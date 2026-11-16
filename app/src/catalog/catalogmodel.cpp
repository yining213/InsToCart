#include "catalogmodel.h"

#include <utility>

int ProductCatalogModel::rowCount(const QModelIndex &parent) const {
    return parent.isValid() ? 0 : products.size();
}

QVariant ProductCatalogModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() ||
        !checkIndex(index, CheckIndexOption::IndexIsValid | CheckIndexOption::ParentIsInvalid))
        return {};

    const Product &product = products.at(index.row());
    switch (role) {
    case Qt::DisplayRole: return product.name;
    case IdRole: return product.id;
    case CategoryRole: return product.category;
    case PriceRole: return product.price;
    case StockRole: return product.stock;
    case ImageKeyRole: return product.imageKey;
    default: return {};
    }
}

void ProductCatalogModel::replaceProducts(QVector<Product> replacement) {
    beginResetModel();
    products = std::move(replacement);
    endResetModel();
}

CatalogSortFilterModel::CatalogSortFilterModel(QObject *parent)
    : QSortFilterProxyModel(parent) {
    sort(0);
}

void CatalogSortFilterModel::setCriteria(const QString &name, const QString &category, Order sortOrder) {
    nameFilter = name.trimmed();
    categoryFilter = category;
    order = sortOrder;
    invalidate();
}

bool CatalogSortFilterModel::filterAcceptsRow(int sourceRow, const QModelIndex &parent) const {
    const QModelIndex index = sourceModel()->index(sourceRow, 0, parent);
    return (categoryFilter.isEmpty() || categoryFilter == "ALL" ||
            index.data(ProductCatalogModel::CategoryRole).toString() == categoryFilter) &&
           index.data().toString().contains(nameFilter, Qt::CaseInsensitive);
}

bool CatalogSortFilterModel::lessThan(const QModelIndex &left, const QModelIndex &right) const {
    if (order != Order::ById) {
        const int leftPrice = left.data(ProductCatalogModel::PriceRole).toInt();
        const int rightPrice = right.data(ProductCatalogModel::PriceRole).toInt();
        if (leftPrice != rightPrice)
            return order == Order::PriceAscending ? leftPrice < rightPrice : leftPrice > rightPrice;
    }

    return left.data(ProductCatalogModel::IdRole).toInt() <
           right.data(ProductCatalogModel::IdRole).toInt();
}

int CatalogPageModel::pageCount() const {
    const int results = sourceModel() ? sourceModel()->rowCount() : 0;
    return (results + PageSize - 1) / PageSize;
}

void CatalogPageModel::setPage(int pageNumber) {
    page = qBound(0, pageNumber, qMax(0, pageCount() - 1));
    // Re-evaluate row positions even if the page number stayed the same.
    invalidateFilter();
}

bool CatalogPageModel::filterAcceptsRow(int sourceRow, const QModelIndex &) const {
    const int firstRow = page * PageSize;
    return sourceRow >= firstRow && sourceRow < firstRow + PageSize;
}
