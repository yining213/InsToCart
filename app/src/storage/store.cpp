#include "store.h"
#include "sqlite/sqlitebackend.h"
#include "mysql/mysqlbackend.h"
#include <QCryptographicHash>
#include <QFile>
#include <QPasswordDigestor>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QUuid>
#include <QVariant>

namespace {
QString digest(const QString &salt, const QString &password) {
    return QString::fromLatin1(QPasswordDigestor::deriveKeyPbkdf2(
        QCryptographicHash::Sha256, password.toUtf8(), QByteArray::fromHex(salt.toLatin1()),
        100000, 32).toHex());
}
QString normalized(const QString &account) { return account.trimmed().toLower(); }
}

bool Store::open(const QString &backend, const QString &dataDirectory) {
    mode = backend.toLower();
    if (mode != "sqlite" && mode != "mysql") {
        lastError = "Unknown storage mode: " + backend;
        return false;
    }
    if (!(mode == "sqlite" ? SQLiteBackend::open(dataDirectory, &lastError)
                            : MySQLBackend::open(&lastError))) return false;
    return initialize();
}

bool Store::runScript(const QString &path) {
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        lastError = "Cannot read SQL resource: " + path;
        return false;
    }
    const QStringList statements = QString::fromUtf8(file.readAll()).split(';');
    for (const QString &statement : statements) {
        if (statement.trimmed().isEmpty()) continue;
        QSqlQuery query;
        if (!query.exec(statement.trimmed())) {
            lastError = query.lastError().text();
            return false;
        }
    }
    return true;
}

bool Store::initialize() {
    const QString root = ":/sql/" + mode;
    if (!runScript(root + "/schema.sql")) return false;
    QSqlQuery count;
    if (!count.exec("SELECT COUNT(*) FROM products") || !count.next()) {
        lastError = count.lastError().text();
        return false;
    }
    if (count.value(0).toInt() == 0 && !runScript(root + "/seed.sql")) return false;
    return true;
}

bool Store::createAccount(const QString &account, const QString &password) {
    if (normalized(account).isEmpty() || password.size() < 8) {
        lastError = "Enter an account and a password of at least eight characters.";
        return false;
    }
    const QString salt = QUuid::createUuid().toString(QUuid::WithoutBraces).remove('-');
    QSqlQuery query;
    query.prepare("INSERT INTO accounts (account, salt, password_hash) VALUES (?, ?, ?)");
    query.addBindValue(normalized(account));
    query.addBindValue(salt);
    query.addBindValue(digest(salt, password));
    if (!query.exec()) { lastError = query.lastError().text(); return false; }
    return true;
}

int Store::authenticate(const QString &account, const QString &password) {
    QSqlQuery query;
    query.prepare("SELECT id, salt, password_hash FROM accounts WHERE account = ?");
    query.addBindValue(normalized(account));
    if (!query.exec()) { lastError = query.lastError().text(); return -1; }
    if (!query.next()) return -1;
    return digest(query.value(1).toString(), password) == query.value(2).toString()
               ? query.value(0).toInt() : -1;
}

std::optional<QVector<Product>> Store::products() {
    QSqlQuery query;
    if (!query.exec("SELECT id, name, category, price, stock, image_key FROM products "
                    "WHERE stock > 0 ORDER BY id")) {
        lastError = query.lastError().text();
        return std::nullopt;
    }

    QVector<Product> result;
    while (query.next()) {
        result.append({query.value(0).toInt(), query.value(1).toString(),
                       query.value(2).toString(), query.value(3).toInt(),
                       query.value(4).toInt(), query.value(5).toString()});
    }
    if (query.lastError().isValid()) {
        lastError = query.lastError().text();
        return std::nullopt;
    }
    return result;
}

