/********************************************************************************
** Form generated from reading UI file 'myorderdetail.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYORDERDETAIL_H
#define UI_MYORDERDETAIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyOrderDetail
{
public:
    QLabel *label;
    QLabel *label_3;
    QTextBrowser *address;
    QLabel *label_4;
    QLabel *label_8;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *m_price;
    QLabel *ship_price;
    QLabel *label_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QLabel *label_7;
    QTableWidget *tableWidget;
    QLabel *total_price;

    void setupUi(QDialog *MyOrderDetail)
    {
        if (MyOrderDetail->objectName().isEmpty())
            MyOrderDetail->setObjectName(QString::fromUtf8("MyOrderDetail"));
        MyOrderDetail->resize(900, 400);
        MyOrderDetail->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label = new QLabel(MyOrderDetail);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 20, 241, 41));
        label->setStyleSheet(QString::fromUtf8("font: 20pt \"Consolas\";\n"
""));
        label_3 = new QLabel(MyOrderDetail);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(450, 60, 261, 41));
        label_3->setStyleSheet(QString::fromUtf8("font: 15pt \"Consolas\";\n"
""));
        address = new QTextBrowser(MyOrderDetail);
        address->setObjectName(QString::fromUtf8("address"));
        address->setGeometry(QRect(450, 100, 311, 61));
        address->setLayoutDirection(Qt::RightToLeft);
        address->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"border-radius:  13px; \n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"font: 10pt \"Consolas\";\n"
"padding-left: 10px;"));
        label_4 = new QLabel(MyOrderDetail);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(490, 180, 261, 41));
        label_4->setStyleSheet(QString::fromUtf8("font:  20pt \"Consolas\";\n"
""));
        label_8 = new QLabel(MyOrderDetail);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(450, 340, 191, 31));
        label_8->setStyleSheet(QString::fromUtf8("font: 18pt \"Consolas\";\n"
""));
        layoutWidget = new QWidget(MyOrderDetail);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(678, 220, 111, 86));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        m_price = new QLabel(layoutWidget);
        m_price->setObjectName(QString::fromUtf8("m_price"));
        m_price->setStyleSheet(QString::fromUtf8("font: 15pt \"Consolas\";\n"
""));
        m_price->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(m_price);

        ship_price = new QLabel(layoutWidget);
        ship_price->setObjectName(QString::fromUtf8("ship_price"));
        ship_price->setLayoutDirection(Qt::RightToLeft);
        ship_price->setStyleSheet(QString::fromUtf8("font: 15pt \"Consolas\";\n"
""));
        ship_price->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(ship_price);

        label_2 = new QLabel(MyOrderDetail);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(510, 20, 261, 41));
        label_2->setStyleSheet(QString::fromUtf8("font: 20pt \"Consolas\";\n"
""));
        layoutWidget1 = new QWidget(MyOrderDetail);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(450, 220, 231, 86));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 15pt \"Consolas\";\n"
""));

        verticalLayout->addWidget(label_5);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("font: 15pt \"Consolas\";\n"
""));

        verticalLayout->addWidget(label_7);

        tableWidget = new QTableWidget(MyOrderDetail);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(30, 80, 371, 281));
        tableWidget->setFrameShape(QFrame::NoFrame);
        total_price = new QLabel(MyOrderDetail);
        total_price->setObjectName(QString::fromUtf8("total_price"));
        total_price->setGeometry(QRect(660, 340, 129, 24));
        total_price->setLayoutDirection(Qt::RightToLeft);
        total_price->setStyleSheet(QString::fromUtf8("font: 18pt \"Consolas\";\n"
""));
        total_price->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(MyOrderDetail);

        QMetaObject::connectSlotsByName(MyOrderDetail);
    } // setupUi

    void retranslateUi(QDialog *MyOrderDetail)
    {
        MyOrderDetail->setWindowTitle(QCoreApplication::translate("MyOrderDetail", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("MyOrderDetail", "PRODUCT DETAILS", nullptr));
        label_3->setText(QCoreApplication::translate("MyOrderDetail", "Address", nullptr));
        label_4->setText(QCoreApplication::translate("MyOrderDetail", "PAYMENT DETAILS", nullptr));
        label_8->setText(QCoreApplication::translate("MyOrderDetail", "Total Payment", nullptr));
        m_price->setText(QCoreApplication::translate("MyOrderDetail", "$", nullptr));
        ship_price->setText(QCoreApplication::translate("MyOrderDetail", "$", nullptr));
        label_2->setText(QCoreApplication::translate("MyOrderDetail", "ORDER DETAILS", nullptr));
        label_5->setText(QCoreApplication::translate("MyOrderDetail", "Merchandise subtotal", nullptr));
        label_7->setText(QCoreApplication::translate("MyOrderDetail", "Shipping subtotal", nullptr));
        total_price->setText(QCoreApplication::translate("MyOrderDetail", "$", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyOrderDetail: public Ui_MyOrderDetail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYORDERDETAIL_H
