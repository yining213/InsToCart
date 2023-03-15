/********************************************************************************
** Form generated from reading UI file 'mymarket.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYMARKET_H
#define UI_MYMARKET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyMarket
{
public:
    QLabel *label;
    QPushButton *back;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *search1;
    QLineEdit *searchNametext;
    QPushButton *search2;
    QLineEdit *searchIDtext;
    QComboBox *searchType;
    QLabel *label_4;
    QTableWidget *tableWidget;
    QPushButton *update;
    QPushButton *addProduct;
    QPushButton *del;
    QWidget *page_2;
    QTabWidget *tabWidget;
    QWidget *ToBeCompleted;
    QTableWidget *tbctable;
    QPushButton *save;
    QWidget *Completed;
    QTableWidget *ctable;
    QPushButton *managestock;
    QPushButton *manageorder;
    QLabel *curpage;

    void setupUi(QDialog *MyMarket)
    {
        if (MyMarket->objectName().isEmpty())
            MyMarket->setObjectName(QString::fromUtf8("MyMarket"));
        MyMarket->resize(1000, 700);
        MyMarket->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 188, 46);"));
        label = new QLabel(MyMarket);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 20, 301, 101));
        QFont font;
        font.setFamilies({QString::fromUtf8("Consolas")});
        font.setPointSize(40);
        font.setBold(false);
        font.setItalic(false);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("font: 40pt \"Consolas\";\n"
""));
        back = new QPushButton(MyMarket);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(60, 630, 61, 41));
        back->setStyleSheet(QString::fromUtf8("border-image:url(./img/backarrow.png);"));
        back->setAutoDefault(false);
        back->setFlat(true);
        stackedWidget = new QStackedWidget(MyMarket);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(40, 150, 911, 481));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayoutWidget = new QWidget(page);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 10, 311, 271));
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
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Consolas")});
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        searchNametext->setFont(font1);
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

        label_4 = new QLabel(page);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 340, 51, 51));
        tableWidget = new QTableWidget(page);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(360, 10, 521, 341));
        tableWidget->setStyleSheet(QString::fromUtf8("    border-style: outset;\n"
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
        update = new QPushButton(page);
        update->setObjectName(QString::fromUtf8("update"));
        update->setGeometry(QRect(360, 370, 131, 41));
        update->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"font: 75 16pt \"Consolas\";\n"
"color: white;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    padding: 6px;"));
        addProduct = new QPushButton(page);
        addProduct->setObjectName(QString::fromUtf8("addProduct"));
        addProduct->setGeometry(QRect(680, 370, 81, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Consolas")});
        font2.setPointSize(16);
        font2.setBold(false);
        font2.setItalic(false);
        addProduct->setFont(font2);
        addProduct->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"font: 75 16pt \"Consolas\";\n"
"color: white;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    padding: 6px;"));
        del = new QPushButton(page);
        del->setObjectName(QString::fromUtf8("del"));
        del->setGeometry(QRect(800, 370, 81, 41));
        del->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"font: 75 16pt \"Consolas\";\n"
"color: white;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    padding: 6px;"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        tabWidget = new QTabWidget(page_2);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 10, 871, 421));
        tabWidget->setStyleSheet(QString::fromUtf8("font: 15pt \"Consolas\";\n"
"background-color: rgb(255, 255, 255, 70);\n"
"border-style: outset;\n"
"\n"
""));
        ToBeCompleted = new QWidget();
        ToBeCompleted->setObjectName(QString::fromUtf8("ToBeCompleted"));
        tbctable = new QTableWidget(ToBeCompleted);
        tbctable->setObjectName(QString::fromUtf8("tbctable"));
        tbctable->setGeometry(QRect(30, 30, 811, 290));
        tbctable->setStyleSheet(QString::fromUtf8("    border-style: outset;\n"
"    border-width: 1px;\n"
"    border-color: beige;\n"
"font: 17pt \"Consolas\";\n"
"color: black;\n"
"border-style: outset;\n"
"padding: 2pt;\n"
"\n"
""));
        tbctable->setDragDropOverwriteMode(true);
        tbctable->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tbctable->setShowGrid(false);
        tbctable->setGridStyle(Qt::NoPen);
        tbctable->setWordWrap(false);
        save = new QPushButton(ToBeCompleted);
        save->setObjectName(QString::fromUtf8("save"));
        save->setGeometry(QRect(740, 330, 101, 41));
        save->setStyleSheet(QString::fromUtf8("background-color: white;    \n"
"border-style: outset;\n"
"font: 9pt \"Consolas\" ;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 15px;\n"
"    padding: 6px;\n"
"background-color: rgb(243, 188, 46, 70);"));
        save->setFlat(false);
        tabWidget->addTab(ToBeCompleted, QString());
        Completed = new QWidget();
        Completed->setObjectName(QString::fromUtf8("Completed"));
        ctable = new QTableWidget(Completed);
        ctable->setObjectName(QString::fromUtf8("ctable"));
        ctable->setGeometry(QRect(30, 30, 811, 290));
        ctable->setStyleSheet(QString::fromUtf8("    border-style: outset;\n"
"background-color: rgba(255, 255, 255, 70);\n"
"    border-width: 1px;\n"
"    border-color: beige;\n"
"font: 17pt \"Consolas\";\n"
"color: black;\n"
"border-style: outset;\n"
"padding: 2pt;\n"
"\n"
""));
        ctable->setDragDropOverwriteMode(true);
        ctable->setSelectionMode(QAbstractItemView::ExtendedSelection);
        ctable->setShowGrid(false);
        ctable->setGridStyle(Qt::NoPen);
        ctable->setWordWrap(false);
        tabWidget->addTab(Completed, QString());
        stackedWidget->addWidget(page_2);
        managestock = new QPushButton(MyMarket);
        managestock->setObjectName(QString::fromUtf8("managestock"));
        managestock->setGeometry(QRect(570, 60, 171, 41));
        managestock->setStyleSheet(QString::fromUtf8("border-radius: 13px;\n"
"color: rgb(255, 255, 255);\n"
"font: 14pt \"Consolas\";\n"
"\n"
""));
        manageorder = new QPushButton(MyMarket);
        manageorder->setObjectName(QString::fromUtf8("manageorder"));
        manageorder->setGeometry(QRect(760, 60, 171, 41));
        manageorder->setStyleSheet(QString::fromUtf8("border-radius: 13px;\n"
"color: rgb(255, 255, 255);\n"
"font: 14pt \"Consolas\";\n"
""));
        curpage = new QLabel(MyMarket);
        curpage->setObjectName(QString::fromUtf8("curpage"));
        curpage->setGeometry(QRect(60, 90, 191, 41));
        curpage->setStyleSheet(QString::fromUtf8("font: 20pt \"Consolas\";\n"
"color:rgb(38, 115, 154);\n"
"color: white;\n"
""));

        retranslateUi(MyMarket);

        back->setDefault(false);
        stackedWidget->setCurrentIndex(1);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MyMarket);
    } // setupUi

    void retranslateUi(QDialog *MyMarket)
    {
        MyMarket->setWindowTitle(QCoreApplication::translate("MyMarket", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("MyMarket", "MY MARKET", nullptr));
        back->setText(QString());
        search1->setText(QCoreApplication::translate("MyMarket", "SEARCH", nullptr));
        searchNametext->setPlaceholderText(QCoreApplication::translate("MyMarket", "Name", nullptr));
        search2->setText(QCoreApplication::translate("MyMarket", "SEARCH", nullptr));
        searchIDtext->setPlaceholderText(QCoreApplication::translate("MyMarket", "itemID", nullptr));
        searchType->setItemText(0, QCoreApplication::translate("MyMarket", "ALL", nullptr));
        searchType->setItemText(1, QCoreApplication::translate("MyMarket", "FOOD", nullptr));
        searchType->setItemText(2, QCoreApplication::translate("MyMarket", "CLOTHES", nullptr));
        searchType->setItemText(3, QCoreApplication::translate("MyMarket", "HOME LIVING", nullptr));
        searchType->setItemText(4, QCoreApplication::translate("MyMarket", "ELECTRIC DEVICE", nullptr));

        searchType->setPlaceholderText(QCoreApplication::translate("MyMarket", "CATEGORY", nullptr));
        label_4->setText(QString());
        update->setText(QCoreApplication::translate("MyMarket", "UPDATE", nullptr));
        addProduct->setText(QCoreApplication::translate("MyMarket", "ADD", nullptr));
        del->setText(QCoreApplication::translate("MyMarket", "DEL", nullptr));
        save->setText(QCoreApplication::translate("MyMarket", "SAVE", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ToBeCompleted), QCoreApplication::translate("MyMarket", "To Be Completed", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Completed), QCoreApplication::translate("MyMarket", "Completed", nullptr));
        managestock->setText(QCoreApplication::translate("MyMarket", "MANAGE STOCK", nullptr));
        manageorder->setText(QCoreApplication::translate("MyMarket", "MANAGE ORDER", nullptr));
        curpage->setText(QCoreApplication::translate("MyMarket", "123", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyMarket: public Ui_MyMarket {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYMARKET_H
