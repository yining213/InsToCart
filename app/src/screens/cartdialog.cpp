#include "cartdialog.h"
#include "storage/store.h"
#include <QDialog>
#include <QLabel>
#include <QListWidget>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>

void showCartDialog(QWidget *parent, Store &store, int accountId) {
    QDialog dialog(parent);
    dialog.setWindowTitle("Your cart");
    dialog.resize(440, 380);
    auto *layout = new QVBoxLayout(&dialog);
    auto *list = new QListWidget;
    auto *total = new QLabel;
    auto *remove = new QPushButton("Remove selected item");
    auto *place = new QPushButton("Place order");
    layout->addWidget(list);
    layout->addWidget(total);
    layout->addWidget(remove);
    layout->addWidget(place);
    auto reload = [&] {
        list->clear();
        int sum = 0;
        for (const CartLine &line : store.cart(accountId)) {
            const int subtotal = line.quantity * line.unitPrice;
            auto *row = new QListWidgetItem(line.name + " × " + QString::number(line.quantity) +
                " — $" + QString::number(subtotal), list);
            row->setData(Qt::UserRole, line.productId);
            sum += subtotal;
        }
        total->setText("Total: $" + QString::number(sum));
    };
    QObject::connect(remove, &QPushButton::clicked, &dialog, [&] {
        if (!list->currentItem()) return;
        if (!store.removeFromCart(accountId, list->currentItem()->data(Qt::UserRole).toInt()))
            QMessageBox::warning(&dialog, "Cart", store.error());
        reload();
    });
    QObject::connect(place, &QPushButton::clicked, &dialog, [&] {
        if (list->count() == 0) return;
        const int orderId = store.placeOrder(accountId);
        if (orderId < 0) { QMessageBox::warning(&dialog, "Order", store.error()); return; }
        reload();
        QMessageBox::information(&dialog, "Order placed", "Order #" + QString::number(orderId) + " saved.");
    });
    reload();
    dialog.exec();
}
