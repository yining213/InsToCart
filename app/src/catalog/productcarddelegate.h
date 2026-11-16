#pragma once

#include <QStyledItemDelegate>

class ProductCardDelegate final : public QStyledItemDelegate {
    Q_OBJECT
public:
    using QStyledItemDelegate::QStyledItemDelegate;
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *, QAbstractItemModel *, const QModelIndex &) const override {}
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                              const QModelIndex &index) const override;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void paint(QPainter *, const QStyleOptionViewItem &, const QModelIndex &) const override {}

signals:
    void addRequested(int productId, int quantity);
    void detailsRequested(int productId);
};
