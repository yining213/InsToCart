/********************************************************************************
** Form generated from reading UI file 'orderINFO.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERINFO_H
#define UI_ORDERINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_orderINFO
{
public:
    QLabel *label;
    QTableWidget *table;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_total;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_SF;
    QLabel *label_7;
    QLabel *label_subtotal;
    QLabel *lineEdit;

    void setupUi(QWidget *orderINFO)
    {
        if (orderINFO->objectName().isEmpty())
            orderINFO->setObjectName(QString::fromUtf8("orderINFO"));
        orderINFO->resize(900, 400);
        orderINFO->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: \"Consolas\";\n"
"color: rgb(0, 0, 0);"));
        label = new QLabel(orderINFO);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 40, 301, 41));
        label->setStyleSheet(QString::fromUtf8("font: 75 20pt \"Consolas\";"));
        label->setAlignment(Qt::AlignCenter);
        table = new QTableWidget(orderINFO);
        table->setObjectName(QString::fromUtf8("table"));
        table->setGeometry(QRect(20, 130, 471, 211));
        table->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 12pt \"Consolas\";\n"
""));
        label_4 = new QLabel(orderINFO);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(560, 200, 271, 41));
        label_4->setStyleSheet(QString::fromUtf8("font: 20pt \"Consolas\";"));
        label_4->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(orderINFO);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(560, 40, 271, 41));
        label_2->setStyleSheet(QString::fromUtf8("font: 20pt \"Consolas\";"));
        label_2->setAlignment(Qt::AlignCenter);
        label_total = new QLabel(orderINFO);
        label_total->setObjectName(QString::fromUtf8("label_total"));
        label_total->setGeometry(QRect(780, 340, 91, 21));
        label_total->setStyleSheet(QString::fromUtf8("font: 75 14pt \"Consolas\";"));
        label_total->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(orderINFO);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(530, 100, 91, 21));
        label_3->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Consolas\";"));
        label_5 = new QLabel(orderINFO);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(530, 260, 211, 21));
        label_5->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Consolas\";"));
        label_6 = new QLabel(orderINFO);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(530, 340, 211, 21));
        label_6->setStyleSheet(QString::fromUtf8("font: 75 14pt \"Consolas\";"));
        label_SF = new QLabel(orderINFO);
        label_SF->setObjectName(QString::fromUtf8("label_SF"));
        label_SF->setGeometry(QRect(780, 300, 91, 21));
        label_SF->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Consolas\";"));
        label_SF->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_7 = new QLabel(orderINFO);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(530, 300, 211, 21));
        label_7->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Consolas\";"));
        label_subtotal = new QLabel(orderINFO);
        label_subtotal->setObjectName(QString::fromUtf8("label_subtotal"));
        label_subtotal->setGeometry(QRect(780, 260, 91, 21));
        label_subtotal->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Consolas\";"));
        label_subtotal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit = new QLabel(orderINFO);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(530, 130, 361, 41));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"font: 10pt \"Consolas\";\n"
"padding-left: 10px;\n"
"border-color: rgba(255, 255, 255, 0);"));

        retranslateUi(orderINFO);

        QMetaObject::connectSlotsByName(orderINFO);
    } // setupUi

    void retranslateUi(QWidget *orderINFO)
    {
        orderINFO->setWindowTitle(QCoreApplication::translate("orderINFO", "Form", nullptr));
        label->setText(QCoreApplication::translate("orderINFO", "PRODUCT DETAILS", nullptr));
        label_4->setText(QCoreApplication::translate("orderINFO", "Payment Details", nullptr));
        label_2->setText(QCoreApplication::translate("orderINFO", "ORDER DETAILS", nullptr));
        label_total->setText(QCoreApplication::translate("orderINFO", "SF", nullptr));
        label_3->setText(QCoreApplication::translate("orderINFO", "Shipping", nullptr));
        label_5->setText(QCoreApplication::translate("orderINFO", "Merchandise subtotal", nullptr));
        label_6->setText(QCoreApplication::translate("orderINFO", "Total payment", nullptr));
        label_SF->setText(QCoreApplication::translate("orderINFO", "SF", nullptr));
        label_7->setText(QCoreApplication::translate("orderINFO", "Shipping subtotal", nullptr));
        label_subtotal->setText(QCoreApplication::translate("orderINFO", "price", nullptr));
        lineEdit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class orderINFO: public Ui_orderINFO {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERINFO_H
