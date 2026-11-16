#pragma once

#include "domain/product.h"
#include <QAbstractListModel>
#include <QSortFilterProxyModel>

class ProductCatalogModel final : public QAbstractListModel {
public:
    enum Role {
        IdRole = Qt::UserRole + 1,
        CategoryRole,
        PriceRole,
        StockRole,
        ImageKeyRole
    };

    using QAbstractListModel::QAbstractListModel;
    int rowCount(const QModelIndex &parent = {}) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void replaceProducts(QVector<Product> products);

private:
    QVector<Product> products;
};

class CatalogSortFilterModel final : public QSortFilterProxyModel {
public:
    enum class Order { ById, PriceAscending, PriceDescending };

    explicit CatalogSortFilterModel(QObject *parent = nullptr);
    void setCriteria(const QString &name, const QString &category, Order order);

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &parent) const override;
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const override;

private:
    QString nameFilter;
    QString categoryFilter;
    Order order = Order::ById;
};

class CatalogPageModel final : public QSortFilterProxyModel {
public:
    static constexpr int PageSize = 8;

    using QSortFilterProxyModel::QSortFilterProxyModel;
    int pageCount() const;
    int currentPage() const { return page; }
    void setPage(int pageNumber);

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &parent) const override;

private:
    int page = 0;
};
