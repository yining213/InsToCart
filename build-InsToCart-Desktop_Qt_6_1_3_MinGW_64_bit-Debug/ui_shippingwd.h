/********************************************************************************
** Form generated from reading UI file 'shippingwd.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHIPPINGWD_H
#define UI_SHIPPINGWD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_shippingWD
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QTableWidget *table;

    void setupUi(QDialog *shippingWD)
    {
        if (shippingWD->objectName().isEmpty())
            shippingWD->setObjectName(QString::fromUtf8("shippingWD"));
        shippingWD->resize(624, 396);
        shippingWD->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEdit = new QLineEdit(shippingWD);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(270, 40, 161, 31));
        lineEdit->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 12pt \"Consolas\";"));
        label = new QLabel(shippingWD);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 40, 81, 31));
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 12pt \"Consolas\";"));
        table = new QTableWidget(shippingWD);
        table->setObjectName(QString::fromUtf8("table"));
        table->setGeometry(QRect(50, 100, 521, 251));
        table->setStyleSheet(QString::fromUtf8("font: 12pt \"Consolas\";\n"
"color: rgb(0, 0, 0);"));

        retranslateUi(shippingWD);

        QMetaObject::connectSlotsByName(shippingWD);
    } // setupUi

    void retranslateUi(QDialog *shippingWD)
    {
        shippingWD->setWindowTitle(QCoreApplication::translate("shippingWD", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("shippingWD", "Order ID", nullptr));
    } // retranslateUi

};

namespace Ui {
    class shippingWD: public Ui_shippingWD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHIPPINGWD_H
