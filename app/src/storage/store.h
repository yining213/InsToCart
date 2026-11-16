#pragma once
#include "domain/product.h"
#include "domain/cartline.h"
#include <QString>
#include <QVector>
#include <optional>

class Store {
public:
    bool open(const QString &backend, const QString &dataDirectory);
    QString error() const { return lastError; }
    QString backendName() const { return mode; }
    bool createAccount(const QString &account, const QString &password);
    int authenticate(const QString &account, const QString &password);
    std::optional<QVector<Product>> products();
    bool addToCart(int accountId, int productId, int quantity);
    QVector<CartLine> cart(int accountId);
    bool removeFromCart(int accountId, int productId);
    int placeOrder(int accountId);

private:
    QString mode;
    QString lastError;
    bool runScript(const QString &path);
    bool initialize();
};
