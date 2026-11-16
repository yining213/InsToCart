#include "productcarddelegate.h"

#include "catalogmodel.h"
#include <QFrame>
#include <QHBoxLayout>
#include <QIcon>
#include <QLabel>
#include <QListView>
#include <QPixmap>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>

namespace {
class ProductCard final : public QFrame {
    Q_OBJECT
public:
    explicit ProductCard(QWidget *parent) : QFrame(parent) {
        setObjectName("productCard");
        setStyleSheet(
            "QFrame#productCard { background: white; border-radius: 16px; }"
            "QLabel, QPushButton { background: transparent; color: #222; }"
            "QPushButton#cardDetails { border: 1px solid #333; border-radius: 8px; padding: 3px 10px; }"
            "QPushButton:focus, QSpinBox:focus { border: 2px solid #88630a; }"
            "QSpinBox { color: #222; background: #fff; border: 1px solid #b8b8b8;"
            "  border-radius: 4px; padding: 2px 16px 2px 5px; }"
            "QSpinBox::up-button, QSpinBox::down-button { width: 14px; background: #eee; }"
            "QSpinBox::up-button { subcontrol-position: top right; }"
            "QSpinBox::down-button { subcontrol-position: bottom right; }"
            "QSpinBox::up-arrow { image: url(:/icons/up.png); width: 7px; height: 7px; }"
            "QSpinBox::down-arrow { image: url(:/icons/down.png); width: 7px; height: 7px; }");

        auto *layout = new QVBoxLayout(this);
        layout->setContentsMargins(14, 10, 14, 12);
        layout->setSpacing(5);
        auto *heading = new QHBoxLayout;
        auto *add = new QPushButton(QIcon(":/icons/plus.png"), QString(), this);
        add->setObjectName("cardAdd");
        add->setFixedSize(30, 28);
        add->setFlat(true);
        add->setFocusPolicy(Qt::StrongFocus);
        heading->addSpacing(add->width());
        heading->addWidget(&name, 1);
        heading->addWidget(add);
        name.setAlignment(Qt::AlignCenter);
        name.setTextFormat(Qt::PlainText);
        name.setWordWrap(true);
        name.setMinimumHeight(30);
        layout->addLayout(heading);

        auto *orderRow = new QHBoxLayout;
        quantity.setObjectName("cardQuantity");
        quantity.setMinimum(1);
        quantity.setMinimumWidth(60);
        price.setAlignment(Qt::AlignCenter);
        orderRow->addWidget(&quantity);
        orderRow->addWidget(&price, 1);
        layout->addLayout(orderRow);

        picture.setAlignment(Qt::AlignCenter);
        layout->addWidget(&picture, 1);
        auto *details = new QPushButton("DETAILS", this);
        details->setObjectName("cardDetails");
        details->setFocusPolicy(Qt::StrongFocus);
        layout->addWidget(details, 0, Qt::AlignHCenter);

        connect(add, &QPushButton::clicked, this, [this] { emit addRequested(productId, quantity.value()); });
        connect(details, &QPushButton::clicked, this, [this] { emit detailsRequested(productId); });
    }

    void bind(const QModelIndex &index) {
        const QString productName = index.data().toString();
        const int id = index.data(ProductCatalogModel::IdRole).toInt();
        const bool changedProduct = productId != id;
        productId = id;
        setProperty("productId", id);
        name.setText(productName);
        price.setText("$" + QString::number(index.data(ProductCatalogModel::PriceRole).toInt()));
        quantity.setMaximum(index.data(ProductCatalogModel::StockRole).toInt());
        if (changedProduct)
            quantity.setValue(1);
        quantity.setAccessibleName("Quantity for " + productName);
        auto *add = findChild<QPushButton *>("cardAdd");
        add->setAccessibleName("Add " + productName + " to cart");
        add->setToolTip(add->accessibleName());
        findChild<QPushButton *>("cardDetails")->setAccessibleName("Details for " + productName);

        const QPixmap photo(":/products/" + index.data(ProductCatalogModel::ImageKeyRole).toString());
        picture.setPixmap(photo.scaled(176, 108, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }

signals:
    void addRequested(int productId, int quantity);
    void detailsRequested(int productId);

private:
    int productId = -1;
    QLabel name, price, picture;
    QSpinBox quantity;
};
}

QWidget *ProductCardDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &,
                                           const QModelIndex &) const {
    auto *card = new ProductCard(parent);
    connect(card, &ProductCard::addRequested, this, &ProductCardDelegate::addRequested);
    connect(card, &ProductCard::detailsRequested, this, &ProductCardDelegate::detailsRequested);
    return card;
}

void ProductCardDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const {
    static_cast<ProductCard *>(editor)->bind(index);
}

void ProductCardDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                                                const QModelIndex &) const {
    editor->setGeometry(option.rect.adjusted(7, 7, -7, -7));
}

QSize ProductCardDelegate::sizeHint(const QStyleOptionViewItem &, const QModelIndex &) const {
    return static_cast<const QListView *>(parent())->gridSize();
}

#include "productcarddelegate.moc"
