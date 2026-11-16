#include "catalog/catalogmodel.h"
#include "screens/homewindow.h"
#include "storage/store.h"

#include <QAbstractItemModelTester>
#include <QLabel>
#include <QListView>
#include <QMessageBox>
#include <QPushButton>
#include <QSpinBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QTemporaryDir>
#include <QTest>
#include <QTimer>

namespace {

int idAt(const QAbstractItemModel &model, int row) {
    return model.index(row, 0).data(ProductCatalogModel::IdRole).toInt();
}

void closeDatabase() {
    if (QSqlDatabase::contains())
        QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
}

QWidget *cardFor(HomeWindow &window, int productId) {
    for (auto *card : window.findChildren<QWidget *>("productCard")) {
        if (card->isVisible() && card->property("productId").toInt() == productId)
            return card;
    }
    return nullptr;
}

} // namespace

class CatalogTests final : public QObject {
    Q_OBJECT
private slots:
    void cleanup() { closeDatabase(); }
    void modelFilteringAndPagination();
    void cardActionsFollowProductId();
    void emptyAndFailureStates();
    void orderRollbackAndPersistence();
};

void CatalogTests::modelFilteringAndPagination() {
    ProductCatalogModel catalog;
    CatalogSortFilterModel results;
    CatalogPageModel page;
    results.setSourceModel(&catalog);
    page.setSourceModel(&results);

    using Tester = QAbstractItemModelTester;
    Tester catalogTester(&catalog, Tester::FailureReportingMode::QtTest);
    Tester resultsTester(&results, Tester::FailureReportingMode::QtTest);
    Tester pageTester(&page, Tester::FailureReportingMode::QtTest);
    QVector<Product> products;
    for (int id = 17; id >= 1; --id) {
        products.append({id, id % 2 ? "Canvas bag" : "Desk lamp", id <= 4 ? "CLOTHES" : "HOME LIVING",
                         id == 1 || id == 3 ? 10 : id == 2 ? 2 : 100 + id, 4, "chair.jpg"});
    }
    catalog.replaceProducts(products);
    using Order = CatalogSortFilterModel::Order;
    results.setCriteria("", "ALL", Order::ById);
    QCOMPARE(catalog.rowCount(), 17);
    QCOMPARE(page.pageCount(), 3);
    QCOMPARE(page.rowCount(), 8);
    QCOMPARE(idAt(page, 0), 1);

    page.setPage(1);
    QCOMPARE(page.rowCount(), 8);
    QCOMPARE(idAt(page, 0), 9);
    page.setPage(2);
    QCOMPARE(page.rowCount(), 1);
    QCOMPARE(idAt(page, 0), 17);

    results.setCriteria("cAnVaS", "CLOTHES", Order::PriceDescending);
    page.setPage(0);
    QCOMPARE(page.pageCount(), 1);
    QCOMPARE(page.rowCount(), 2);
    QCOMPARE(idAt(page, 0), 1);
    QCOMPARE(idAt(page, 1), 3);

    results.setCriteria("", "CLOTHES", Order::PriceAscending);
    page.setPage(0);
    QCOMPARE(idAt(page, 0), 2);
    QCOMPARE(idAt(page, 1), 1);
    QCOMPARE(idAt(page, 2), 3);
    results.setCriteria("Desk", "FOOD", Order::ById);
    page.setPage(0);
    QCOMPARE(page.rowCount(), 0);
    QCOMPARE(page.pageCount(), 0);
    QCOMPARE(page.currentPage(), 0);
}

