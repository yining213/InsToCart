#include "homewindow.h"

#include "cartdialog.h"
#include "catalog/productcarddelegate.h"
#include "storage/store.h"
#include <QIcon>
#include <QListView>
#include <QMessageBox>
#include <QSignalBlocker>
#include <QStackedWidget>
#include <utility>

namespace {
class CatalogView final : public QListView {
public:
    explicit CatalogView(QWidget *parent) : QListView(parent) {
        setObjectName("catalogView");
        setViewMode(QListView::IconMode);
        setMovement(QListView::Static);
        setResizeMode(QListView::Adjust);
        setUniformItemSizes(true);
        setEditTriggers(QAbstractItemView::NoEditTriggers);
        setSelectionMode(QAbstractItemView::NoSelection);
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setFrameShape(QFrame::NoFrame);
        setStyleSheet("QListView { background: transparent; }");
        setGridSize(QSize(248, 245));
    }

protected:
    void resizeEvent(QResizeEvent *event) override {
        QListView::resizeEvent(event);
        const QSize available = viewport()->size();
        setGridSize(QSize(qMax(1, available.width() / 4), qMax(1, available.height() / 2)));
    }
};
}

HomeWindow::HomeWindow(Store &backend) : store(backend) {
    ui.setupUi(this);
    setMinimumSize(1000, 630);
    setWindowTitle("InsToCart — " + store.backendName().toUpper());

    auto *containerLayout = new QVBoxLayout(ui.catalogContainer);
    containerLayout->setContentsMargins(0, 0, 0, 0);
    catalogState = new QStackedWidget(ui.catalogContainer);
    containerLayout->addWidget(catalogState);
    view = new CatalogView(catalogState);
    catalogState->addWidget(view);
    emptyState = new QLabel("No matching products.", catalogState);
    emptyState->setObjectName("catalogEmpty");
    static_cast<QLabel *>(emptyState)->setAlignment(Qt::AlignCenter);
    catalogState->addWidget(emptyState);

    errorState = new QWidget(catalogState);
    errorState->setObjectName("catalogError");
    auto *errorLayout = new QVBoxLayout(errorState);
    auto *errorLabel = new QLabel("Could not load products.", errorState);
    errorLabel->setAlignment(Qt::AlignCenter);
    auto *retry = new QPushButton("Retry", errorState);
    retry->setObjectName("catalogRetry");
    errorLayout->addStretch();
    errorLayout->addWidget(errorLabel);
    errorLayout->addWidget(retry, 0, Qt::AlignHCenter);
    errorLayout->addStretch();
    catalogState->addWidget(errorState);
    connect(retry, &QPushButton::clicked, this, &HomeWindow::refresh);

    results.setSourceModel(&catalog);
    page.setSourceModel(&results);
    view->setModel(&page);
    auto *delegate = new ProductCardDelegate(view);
    view->setItemDelegate(delegate);
    connect(delegate, &ProductCardDelegate::addRequested, this, &HomeWindow::addToCart);
    connect(delegate, &ProductCardDelegate::detailsRequested, this, &HomeWindow::showDetails);

    ui.search->setIcon(QIcon(":/icons/search2.png"));
    ui.left_arrow->setIcon(QIcon(":/icons/left.png"));
    ui.right_arrow->setIcon(QIcon(":/icons/right.png"));
    ui.up->setIcon(QIcon(":/icons/up.png"));
    ui.down->setIcon(QIcon(":/icons/down.png"));
    ui.settings->setStyleSheet("image: url(:/person.png);");
    ui.search->setAccessibleName("Search products");
    ui.left_arrow->setAccessibleName("Previous product page");
    ui.right_arrow->setAccessibleName("Next product page");
    ui.up->setAccessibleName("Sort by lowest price");
    ui.down->setAccessibleName("Sort by highest price");
    ui.cart->setAccessibleName("Open cart");
    ui.settings->setAccessibleName("Log out");

    connect(ui.search, &QPushButton::clicked, this, &HomeWindow::applyCriteria);
    connect(ui.search_lineEdit, &QLineEdit::returnPressed, this, &HomeWindow::applyCriteria);
    connect(ui.search_comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, [this] { applyCriteria(); });
    connect(ui.left_arrow, &QPushButton::clicked, this, [this] { showPage(page.currentPage() - 1); });
    connect(ui.right_arrow, &QPushButton::clicked, this, [this] { showPage(page.currentPage() + 1); });
    connect(ui.up, &QPushButton::clicked, this, [this] {
        sortOrder = CatalogSortFilterModel::Order::PriceAscending;
        applyCriteria();
    });
    connect(ui.down, &QPushButton::clicked, this, [this] {
        sortOrder = CatalogSortFilterModel::Order::PriceDescending;
        applyCriteria();
    });
    connect(ui.cart, &QPushButton::clicked, this, [this] {
        showCartDialog(this, store, accountId);
        refresh();
    });
    connect(ui.settings, &QPushButton::clicked, this, [this] { if (logout) logout(); });
    ui.settings->setToolTip("Log out");
    connect(ui.message, &QPushButton::clicked, this, [this] {
        QMessageBox::information(this, "Messaging", "Messaging is not included in this desktop demo.");
    });
    showPage(0);
}

