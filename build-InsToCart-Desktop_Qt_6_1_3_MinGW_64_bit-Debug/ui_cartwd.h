/********************************************************************************
** Form generated from reading UI file 'cartwd.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARTWD_H
#define UI_CARTWD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CartWD
{
public:
    QTabWidget *tabWidget;
    QLabel *label;
    QLabel *text;
    QPushButton *pushButton_place;

    void setupUi(QWidget *CartWD)
    {
        if (CartWD->objectName().isEmpty())
            CartWD->setObjectName(QString::fromUtf8("CartWD"));
        CartWD->resize(800, 600);
        CartWD->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 188, 46);"));
        tabWidget = new QTabWidget(CartWD);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(30, 110, 741, 351));
        tabWidget->setStyleSheet(QString::fromUtf8("font: 12pt \"Consolas\";\n"
"color: rgb(50, 50, 50);"));
        label = new QLabel(CartWD);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 10, 131, 81));
        label->setStyleSheet(QString::fromUtf8("color: rgb(50, 50, 50);\n"
"font:  40pt \"Impact\";\n"
"background-color: rgba(255, 255, 255, 0);"));
        label->setAlignment(Qt::AlignCenter);
        text = new QLabel(CartWD);
        text->setObjectName(QString::fromUtf8("text"));
        text->setGeometry(QRect(280, 240, 241, 51));
        text->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 24pt \"Consolas\";"));
        text->setAlignment(Qt::AlignCenter);
        pushButton_place = new QPushButton(CartWD);
        pushButton_place->setObjectName(QString::fromUtf8("pushButton_place"));
        pushButton_place->setGeometry(QRect(630, 510, 141, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Consolas")});
        font.setPointSize(14);
        pushButton_place->setFont(font);
        pushButton_place->setFocusPolicy(Qt::ClickFocus);
        pushButton_place->setAutoFillBackground(false);
        pushButton_place->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 2px solid black;\n"
"border-radius:  15px; "));
        pushButton_place->setIconSize(QSize(20, 20));
        pushButton_place->setAutoDefault(false);
        pushButton_place->setFlat(true);

        retranslateUi(CartWD);

        tabWidget->setCurrentIndex(-1);
        pushButton_place->setDefault(false);


        QMetaObject::connectSlotsByName(CartWD);
    } // setupUi

    void retranslateUi(QWidget *CartWD)
    {
        CartWD->setWindowTitle(QCoreApplication::translate("CartWD", "Form", nullptr));
        label->setText(QCoreApplication::translate("CartWD", "Cart", nullptr));
        text->setText(QCoreApplication::translate("CartWD", "NO ITEM YET", nullptr));
        pushButton_place->setText(QCoreApplication::translate("CartWD", "CHECK OUT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CartWD: public Ui_CartWD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARTWD_H
