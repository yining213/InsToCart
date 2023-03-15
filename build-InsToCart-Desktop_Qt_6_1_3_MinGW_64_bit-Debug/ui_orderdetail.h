/********************************************************************************
** Form generated from reading UI file 'orderdetail.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERDETAIL_H
#define UI_ORDERDETAIL_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_orderDetail
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_subtotal;
    QLabel *label_5;
    QLabel *label_SF;
    QLabel *label_6;
    QLabel *label_total;
    QPushButton *pushButton_place;

    void setupUi(QWidget *orderDetail)
    {
        if (orderDetail->objectName().isEmpty())
            orderDetail->setObjectName(QString::fromUtf8("orderDetail"));
        orderDetail->resize(400, 456);
        orderDetail->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 12pt \"Consolas\";\n"
"color: rgb(0, 0, 0);"));
        label = new QLabel(orderDetail);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 30, 271, 41));
        label->setStyleSheet(QString::fromUtf8("font: 20pt \"Consolas\";"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(orderDetail);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 90, 91, 21));
        lineEdit = new QLineEdit(orderDetail);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 120, 361, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Consolas")});
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        lineEdit->setFont(font);
        lineEdit->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"border-radius:  13px; \n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"font: 10pt \"Consolas\";\n"
"padding-left: 10px;"));
        lineEdit->setLocale(QLocale(QLocale::Chinese, QLocale::Taiwan));
        label_4 = new QLabel(orderDetail);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 190, 271, 41));
        label_4->setStyleSheet(QString::fromUtf8("font: 20pt \"Consolas\";"));
        label_4->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(orderDetail);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 250, 211, 21));
        label_3->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Consolas\";"));
        label_subtotal = new QLabel(orderDetail);
        label_subtotal->setObjectName(QString::fromUtf8("label_subtotal"));
        label_subtotal->setGeometry(QRect(280, 250, 91, 21));
        label_subtotal->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Consolas\";"));
        label_subtotal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_5 = new QLabel(orderDetail);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 290, 211, 21));
        label_SF = new QLabel(orderDetail);
        label_SF->setObjectName(QString::fromUtf8("label_SF"));
        label_SF->setGeometry(QRect(280, 290, 91, 21));
        label_SF->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_6 = new QLabel(orderDetail);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 330, 211, 21));
        label_6->setStyleSheet(QString::fromUtf8("font: 75 14pt \"Consolas\";"));
        label_total = new QLabel(orderDetail);
        label_total->setObjectName(QString::fromUtf8("label_total"));
        label_total->setGeometry(QRect(280, 330, 91, 21));
        label_total->setStyleSheet(QString::fromUtf8("font: 75 14pt \"Consolas\";"));
        label_total->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_place = new QPushButton(orderDetail);
        pushButton_place->setObjectName(QString::fromUtf8("pushButton_place"));
        pushButton_place->setGeometry(QRect(220, 390, 161, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Consolas")});
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        pushButton_place->setFont(font1);
        pushButton_place->setFocusPolicy(Qt::ClickFocus);
        pushButton_place->setAutoFillBackground(false);
        pushButton_place->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 2px solid black;\n"
"border-radius:  15px; "));
        pushButton_place->setIconSize(QSize(20, 20));
        pushButton_place->setAutoDefault(false);
        pushButton_place->setFlat(true);

        retranslateUi(orderDetail);

        pushButton_place->setDefault(false);


        QMetaObject::connectSlotsByName(orderDetail);
    } // setupUi

    void retranslateUi(QWidget *orderDetail)
    {
        orderDetail->setWindowTitle(QCoreApplication::translate("orderDetail", "Form", nullptr));
        label->setText(QCoreApplication::translate("orderDetail", "ORDER DETAILS", nullptr));
        label_2->setText(QCoreApplication::translate("orderDetail", "Shipping", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("orderDetail", "Address", nullptr));
        label_4->setText(QCoreApplication::translate("orderDetail", "Payment Details", nullptr));
        label_3->setText(QCoreApplication::translate("orderDetail", "Merchandise subtotal", nullptr));
        label_subtotal->setText(QCoreApplication::translate("orderDetail", "price", nullptr));
        label_5->setText(QCoreApplication::translate("orderDetail", "Shipping subtotal", nullptr));
        label_SF->setText(QCoreApplication::translate("orderDetail", "SF", nullptr));
        label_6->setText(QCoreApplication::translate("orderDetail", "Total payment", nullptr));
        label_total->setText(QCoreApplication::translate("orderDetail", "SF", nullptr));
        pushButton_place->setText(QCoreApplication::translate("orderDetail", "PLACE ORDER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class orderDetail: public Ui_orderDetail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERDETAIL_H