void CatalogTests::cardActionsFollowProductId() {
    QTemporaryDir temp;
    QVERIFY(temp.isValid());
    Store store;
    QVERIFY2(store.open("sqlite", temp.path()), qPrintable(store.error()));
    QVERIFY(store.createAccount("catalog-test@example.com", "catalog-fixture"));
    const int accountId = store.authenticate("catalog-test@example.com", "catalog-fixture");
    QVERIFY(accountId > 0);
    QSqlQuery insert;
    QVERIFY2(insert.exec("INSERT INTO products VALUES (9, 'Travel Apples', 'FOOD', 2, 4, 'apple.jpg')"),
             qPrintable(insert.lastError().text()));

    HomeWindow window(store);
    window.setAccount(accountId);
    window.show();
    QVERIFY(QTest::qWaitForWindowExposed(&window));
    auto *view = window.findChild<QListView *>("catalogView");
    auto *next = window.findChild<QPushButton *>("right_arrow");
    auto *previous = window.findChild<QPushButton *>("left_arrow");
    auto *sort = window.findChild<QPushButton *>("up");
    auto *search = window.findChild<QPushButton *>("search");
    auto *input = window.findChild<QLineEdit *>("search_lineEdit");
    QVERIFY(view && next && previous && sort && search && input);

    QCOMPARE(view->model()->rowCount(), 8);
    QTRY_VERIFY(cardFor(window, 1));
    const QRect firstCard = cardFor(window, 1)->geometry();
    for (int id = 1; id <= 8; ++id) {
        const auto *card = cardFor(window, id);
        QVERIFY(card);
        QVERIFY(view->viewport()->rect().contains(card->geometry()));
        QCOMPARE(card->geometry().y() == firstCard.y(), id <= 4);
        if (id != 1)
            QVERIFY(!firstCard.intersects(card->geometry()));
    }

    QVERIFY(next->isEnabled());
    QVERIFY(!previous->isEnabled());
    QTest::mouseClick(next, Qt::LeftButton);
    QCOMPARE(view->model()->rowCount(), 1);
    QCOMPARE(idAt(*view->model(), 0), 9);
    QVERIFY(previous->isEnabled());
    QVERIFY(!next->isEnabled());
    auto *extra = cardFor(window, 9);
    QVERIFY(extra);
    auto *quantity = extra->findChild<QSpinBox *>("cardQuantity");
    QVERIFY(quantity);
    QCOMPARE(quantity->maximum(), 4);
    quantity->setValue(2);
    QTest::mouseClick(extra->findChild<QPushButton *>("cardAdd"), Qt::LeftButton);
    QCOMPARE(store.cart(accountId).size(), 1);
    QCOMPARE(store.cart(accountId).first().productId, 9);
    QCOMPARE(store.cart(accountId).first().quantity, 2);

    QTest::mouseClick(sort, Qt::LeftButton);
    QVERIFY(!previous->isEnabled());
    QCOMPARE(idAt(*view->model(), 0), 9);
    input->setText("APPLES");
    QTest::mouseClick(search, Qt::LeftButton);
    QCOMPARE(view->model()->rowCount(), 2);
    QCOMPARE(idAt(*view->model(), 1), 1);
    auto *apple = cardFor(window, 1);
    QVERIFY(apple);
    auto *add = apple->findChild<QPushButton *>("cardAdd");
    window.activateWindow();
    input->setFocus();
    QTRY_COMPARE(QApplication::focusWidget(), static_cast<QWidget *>(input));
    for (int attempt = 0; attempt < 32 && QApplication::focusWidget() != add; ++attempt) {
        auto *focused = QApplication::focusWidget();
        QVERIFY(focused);
        QTest::keyClick(focused, Qt::Key_Tab);
    }
    QCOMPARE(QApplication::focusWidget(), static_cast<QWidget *>(add));
    QTest::keyClick(add, Qt::Key_Space);
    const auto cart = store.cart(accountId);
    QCOMPARE(cart.size(), 2);
    QCOMPARE(cart[0].productId, 1);
    QCOMPARE(cart[0].quantity, 1);
    QCOMPARE(cart[1].productId, 9);
    QCOMPARE(cart[1].quantity, 2);

    QString details;
    QTimer::singleShot(0, [&] {
        if (auto *message = qobject_cast<QMessageBox *>(QApplication::activeModalWidget())) {
            details = message->windowTitle() + message->text();
            message->accept();
        }
    });
    QTest::mouseClick(apple->findChild<QPushButton *>("cardDetails"), Qt::LeftButton);
    QVERIFY2(details.contains("Fresh Apples"), qPrintable(details));
    QVERIFY(details.contains("Price: $5"));
}