void HomeWindow::setAccount(int id) {
    accountId = id;
    ui.search_lineEdit->clear();
    const QSignalBlocker waitForReload(ui.search_comboBox);
    ui.search_comboBox->setCurrentIndex(0);
    sortOrder = CatalogSortFilterModel::Order::ById;
    refresh();
}

void HomeWindow::refresh() {
    auto products = store.products();
    catalogReady = products.has_value();
    closeCards();
    catalog.replaceProducts(products ? std::move(*products) : QVector<Product>());
    applyCriteria();
}

void HomeWindow::applyCriteria() {
    closeCards();
    results.setCriteria(ui.search_lineEdit->text(), ui.search_comboBox->currentText(), sortOrder);
    showPage(0);
}

void HomeWindow::closeCards() {
    for (int row = 0; row < page.rowCount(); ++row)
        view->closePersistentEditor(page.index(row, 0));
}

void HomeWindow::showPage(int pageNumber) {
    closeCards();
    page.setPage(pageNumber);
    ui.left_arrow->setEnabled(catalogReady && page.currentPage() > 0);
    ui.right_arrow->setEnabled(catalogReady && page.currentPage() + 1 < page.pageCount());

    if (!catalogReady) {
        catalogState->setCurrentWidget(errorState);
        return;
    }
    if (page.rowCount() == 0) {
        catalogState->setCurrentWidget(emptyState);
        return;
    }

    catalogState->setCurrentWidget(view);
    for (int row = 0; row < page.rowCount(); ++row)
        view->openPersistentEditor(page.index(row, 0));
}

QModelIndex HomeWindow::visibleProduct(int productId) const {
    for (int row = 0; row < page.rowCount(); ++row) {
        const QModelIndex index = page.index(row, 0);
        if (index.data(ProductCatalogModel::IdRole).toInt() == productId)
            return index;
    }
    return {};
}

void HomeWindow::addToCart(int productId, int quantity) {
    const QModelIndex product = visibleProduct(productId);
    if (!product.isValid() || accountId < 0)
        return;
    if (!store.addToCart(accountId, productId, quantity))
        QMessageBox::warning(this, "Cart", store.error());
    else
        statusBar()->showMessage(product.data().toString() + " added to cart", 2500);
}

void HomeWindow::showDetails(int productId) {
    const QModelIndex product = visibleProduct(productId);
    if (!product.isValid())
        return;
    QMessageBox details(QMessageBox::Information, "Product details", {}, QMessageBox::Ok, this);
    details.setTextFormat(Qt::PlainText);
    details.setText(product.data().toString() + "\n" +
                    product.data(ProductCatalogModel::CategoryRole).toString() + "\nPrice: $" +
                    product.data(ProductCatalogModel::PriceRole).toString() + "\nAvailable: " +
                    product.data(ProductCatalogModel::StockRole).toString());
    details.exec();
}