bool Store::addToCart(int accountId, int productId, int quantity) {
    if (accountId < 1 || quantity < 1) { lastError = "Invalid cart item."; return false; }
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.transaction()) { lastError = db.lastError().text(); return false; }
    QSqlQuery stock;
    stock.prepare("SELECT stock FROM products WHERE id = ?");
    stock.addBindValue(productId);
    if (!stock.exec() || !stock.next()) {
        lastError = stock.lastError().text(); db.rollback(); return false;
    }
    const int available = stock.value(0).toInt();
    QSqlQuery current;
    current.prepare("SELECT quantity FROM cart WHERE account_id = ? AND product_id = ?");
    current.addBindValue(accountId);
    current.addBindValue(productId);
    if (!current.exec()) { lastError = current.lastError().text(); db.rollback(); return false; }
    const bool exists = current.next();
    const int newQuantity = quantity + (exists ? current.value(0).toInt() : 0);
    if (newQuantity > available) {
        lastError = "Only " + QString::number(available) + " items are available.";
        db.rollback(); return false;
    }
    QSqlQuery write;
    write.prepare(exists ? "UPDATE cart SET quantity = ? WHERE account_id = ? AND product_id = ?"
                         : "INSERT INTO cart (quantity, account_id, product_id) VALUES (?, ?, ?)");
    write.addBindValue(newQuantity);
    write.addBindValue(accountId);
    write.addBindValue(productId);
    if (!write.exec()) { lastError = write.lastError().text(); db.rollback(); return false; }
    if (!db.commit()) { lastError = db.lastError().text(); db.rollback(); return false; }
    return true;
}

QVector<CartLine> Store::cart(int accountId) {
    QVector<CartLine> result;
    QSqlQuery query;
    query.prepare("SELECT p.id, p.name, c.quantity, p.price FROM cart c "
                  "JOIN products p ON p.id = c.product_id WHERE c.account_id = ? ORDER BY p.name");
    query.addBindValue(accountId);
    if (!query.exec()) { lastError = query.lastError().text(); return result; }
    while (query.next()) result.append({query.value(0).toInt(), query.value(1).toString(),
                                        query.value(2).toInt(), query.value(3).toInt()});
    return result;
}

bool Store::removeFromCart(int accountId, int productId) {
    QSqlQuery query;
    query.prepare("DELETE FROM cart WHERE account_id = ? AND product_id = ?");
    query.addBindValue(accountId);
    query.addBindValue(productId);
    if (!query.exec()) { lastError = query.lastError().text(); return false; }
    return true;
}

int Store::placeOrder(int accountId) {
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.transaction()) { lastError = db.lastError().text(); return -1; }
    const QVector<CartLine> lines = cart(accountId);
    if (lines.isEmpty()) { lastError = "Cart is empty."; db.rollback(); return -1; }
    int total = 0;
    for (const CartLine &line : lines) total += line.quantity * line.unitPrice;
    QSqlQuery order;
    order.prepare("INSERT INTO orders (account_id, total) VALUES (?, ?)");
    order.addBindValue(accountId);
    order.addBindValue(total);
    if (!order.exec()) { lastError = order.lastError().text(); db.rollback(); return -1; }
    const int orderId = order.lastInsertId().toInt();
    for (const CartLine &line : lines) {
        QSqlQuery stock;
        stock.prepare("UPDATE products SET stock = stock - ? WHERE id = ? AND stock >= ?");
        stock.addBindValue(line.quantity);
        stock.addBindValue(line.productId);
        stock.addBindValue(line.quantity);
        if (!stock.exec() || stock.numRowsAffected() != 1) {
            lastError = stock.lastError().text().isEmpty() ? "Insufficient stock." : stock.lastError().text();
            db.rollback(); return -1;
        }
        QSqlQuery item;
        item.prepare("INSERT INTO order_items (order_id, product_id, quantity, unit_price) VALUES (?, ?, ?, ?)");
        item.addBindValue(orderId);
        item.addBindValue(line.productId);
        item.addBindValue(line.quantity);
        item.addBindValue(line.unitPrice);
        if (!item.exec()) { lastError = item.lastError().text(); db.rollback(); return -1; }
    }
    QSqlQuery clear;
    clear.prepare("DELETE FROM cart WHERE account_id = ?");
    clear.addBindValue(accountId);
    if (!clear.exec()) { lastError = clear.lastError().text(); db.rollback(); return -1; }
    if (!db.commit()) { lastError = db.lastError().text(); db.rollback(); return -1; }
    return orderId;
}