void CatalogTests::emptyAndFailureStates() {
    QTemporaryDir temp;
    QVERIFY(temp.isValid());
    Store store;
    QVERIFY(store.open("sqlite", temp.path()));
    HomeWindow window(store);
    window.setAccount(1);
    window.show();
    window.findChild<QLineEdit *>("search_lineEdit")->setText("absent");
    QTest::mouseClick(window.findChild<QPushButton *>("search"), Qt::LeftButton);
    QVERIFY(window.findChild<QLabel *>("catalogEmpty")->isVisible());
    QVERIFY(!window.findChild<QPushButton *>("right_arrow")->isEnabled());

    QSqlDatabase::database().close();
    window.refresh();
    QVERIFY(window.findChild<QWidget *>("catalogError")->isVisible());
    QVERIFY(!window.findChild<QLabel *>("catalogEmpty")->isVisible());
    QVERIFY(QSqlDatabase::database().open());
    window.findChild<QLineEdit *>("search_lineEdit")->clear();
    QTest::mouseClick(window.findChild<QPushButton *>("search"), Qt::LeftButton);
    QTest::mouseClick(window.findChild<QPushButton *>("catalogRetry"), Qt::LeftButton);
    QCOMPARE(window.findChild<QListView *>("catalogView")->model()->rowCount(), 8);
}

void CatalogTests::orderRollbackAndPersistence() {
    QTemporaryDir temp;
    QVERIFY(temp.isValid());
    Store store;
    QVERIFY(store.open("sqlite", temp.path()));
    QVERIFY(store.createAccount("order-test@example.com", "order-fixture"));
    const int accountId = store.authenticate("order-test@example.com", "order-fixture");
    QVERIFY(store.addToCart(accountId, 1, 2));
    QVERIFY(store.addToCart(accountId, 8, 2));

    {
        QSqlQuery query;
        QVERIFY(query.exec("UPDATE products SET stock = 1 WHERE id = 8"));

        QCOMPARE(store.placeOrder(accountId), -1);
        QVERIFY(store.error().contains("Insufficient stock"));
        QVERIFY(query.exec("SELECT (SELECT COUNT(*) FROM orders), (SELECT COUNT(*) FROM order_items), "
                           "(SELECT stock FROM products WHERE id = 1)"));
        QVERIFY(query.next());
        QCOMPARE(query.value(0).toInt(), 0);
        QCOMPARE(query.value(1).toInt(), 0);
        QCOMPARE(query.value(2).toInt(), 20);
        QCOMPARE(store.cart(accountId).size(), 2);
        QVERIFY(query.exec("UPDATE products SET stock = 8 WHERE id = 8"));
    }

    const int orderId = store.placeOrder(accountId);
    QVERIFY2(orderId > 0, qPrintable(store.error()));
    closeDatabase();

    Store reopened;
    QVERIFY(reopened.open("sqlite", temp.path()));
    QCOMPARE(reopened.authenticate("order-test@example.com", "order-fixture"), accountId);
    QVERIFY(reopened.cart(accountId).isEmpty());
    QSqlQuery query;
    QVERIFY(query.exec("SELECT o.id, o.total, i.product_id, i.quantity, p.stock "
                       "FROM orders o JOIN order_items i ON o.id = i.order_id "
                       "JOIN products p ON i.product_id = p.id ORDER BY i.product_id"));
    QVERIFY(query.next());
    QCOMPARE(query.value(0).toInt(), orderId);
    QCOMPARE(query.value(1).toInt(), 108);
    QCOMPARE(query.value(2).toInt(), 1);
    QCOMPARE(query.value(3).toInt(), 2);
    QCOMPARE(query.value(4).toInt(), 18);
    QVERIFY(query.next());
    QCOMPARE(query.value(2).toInt(), 8);
    QCOMPARE(query.value(3).toInt(), 2);
    QCOMPARE(query.value(4).toInt(), 6);
    QVERIFY(!query.next());
}

QTEST_MAIN(CatalogTests)
#include "catalogtests.moc"
