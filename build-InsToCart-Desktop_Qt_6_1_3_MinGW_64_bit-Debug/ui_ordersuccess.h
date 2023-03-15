/********************************************************************************
** Form generated from reading UI file 'ordersuccess.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERSUCCESS_H
#define UI_ORDERSUCCESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_orderSuccess
{
public:
    QLabel *label;

    void setupUi(QWidget *orderSuccess)
    {
        if (orderSuccess->objectName().isEmpty())
            orderSuccess->setObjectName(QString::fromUtf8("orderSuccess"));
        orderSuccess->resize(400, 124);
        orderSuccess->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label = new QLabel(orderSuccess);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 361, 61));
        label->setStyleSheet(QString::fromUtf8("font: 75 16pt \"Consolas\";\n"
"color: rgb(0, 0, 0);"));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(orderSuccess);

        QMetaObject::connectSlotsByName(orderSuccess);
    } // setupUi

    void retranslateUi(QWidget *orderSuccess)
    {
        orderSuccess->setWindowTitle(QCoreApplication::translate("orderSuccess", "Form", nullptr));
        label->setText(QCoreApplication::translate("orderSuccess", "Your order was successful!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class orderSuccess: public Ui_orderSuccess {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERSUCCESS_H
