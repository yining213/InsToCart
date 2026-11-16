#include "homewindow.h"
#include "cartdialog.h"
#include "storage/store.h"
#include <QComboBox>
#include <QDoubleSpinBox>
#include <QFrame>
#include <QIcon>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPixmap>
#include <QPushButton>
#include <QStatusBar>

HomeWindow::HomeWindow(Store &backend) : store(backend) {
    ui.setupUi(this);
    setWindowTitle("InsToCart — " + store.backendName().toUpper());
    frames = {ui.frame_0, ui.frame_1, ui.frame_4, ui.frame_5,
              ui.frame_6, ui.frame_7, ui.frame_8, ui.frame_9};
    names = {ui.label_0_name, ui.label_1_name, ui.label_2_name, ui.label_3_name,
             ui.label_4_name, ui.label_5_name, ui.label_6_name, ui.label_7_name};
    prices = {ui.label_0_price, ui.label_1_price, ui.label_2_price, ui.label_3_price,
              ui.label_4_price, ui.label_5_price, ui.label_6_price, ui.label_7_price};
    pictures = {ui.label_0_img, ui.label_1_img, ui.label_2_img, ui.label_3_img,
                ui.label_4_img, ui.label_5_img, ui.label_6_img, ui.label_7_img};
    quantities = {ui.doubleSpinBox_0, ui.doubleSpinBox_1, ui.doubleSpinBox_2,
                  ui.doubleSpinBox_3, ui.doubleSpinBox_4, ui.doubleSpinBox_5,
                  ui.doubleSpinBox_6, ui.doubleSpinBox_7};
    addButtons = {ui.plus_0, ui.plus_1, ui.plus_2, ui.plus_3,
                  ui.plus_4, ui.plus_5, ui.plus_6, ui.plus_7};
    detailButtons = {ui.pushButton_back_0, ui.pushButton_back_1,
                     ui.pushButton_2_back, ui.pushButton_3_back,
                     ui.pushButton_4_back, ui.pushButton_5_back,
                     ui.pushButton_6_back, ui.pushButton_7_back};
    ui.search->setIcon(QIcon(":/icons/search2.png"));
    ui.left_arrow->setIcon(QIcon(":/icons/left.png"));
    ui.right_arrow->setIcon(QIcon(":/icons/right.png"));
    ui.up->setIcon(QIcon(":/icons/up.png"));
    ui.down->setIcon(QIcon(":/icons/down.png"));
    ui.settings->setStyleSheet("image: url(:/person.png);");
    for (int slot = 0; slot < 8; ++slot) {
        addButtons[slot]->setIcon(QIcon(":/icons/plus.png"));
        connect(addButtons[slot], &QPushButton::clicked, this, [this, slot] { addToCart(slot); });
        connect(detailButtons[slot], &QPushButton::clicked, this, [this, slot] { showDetails(slot); });
    }
    connect(ui.search, &QPushButton::clicked, this, [this] { refresh(); });
    connect(ui.search_lineEdit, &QLineEdit::returnPressed, this, [this] { refresh(); });
    connect(ui.search_comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, [this] { refresh(); });
    connect(ui.left_arrow, &QPushButton::clicked, this, [this] {
        if (page > 0) { --page; render(); }
    });
    connect(ui.right_arrow, &QPushButton::clicked, this, [this] {
        if ((page + 1) * 8 < products.size()) { ++page; render(); }
    });
    connect(ui.up, &QPushButton::clicked, this, [this] { sortMode = 1; refresh(); });
    connect(ui.down, &QPushButton::clicked, this, [this] { sortMode = 2; refresh(); });
    connect(ui.cart, &QPushButton::clicked, this, [this] {
        showCartDialog(this, store, accountId);
        refresh();
    });
    connect(ui.settings, &QPushButton::clicked, this, [this] { if (logout) logout(); });
    ui.settings->setToolTip("Log out");
    connect(ui.message, &QPushButton::clicked, this, [this] {
        QMessageBox::information(this, "Messaging", "Messaging is not included in this desktop demo.");
    });
}

void HomeWindow::setAccount(int id) {
    accountId = id;
    ui.search_lineEdit->clear();
    ui.search_comboBox->setCurrentIndex(0);
    sortMode = 0;
    refresh();
}

void HomeWindow::refresh() {
    products = store.products(ui.search_lineEdit->text(), ui.search_comboBox->currentText(), sortMode);
    page = 0;
    render();
}

void HomeWindow::render() {
    for (int slot = 0; slot < 8; ++slot) {
        const int index = page * 8 + slot;
        const bool visible = index < products.size();
        frames[slot]->setVisible(visible);
        if (!visible) continue;
        const Product &product = products[index];
        names[slot]->setText(product.name);
        prices[slot]->setText("$" + QString::number(product.price));
        pictures[slot]->setPixmap(QPixmap(":/products/" + product.imageKey).scaled(
            pictures[slot]->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        pictures[slot]->setAlignment(Qt::AlignCenter);
        quantities[slot]->setDecimals(0);
        quantities[slot]->setMinimum(1);
        quantities[slot]->setMaximum(product.stock);
        quantities[slot]->setValue(1);
    }
    ui.left_arrow->setEnabled(page > 0);
    ui.right_arrow->setEnabled((page + 1) * 8 < products.size());
}

void HomeWindow::addToCart(int slot) {
    const int index = page * 8 + slot;
    if (index >= products.size() || accountId < 0) return;
    const Product &product = products[index];
    if (!store.addToCart(accountId, product.id, static_cast<int>(quantities[slot]->value())))
        QMessageBox::warning(this, "Cart", store.error());
    else statusBar()->showMessage(product.name + " added to cart", 2500);
}

void HomeWindow::showDetails(int slot) {
    const int index = page * 8 + slot;
    if (index >= products.size()) return;
    const Product &p = products[index];
    QMessageBox::information(this, p.name, p.category + "\nPrice: $" +
        QString::number(p.price) + "\nAvailable: " + QString::number(p.stock));
}
