#pragma once
#include "ui_homepage.h"
#include "domain/product.h"
#include <QMainWindow>
#include <QVector>
#include <functional>
class Store;

class HomeWindow : public QMainWindow {
public:
    explicit HomeWindow(Store &store);
    void setAccount(int id);
    void refresh();
    std::function<void()> logout;

private:
    Ui::HomePage ui;
    Store &store;
    int accountId = -1;
    int page = 0;
    int sortMode = 0;
    QVector<Product> products;
    QVector<QFrame*> frames;
    QVector<QLabel*> names, prices, pictures;
    QVector<QDoubleSpinBox*> quantities;
    QVector<QPushButton*> addButtons, detailButtons;
    void render();
    void addToCart(int slot);
    void showDetails(int slot);
};
