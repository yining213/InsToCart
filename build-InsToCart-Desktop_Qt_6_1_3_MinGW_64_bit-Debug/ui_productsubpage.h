/********************************************************************************
** Form generated from reading UI file 'productsubpage.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTSUBPAGE_H
#define UI_PRODUCTSUBPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProductSubPage
{
public:
    QLabel *label_category_2;
    QLabel *label_category;
    QDoubleSpinBox *doubleSpinBox;
    QTabWidget *tabWidget;
    QWidget *tab_desc;
    QTextBrowser *textBrowser;
    QWidget *tab_rate;
    QTableWidget *table;
    QLabel *label;
    QLabel *label_stock;
    QLabel *label_seller_2;
    QLabel *label_stock_2;
    QLabel *label_seller;
    QLabel *label_pdName;
    QPushButton *pushButton_addToCart;
    QLabel *label_SF;
    QLabel *label_SF_2;
    QLabel *label_rating_1;
    QLabel *label_rating_2;
    QLabel *label_price;

    void setupUi(QWidget *ProductSubPage)
    {
        if (ProductSubPage->objectName().isEmpty())
            ProductSubPage->setObjectName(QString::fromUtf8("ProductSubPage"));
        ProductSubPage->resize(606, 541);
        ProductSubPage->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 188, 46);"));
        label_category_2 = new QLabel(ProductSubPage);
        label_category_2->setObjectName(QString::fromUtf8("label_category_2"));
        label_category_2->setGeometry(QRect(340, 100, 231, 21));
        label_category_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Consolas\";\n"
"color: rgb(50, 50, 50);"));
        label_category = new QLabel(ProductSubPage);
        label_category->setObjectName(QString::fromUtf8("label_category"));
        label_category->setGeometry(QRect(250, 100, 91, 21));
        label_category->setStyleSheet(QString::fromUtf8("font: 12pt \"Consolas\";\n"
"color: rgb(50, 50, 50);"));
        doubleSpinBox = new QDoubleSpinBox(ProductSubPage);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(350, 250, 81, 31));
        doubleSpinBox->setStyleSheet(QString::fromUtf8("font: 12pt \"Consolas\";\n"
"color: rgb(50, 50, 50);"));
        doubleSpinBox->setAlignment(Qt::AlignCenter);
        doubleSpinBox->setDecimals(0);
        tabWidget = new QTabWidget(ProductSubPage);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(40, 300, 531, 211));
        tabWidget->setStyleSheet(QString::fromUtf8("color: rgb(50, 50, 50);\n"
"font: 12pt \"Consolas\";"));
        tab_desc = new QWidget();
        tab_desc->setObjectName(QString::fromUtf8("tab_desc"));
        textBrowser = new QTextBrowser(tab_desc);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 10, 501, 231));
        textBrowser->setStyleSheet(QString::fromUtf8("border: 0px solid white;\n"
"font: 12pt \"Consolas\";\n"
"color: rgb(50, 50, 50);"));
        tabWidget->addTab(tab_desc, QString());
        tab_rate = new QWidget();
        tab_rate->setObjectName(QString::fromUtf8("tab_rate"));
        table = new QTableWidget(tab_rate);
        table->setObjectName(QString::fromUtf8("table"));
        table->setGeometry(QRect(0, 0, 531, 171));
        table->setStyleSheet(QString::fromUtf8("font: 12pt \"Consolas\";\n"
"color: rgb(0, 0, 0);"));
        tabWidget->addTab(tab_rate, QString());
        label = new QLabel(ProductSubPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 40, 171, 171));
        label_stock = new QLabel(ProductSubPage);
        label_stock->setObjectName(QString::fromUtf8("label_stock"));
        label_stock->setGeometry(QRect(250, 70, 61, 21));
        label_stock->setStyleSheet(QString::fromUtf8("font: 12pt \"Consolas\";\n"
"color: rgb(50, 50, 50);"));
        label_seller_2 = new QLabel(ProductSubPage);
        label_seller_2->setObjectName(QString::fromUtf8("label_seller_2"));
        label_seller_2->setGeometry(QRect(320, 130, 201, 21));
        label_seller_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Consolas\";\n"
"color: rgb(50, 50, 50);"));
        label_stock_2 = new QLabel(ProductSubPage);
        label_stock_2->setObjectName(QString::fromUtf8("label_stock_2"));
        label_stock_2->setGeometry(QRect(310, 70, 151, 21));
        label_stock_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Consolas\";\n"
"color: rgb(50, 50, 50);"));
        label_seller = new QLabel(ProductSubPage);
        label_seller->setObjectName(QString::fromUtf8("label_seller"));
        label_seller->setGeometry(QRect(250, 130, 71, 21));
        label_seller->setStyleSheet(QString::fromUtf8("font: 12pt \"Consolas\";\n"
"color: rgb(50, 50, 50);"));
        label_pdName = new QLabel(ProductSubPage);
        label_pdName->setObjectName(QString::fromUtf8("label_pdName"));
        label_pdName->setGeometry(QRect(250, 30, 311, 31));
        label_pdName->setStyleSheet(QString::fromUtf8("font: 16pt \"Consolas\";\n"
"color: rgb(50, 50, 50);"));
        pushButton_addToCart = new QPushButton(ProductSubPage);
        pushButton_addToCart->setObjectName(QString::fromUtf8("pushButton_addToCart"));
        pushButton_addToCart->setGeometry(QRect(540, 250, 41, 31));
        pushButton_addToCart->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_addToCart->setStyleSheet(QString::fromUtf8("image: url(:/addtocart.png);"));
        pushButton_addToCart->setFlat(true);
        label_SF = new QLabel(ProductSubPage);
        label_SF->setObjectName(QString::fromUtf8("label_SF"));
        label_SF->setGeometry(QRect(250, 160, 131, 21));
        label_SF->setStyleSheet(QString::fromUtf8("font: 12pt \"Consolas\";\n"
"color: rgb(50, 50, 50);"));
        label_SF_2 = new QLabel(ProductSubPage);
        label_SF_2->setObjectName(QString::fromUtf8("label_SF_2"));
        label_SF_2->setGeometry(QRect(380, 160, 161, 21));
        label_SF_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Consolas\";\n"
"color: rgb(50, 50, 50);"));
        label_rating_1 = new QLabel(ProductSubPage);
        label_rating_1->setObjectName(QString::fromUtf8("label_rating_1"));
        label_rating_1->setGeometry(QRect(250, 190, 71, 21));
        label_rating_1->setStyleSheet(QString::fromUtf8("font: 12pt \"Consolas\";\n"
"color: rgb(50, 50, 50);"));
        label_rating_2 = new QLabel(ProductSubPage);
        label_rating_2->setObjectName(QString::fromUtf8("label_rating_2"));
        label_rating_2->setGeometry(QRect(330, 190, 161, 21));
        label_rating_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Consolas\";\n"
"color: rgb(50, 50, 50);"));
        label_price = new QLabel(ProductSubPage);
        label_price->setObjectName(QString::fromUtf8("label_price"));
        label_price->setGeometry(QRect(450, 250, 71, 31));
        label_price->setStyleSheet(QString::fromUtf8("font: 12pt \"Consolas\";\n"
"color: rgb(50, 50, 50);"));

        retranslateUi(ProductSubPage);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ProductSubPage);
    } // setupUi

    void retranslateUi(QWidget *ProductSubPage)
    {
        ProductSubPage->setWindowTitle(QCoreApplication::translate("ProductSubPage", "Form", nullptr));
        label_category_2->setText(QCoreApplication::translate("ProductSubPage", "CategoryName", nullptr));
        label_category->setText(QCoreApplication::translate("ProductSubPage", "Category:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_desc), QCoreApplication::translate("ProductSubPage", "Description", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_rate), QCoreApplication::translate("ProductSubPage", "Rate", nullptr));
        label->setText(QString());
        label_stock->setText(QCoreApplication::translate("ProductSubPage", "Stock: ", nullptr));
        label_seller_2->setText(QCoreApplication::translate("ProductSubPage", "SellerName", nullptr));
        label_stock_2->setText(QCoreApplication::translate("ProductSubPage", "stockNum", nullptr));
        label_seller->setText(QCoreApplication::translate("ProductSubPage", "Seller:", nullptr));
        label_pdName->setText(QCoreApplication::translate("ProductSubPage", "ProductName", nullptr));
        pushButton_addToCart->setText(QString());
        label_SF->setText(QCoreApplication::translate("ProductSubPage", "Shipping Fee: ", nullptr));
        label_SF_2->setText(QCoreApplication::translate("ProductSubPage", "Shipping Fee", nullptr));
        label_rating_1->setText(QCoreApplication::translate("ProductSubPage", "Rating:", nullptr));
        label_rating_2->setText(QCoreApplication::translate("ProductSubPage", "Rating", nullptr));
        label_price->setText(QCoreApplication::translate("ProductSubPage", "Price", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductSubPage: public Ui_ProductSubPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTSUBPAGE_H
