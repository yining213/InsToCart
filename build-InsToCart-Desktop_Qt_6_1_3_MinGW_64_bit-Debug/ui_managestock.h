/********************************************************************************
** Form generated from reading UI file 'managestock.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGESTOCK_H
#define UI_MANAGESTOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageStock
{
public:
    QLabel *label;
    QLabel *label_4;
    QPushButton *addProduct;
    QPushButton *update;
    QPushButton *del;
    QPushButton *back;
    QTableWidget *tableWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *search1;
    QLineEdit *searchNametext;
    QPushButton *search2;
    QLineEdit *searchIDtext;
    QComboBox *searchType;

    void setupUi(QDialog *ManageStock)
    {
        if (ManageStock->objectName().isEmpty())
            ManageStock->setObjectName(QString::fromUtf8("ManageStock"));
        ManageStock->resize(1000, 700);
        ManageStock->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 188, 46);"));
        label = new QLabel(ManageStock);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 30, 411, 91));
        QFont font;
        font.setFamilies({QString::fromUtf8("Consolas")});
        font.setPointSize(40);
        font.setBold(false);
        font.setItalic(false);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("font: 40pt \"Consolas\";\n"
""));
        label_4 = new QLabel(ManageStock);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 380, 51, 51));
        addProduct = new QPushButton(ManageStock);
        addProduct->setObjectName(QString::fromUtf8("addProduct"));
        addProduct->setGeometry(QRect(750, 620, 81, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Consolas")});
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setItalic(false);
        addProduct->setFont(font1);
        addProduct->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"font: 75 16pt \"Consolas\";\n"
"color: white;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    padding: 6px;"));
        update = new QPushButton(ManageStock);
        update->setObjectName(QString::fromUtf8("update"));
        update->setGeometry(QRect(480, 620, 131, 41));
        update->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"font: 75 16pt \"Consolas\";\n"
"color: white;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    padding: 6px;"));
        del = new QPushButton(ManageStock);
        del->setObjectName(QString::fromUtf8("del"));
        del->setGeometry(QRect(860, 620, 81, 41));
        del->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"font: 75 16pt \"Consolas\";\n"
"color: white;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    padding: 6px;"));
        back = new QPushButton(ManageStock);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(50, 620, 61, 41));
        back->setStyleSheet(QString::fromUtf8("border-image:url(./img/backarrow.png);"));
        back->setAutoDefault(false);
        back->setFlat(true);
        tableWidget = new QTableWidget(ManageStock);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(440, 160, 521, 421));
        tableWidget->setStyleSheet(QString::fromUtf8("    border-style: outset;\n"
"background-color: rgba(0, 0, 0, 70);\n"
"background-color: rgba(255, 255, 255, 70);\n"
"    border-width: 1px;\n"
"    border-color: beige;\n"
"font: 17pt \"Consolas\";\n"
"color: black;\n"
"border-style: outset;\n"
"padding: 2pt;\n"
"\n"
""));
        tableWidget->setDragDropOverwriteMode(true);
        tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tableWidget->setShowGrid(false);
        tableWidget->setGridStyle(Qt::NoPen);
        tableWidget->setWordWrap(false);
        gridLayoutWidget = new QWidget(ManageStock);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(50, 160, 311, 271));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        search1 = new QPushButton(gridLayoutWidget);
        search1->setObjectName(QString::fromUtf8("search1"));
        search1->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-style: outset;\n"
"padding: 5px;\n"
"font: 10pt \"Consolas\";\n"
"    border-width: 2px;\n"
"    border-radius: 5px;\n"
"    border-color: beige;\n"
""));

        gridLayout->addWidget(search1, 0, 1, 1, 1);

        searchNametext = new QLineEdit(gridLayoutWidget);
        searchNametext->setObjectName(QString::fromUtf8("searchNametext"));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Consolas")});
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setItalic(false);
        searchNametext->setFont(font2);
        searchNametext->setStyleSheet(QString::fromUtf8("    border-style: outset;\n"
"font: 12pt \"Consolas\";\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    min-width: 10em;\n"
"    padding: 6px;\n"
"color: white;\n"
"background-color: rgba(0, 0, 0, 70);\n"
""));

        gridLayout->addWidget(searchNametext, 1, 0, 1, 1);

        search2 = new QPushButton(gridLayoutWidget);
        search2->setObjectName(QString::fromUtf8("search2"));
        search2->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-style: outset;\n"
"padding: 5px;\n"
"font: 10pt \"Consolas\";\n"
"    border-width: 2px;\n"
"    border-radius: 5px;\n"
"    border-color: beige;\n"
""));

        gridLayout->addWidget(search2, 1, 1, 1, 1);

        searchIDtext = new QLineEdit(gridLayoutWidget);
        searchIDtext->setObjectName(QString::fromUtf8("searchIDtext"));
        searchIDtext->setStyleSheet(QString::fromUtf8("    border-style: outset;\n"
"font: 12pt \"Consolas\";\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    min-width: 10em;\n"
"    padding: 6px;\n"
"color: white;\n"
"background-color: rgba(0, 0, 0, 70);\n"
""));

        gridLayout->addWidget(searchIDtext, 0, 0, 1, 1);

        searchType = new QComboBox(gridLayoutWidget);
        searchType->addItem(QString());
        searchType->addItem(QString());
        searchType->addItem(QString());
        searchType->addItem(QString());
        searchType->addItem(QString());
        searchType->setObjectName(QString::fromUtf8("searchType"));
        searchType->setStyleSheet(QString::fromUtf8("    border-style: outset;\n"
"font: 12pt \"Consolas\";\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    min-width: 10em;\n"
"    padding: 6px;\n"
"color: white;\n"
"background-color: rgba(0, 0, 0, 70);\n"
""));

        gridLayout->addWidget(searchType, 2, 0, 1, 1);


        retranslateUi(ManageStock);

        back->setDefault(false);


        QMetaObject::connectSlotsByName(ManageStock);
    } // setupUi

    void retranslateUi(QDialog *ManageStock)
    {
        ManageStock->setWindowTitle(QCoreApplication::translate("ManageStock", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ManageStock", "MANAGE STOCK", nullptr));
        label_4->setText(QString());
        addProduct->setText(QCoreApplication::translate("ManageStock", "ADD", nullptr));
        update->setText(QCoreApplication::translate("ManageStock", "UPDATE", nullptr));
        del->setText(QCoreApplication::translate("ManageStock", "DEL", nullptr));
        back->setText(QString());
        search1->setText(QCoreApplication::translate("ManageStock", "SEARCH", nullptr));
        searchNametext->setPlaceholderText(QCoreApplication::translate("ManageStock", "Name", nullptr));
        search2->setText(QCoreApplication::translate("ManageStock", "SEARCH", nullptr));
        searchIDtext->setPlaceholderText(QCoreApplication::translate("ManageStock", "itemID", nullptr));
        searchType->setItemText(0, QCoreApplication::translate("ManageStock", "ALL", nullptr));
        searchType->setItemText(1, QCoreApplication::translate("ManageStock", "FOOD", nullptr));
        searchType->setItemText(2, QCoreApplication::translate("ManageStock", "CLOTHES", nullptr));
        searchType->setItemText(3, QCoreApplication::translate("ManageStock", "HOME LIVING", nullptr));
        searchType->setItemText(4, QCoreApplication::translate("ManageStock", "ELECTRIC DEVICE", nullptr));

        searchType->setPlaceholderText(QCoreApplication::translate("ManageStock", "CATEGORY", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManageStock: public Ui_ManageStock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGESTOCK_H
