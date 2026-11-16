#pragma once

#include "ui_homepage.h"
#include "catalog/catalogmodel.h"
#include <QMainWindow>
#include <functional>

class QListView;
class QStackedWidget;
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
    ProductCatalogModel catalog;
    CatalogSortFilterModel results;
    CatalogPageModel page;
    QListView *view;
    QStackedWidget *catalogState;
    QWidget *emptyState;
    QWidget *errorState;
    int accountId = -1;
    CatalogSortFilterModel::Order sortOrder = CatalogSortFilterModel::Order::ById;
    bool catalogReady = false;

    void applyCriteria();
    void showPage(int pageNumber);
    void closeCards();
    void addToCart(int productId, int quantity);
    void showDetails(int productId);
    QModelIndex visibleProduct(int productId) const;
};
