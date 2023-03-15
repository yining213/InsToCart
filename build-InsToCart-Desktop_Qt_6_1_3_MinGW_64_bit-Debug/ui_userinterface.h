/********************************************************************************
** Form generated from reading UI file 'userinterface.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINTERFACE_H
#define UI_USERINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserInterface
{
public:
    QWidget *centralwidget;
    QFrame *line;
    QLabel *photo;
    QLabel *username;
    QFrame *line_2;
    QPushButton *pushButton_myaccount;
    QPushButton *pushButton_myorders;
    QStackedWidget *stackedWidget;
    QWidget *page_account;
    QLineEdit *lineEdit_phone;
    QComboBox *comboBox_gender;
    QLabel *label_username_3;
    QLabel *photo_2;
    QLineEdit *lineEdit_account;
    QLabel *label_username_5;
    QLabel *label_username_2;
    QLabel *label_username_6;
    QLabel *label_username_4;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_editPWD;
    QLabel *label_usernameAlert;
    QFrame *frame;
    QLabel *label_accountAlert;
    QLabel *label_pwdAlert;
    QLabel *label_phoneAlert;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QPushButton *pushButton_save;
    QPushButton *pushButton_edit;
    QLabel *label_birthday;
    QWidget *page_orders;
    QFrame *frame_2;
    QTabWidget *tabWidget;
    QWidget *placed;
    QTableWidget *tableWidget_1;
    QWidget *toShip;
    QTableWidget *tableWidget_2;
    QWidget *arrived;
    QTableWidget *tableWidget_3;
    QWidget *toRate;
    QTableWidget *tableWidget_4;
    QWidget *tab;
    QTableWidget *tableWidget_5;
    QWidget *canceled;
    QTableWidget *tableWidget_6;
    QPushButton *mymarket;
    QPushButton *home;
    QPushButton *back;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UserInterface)
    {
        if (UserInterface->objectName().isEmpty())
            UserInterface->setObjectName(QString::fromUtf8("UserInterface"));
        UserInterface->resize(1200, 720);
        UserInterface->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 188, 46);\n"
""));
        centralwidget = new QWidget(UserInterface);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(250, 0, 21, 725));
        QFont font;
        font.setFamilies({QString::fromUtf8("Consolas")});
        font.setPointSize(9);
        line->setFont(font);
        line->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(5);
        line->setFrameShape(QFrame::VLine);
        photo = new QLabel(centralwidget);
        photo->setObjectName(QString::fromUtf8("photo"));
        photo->setGeometry(QRect(70, 110, 121, 111));
        photo->setStyleSheet(QString::fromUtf8("image: url(:/personal_photo.png);\n"
"font: 12pt \"Consolas\";\n"
"color:rgb(50, 50, 50);"));
        photo->setAlignment(Qt::AlignCenter);
        username = new QLabel(centralwidget);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(40, 240, 181, 21));
        username->setStyleSheet(QString::fromUtf8("color:rgb(50, 50, 50);\n"
"font: 12pt \"Consolas\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
""));
        username->setAlignment(Qt::AlignCenter);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setEnabled(true);
        line_2->setGeometry(QRect(50, 290, 20, 71));
        line_2->setStyleSheet(QString::fromUtf8("color: rgb(50, 50, 50);"));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setLineWidth(3);
        line_2->setFrameShape(QFrame::VLine);
        pushButton_myaccount = new QPushButton(centralwidget);
        pushButton_myaccount->setObjectName(QString::fromUtf8("pushButton_myaccount"));
        pushButton_myaccount->setGeometry(QRect(70, 290, 131, 31));
        pushButton_myaccount->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_myaccount->setStyleSheet(QString::fromUtf8("color:rgb(50, 50, 50);\n"
"font: 12pt \"Consolas\";\n"
"\n"
""));
        pushButton_myaccount->setAutoDefault(false);
        pushButton_myaccount->setFlat(true);
        pushButton_myorders = new QPushButton(centralwidget);
        pushButton_myorders->setObjectName(QString::fromUtf8("pushButton_myorders"));
        pushButton_myorders->setGeometry(QRect(70, 330, 121, 31));
        pushButton_myorders->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_myorders->setStyleSheet(QString::fromUtf8("color:rgb(50, 50, 50);\n"
"font: 12pt \"Consolas\";"));
        pushButton_myorders->setFlat(true);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(289, 60, 891, 591));
        page_account = new QWidget();
        page_account->setObjectName(QString::fromUtf8("page_account"));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Consolas")});
        font1.setPointSize(14);
        page_account->setFont(font1);
        lineEdit_phone = new QLineEdit(page_account);
        lineEdit_phone->setObjectName(QString::fromUtf8("lineEdit_phone"));
        lineEdit_phone->setEnabled(true);
        lineEdit_phone->setGeometry(QRect(250, 340, 181, 31));
        lineEdit_phone->setStyleSheet(QString::fromUtf8("font: 14pt \"Consolas\";\n"
"color:rgb(50, 50, 50);\n"
"border: 0px ;"));
        comboBox_gender = new QComboBox(page_account);
        comboBox_gender->addItem(QString());
        comboBox_gender->addItem(QString());
        comboBox_gender->addItem(QString());
        comboBox_gender->setObjectName(QString::fromUtf8("comboBox_gender"));
        comboBox_gender->setGeometry(QRect(250, 400, 131, 31));
        comboBox_gender->setFont(font1);
        comboBox_gender->setStyleSheet(QString::fromUtf8("border-radius:  8px; \n"
"background-color: rgb(255, 255, 255);\n"
"color:rgb(50, 50, 50);"));
        label_username_3 = new QLabel(page_account);
        label_username_3->setObjectName(QString::fromUtf8("label_username_3"));
        label_username_3->setGeometry(QRect(120, 340, 111, 31));
        label_username_3->setStyleSheet(QString::fromUtf8("color:rgb(50, 50, 50);\n"
"font: 14pt \"Consolas\";"));
        photo_2 = new QLabel(page_account);
        photo_2->setObjectName(QString::fromUtf8("photo_2"));
        photo_2->setGeometry(QRect(120, 50, 121, 111));
        photo_2->setStyleSheet(QString::fromUtf8("image: url(:/personal_photo.png);\n"
"font: 14pt \"Consolas\";\n"
"color:rgb(50, 50, 50);"));
        photo_2->setAlignment(Qt::AlignCenter);
        lineEdit_account = new QLineEdit(page_account);
        lineEdit_account->setObjectName(QString::fromUtf8("lineEdit_account"));
        lineEdit_account->setEnabled(true);
        lineEdit_account->setGeometry(QRect(250, 220, 151, 31));
        lineEdit_account->setStyleSheet(QString::fromUtf8("font: 14pt \"Consolas\";\n"
"color:rgb(50, 50, 50);\n"
"border: 0px ;"));
        label_username_5 = new QLabel(page_account);
        label_username_5->setObjectName(QString::fromUtf8("label_username_5"));
        label_username_5->setGeometry(QRect(120, 460, 111, 31));
        label_username_5->setStyleSheet(QString::fromUtf8("color:rgb(50, 50, 50);\n"
"font: 14pt \"Consolas\";"));
        label_username_2 = new QLabel(page_account);
        label_username_2->setObjectName(QString::fromUtf8("label_username_2"));
        label_username_2->setGeometry(QRect(120, 220, 111, 31));
        label_username_2->setStyleSheet(QString::fromUtf8("color:rgb(50, 50, 50);\n"
"font: 14pt \"Consolas\";"));
        label_username_6 = new QLabel(page_account);
        label_username_6->setObjectName(QString::fromUtf8("label_username_6"));
        label_username_6->setGeometry(QRect(120, 280, 111, 31));
        label_username_6->setStyleSheet(QString::fromUtf8("color:rgb(50, 50, 50);\n"
"font: 14pt \"Consolas\";"));
        label_username_4 = new QLabel(page_account);
        label_username_4->setObjectName(QString::fromUtf8("label_username_4"));
        label_username_4->setGeometry(QRect(120, 400, 111, 31));
        label_username_4->setStyleSheet(QString::fromUtf8("color:rgb(50, 50, 50);\n"
"font: 14pt \"Consolas\";"));
        lineEdit_username = new QLineEdit(page_account);
        lineEdit_username->setObjectName(QString::fromUtf8("lineEdit_username"));
        lineEdit_username->setEnabled(true);
        lineEdit_username->setGeometry(QRect(270, 130, 171, 31));
        lineEdit_username->setStyleSheet(QString::fromUtf8("font: 14pt \"Consolas\";\n"
"color: rgb(50, 50, 50);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 0px;"));
        lineEdit_editPWD = new QLineEdit(page_account);
        lineEdit_editPWD->setObjectName(QString::fromUtf8("lineEdit_editPWD"));
        lineEdit_editPWD->setEnabled(true);
        lineEdit_editPWD->setGeometry(QRect(250, 280, 191, 31));
        lineEdit_editPWD->setStyleSheet(QString::fromUtf8("font: 14pt \"Consolas\";\n"
"color:rgb(50, 50, 50);\n"
"border: 0px ;"));
        lineEdit_editPWD->setEchoMode(QLineEdit::Password);
        label_usernameAlert = new QLabel(page_account);
        label_usernameAlert->setObjectName(QString::fromUtf8("label_usernameAlert"));
        label_usernameAlert->setGeometry(QRect(490, 130, 201, 31));
        label_usernameAlert->setStyleSheet(QString::fromUtf8("color: rgb(50, 50, 50);\n"
"font: 14pt \"Consolas\";\n"
"background-color: rgba(255, 255, 255, 0);"));
        frame = new QFrame(page_account);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(20, 10, 861, 571));
        frame->setStyleSheet(QString::fromUtf8("border: 3px solid white;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-radius: 13px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_accountAlert = new QLabel(frame);
        label_accountAlert->setObjectName(QString::fromUtf8("label_accountAlert"));
        label_accountAlert->setGeometry(QRect(600, 210, 201, 31));
        label_accountAlert->setStyleSheet(QString::fromUtf8("color: rgb(50, 50, 50);\n"
"font: 14pt \"Consolas\";\n"
"border-color: rgba(255, 255, 255, 0);"));
        label_pwdAlert = new QLabel(frame);
        label_pwdAlert->setObjectName(QString::fromUtf8("label_pwdAlert"));
        label_pwdAlert->setGeometry(QRect(480, 280, 201, 31));
        label_pwdAlert->setStyleSheet(QString::fromUtf8("color: rgb(50, 50, 50);\n"
"font: 14pt \"Consolas\";\n"
"border-color: rgba(255, 255, 255, 0);"));
        label_phoneAlert = new QLabel(frame);
        label_phoneAlert->setObjectName(QString::fromUtf8("label_phoneAlert"));
        label_phoneAlert->setGeometry(QRect(450, 330, 201, 31));
        label_phoneAlert->setStyleSheet(QString::fromUtf8("color: rgb(50, 50, 50);\n"
"font: 14pt \"Consolas\";\n"
"border-color: rgba(255, 255, 255, 0);"));
        comboBox = new QComboBox(frame);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(400, 210, 151, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Consolas")});
        font2.setPointSize(12);
        comboBox->setFont(font2);
        comboBox->setAutoFillBackground(false);
        comboBox->setStyleSheet(QString::fromUtf8("color: rgb(50, 50, 50);\n"
"selection-background-color: rgba(255, 255, 255, 0);\n"
"background-color: rgb(243, 188, 46);\n"
"\n"
"border: 0px;"));
        comboBox->setFrame(false);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(250, 80, 111, 31));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 10pt \"Consolas\";\n"
"border: 3px solid black;\n"
"border-radius: 8px;\n"
""));
        pushButton_save = new QPushButton(frame);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        pushButton_save->setGeometry(QRect(440, 510, 81, 41));
        pushButton_save->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_save->setStyleSheet(QString::fromUtf8("color: rgb(50, 50, 50);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 2px solid rgb(50, 50, 50);\n"
"border-radius:  13px; \n"
"font: 14pt \"Consolas\";"));
        pushButton_save->setAutoDefault(false);
        pushButton_save->setFlat(true);
        pushButton_edit = new QPushButton(frame);
        pushButton_edit->setObjectName(QString::fromUtf8("pushButton_edit"));
        pushButton_edit->setGeometry(QRect(340, 510, 81, 41));
        pushButton_edit->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_edit->setStyleSheet(QString::fromUtf8("color: rgb(50, 50, 50);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 2px solid rgb(50, 50, 50);\n"
"border-radius:  13px; \n"
"font: 14pt \"Consolas\";"));
        pushButton_edit->setAutoDefault(false);
        pushButton_edit->setFlat(true);
        comboBox->raise();
        pushButton->raise();
        pushButton_save->raise();
        pushButton_edit->raise();
        label_accountAlert->raise();
        label_pwdAlert->raise();
        label_phoneAlert->raise();
        label_birthday = new QLabel(page_account);
        label_birthday->setObjectName(QString::fromUtf8("label_birthday"));
        label_birthday->setGeometry(QRect(250, 460, 121, 31));
        label_birthday->setStyleSheet(QString::fromUtf8("font: 14pt \"Consolas\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(50, 50, 50);"));
        stackedWidget->addWidget(page_account);
        frame->raise();
        lineEdit_phone->raise();
        comboBox_gender->raise();
        label_username_3->raise();
        photo_2->raise();
        lineEdit_account->raise();
        label_username_5->raise();
        label_username_2->raise();
        label_username_6->raise();
        label_username_4->raise();
        lineEdit_username->raise();
        lineEdit_editPWD->raise();
        label_birthday->raise();
        label_usernameAlert->raise();
        page_orders = new QWidget();
        page_orders->setObjectName(QString::fromUtf8("page_orders"));
        frame_2 = new QFrame(page_orders);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(20, 10, 861, 571));
        frame_2->setStyleSheet(QString::fromUtf8("border: 3px solid white;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-radius: 13px;\n"
"font:  \"Consolas\";"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        tabWidget = new QTabWidget(frame_2);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 30, 841, 511));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Consolas")});
        font3.setPointSize(15);
        font3.setBold(false);
        font3.setItalic(false);
        tabWidget->setFont(font3);
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tabWidget->setStyleSheet(QString::fromUtf8("border: 0px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(50, 50, 50);\n"
"selection-background-color: rgb(38, 115, 154);\n"
"border-radius: 0px;\n"
""));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(30, 30));
        tabWidget->setElideMode(Qt::ElideMiddle);
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tabWidget->setTabBarAutoHide(false);
        placed = new QWidget();
        placed->setObjectName(QString::fromUtf8("placed"));
        tableWidget_1 = new QTableWidget(placed);
        tableWidget_1->setObjectName(QString::fromUtf8("tableWidget_1"));
        tableWidget_1->setGeometry(QRect(0, 0, 841, 471));
        tableWidget_1->setStyleSheet(QString::fromUtf8("font: 12pt \"Consolas\";\n"
"color: rgb(0, 0, 0);\n"
"border-radius: 0pt;\n"
"selection-background-color: rgb(191, 145, 51);\n"
"selection-color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
""));
        tableWidget_1->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        tableWidget_1->setSelectionBehavior(QAbstractItemView::SelectRows);
        tabWidget->addTab(placed, QString());
        toShip = new QWidget();
        toShip->setObjectName(QString::fromUtf8("toShip"));
        tableWidget_2 = new QTableWidget(toShip);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(0, 0, 841, 471));
        tableWidget_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Consolas\";\n"
"color: rgb(0, 0, 0);\n"
"border-radius: 0pt;\n"
"selection-background-color: rgb(191, 145, 51);\n"
"selection-color: rgb(0, 0, 0);"));
        tableWidget_2->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
        tabWidget->addTab(toShip, QString());
        arrived = new QWidget();
        arrived->setObjectName(QString::fromUtf8("arrived"));
        tableWidget_3 = new QTableWidget(arrived);
        tableWidget_3->setObjectName(QString::fromUtf8("tableWidget_3"));
        tableWidget_3->setGeometry(QRect(0, 0, 841, 471));
        tableWidget_3->setStyleSheet(QString::fromUtf8("font: 12pt \"Consolas\";\n"
"color: rgb(0, 0, 0);\n"
"border-radius: 0pt;\n"
"selection-background-color: rgb(191, 145, 51);\n"
"selection-color: rgb(0, 0, 0);"));
        tableWidget_3->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        tableWidget_3->setSelectionBehavior(QAbstractItemView::SelectRows);
        tabWidget->addTab(arrived, QString());
        toRate = new QWidget();
        toRate->setObjectName(QString::fromUtf8("toRate"));
        tableWidget_4 = new QTableWidget(toRate);
        tableWidget_4->setObjectName(QString::fromUtf8("tableWidget_4"));
        tableWidget_4->setGeometry(QRect(0, 0, 841, 471));
        tableWidget_4->setStyleSheet(QString::fromUtf8("font: 12pt \"Consolas\";\n"
"color: rgb(0, 0, 0);\n"
"border-radius: 0pt;\n"
"selection-background-color: rgb(191, 145, 51);\n"
"selection-color: rgb(0, 0, 0);"));
        tableWidget_4->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        tableWidget_4->setSelectionBehavior(QAbstractItemView::SelectRows);
        tabWidget->addTab(toRate, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tableWidget_5 = new QTableWidget(tab);
        tableWidget_5->setObjectName(QString::fromUtf8("tableWidget_5"));
        tableWidget_5->setGeometry(QRect(0, 0, 841, 471));
        tableWidget_5->setStyleSheet(QString::fromUtf8("font: 12pt \"Consolas\";\n"
"color: rgb(0, 0, 0);\n"
"border-radius: 0pt;\n"
"selection-background-color: rgb(191, 145, 51);\n"
"selection-color: rgb(0, 0, 0);"));
        tableWidget_5->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        tableWidget_5->setSelectionBehavior(QAbstractItemView::SelectRows);
        tabWidget->addTab(tab, QString());
        canceled = new QWidget();
        canceled->setObjectName(QString::fromUtf8("canceled"));
        tableWidget_6 = new QTableWidget(canceled);
        tableWidget_6->setObjectName(QString::fromUtf8("tableWidget_6"));
        tableWidget_6->setGeometry(QRect(0, 0, 841, 471));
        tableWidget_6->setStyleSheet(QString::fromUtf8("font: 12pt \"Consolas\";\n"
"color: rgb(0, 0, 0);\n"
"border-radius: 0pt;\n"
"selection-background-color: rgb(191, 145, 51);\n"
"selection-color: rgb(0, 0, 0);"));
        tableWidget_6->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        tableWidget_6->setSelectionBehavior(QAbstractItemView::SelectRows);
        tabWidget->addTab(canceled, QString());
        stackedWidget->addWidget(page_orders);
        mymarket = new QPushButton(centralwidget);
        mymarket->setObjectName(QString::fromUtf8("mymarket"));
        mymarket->setGeometry(QRect(70, 600, 141, 41));
        mymarket->setStyleSheet(QString::fromUtf8("background-color: rgb(38, 115, 154);\n"
"border-radius: 13px;\n"
"color: rgb(255, 255, 255);\n"
"font: 14pt \"Consolas\";\n"
""));
        mymarket->setFlat(true);
        home = new QPushButton(centralwidget);
        home->setObjectName(QString::fromUtf8("home"));
        home->setGeometry(QRect(60, 20, 171, 61));
        home->setStyleSheet(QString::fromUtf8("color: rgb(50, 50, 50);\n"
"font: 25pt \"Impact\";"));
        home->setFlat(true);
        back = new QPushButton(centralwidget);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(80, 370, 111, 31));
        back->setStyleSheet(QString::fromUtf8("/*image: url(./img/backarrow.png);*/\n"
"\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 13px;\n"
"color: black;\n"
"font: 12pt \"Consolas\";"));
        back->setFlat(true);
        UserInterface->setCentralWidget(centralwidget);
        line->raise();
        photo->raise();
        username->raise();
        pushButton_myaccount->raise();
        pushButton_myorders->raise();
        stackedWidget->raise();
        line_2->raise();
        mymarket->raise();
        home->raise();
        back->raise();
        menubar = new QMenuBar(UserInterface);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 21));
        UserInterface->setMenuBar(menubar);
        statusbar = new QStatusBar(UserInterface);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        UserInterface->setStatusBar(statusbar);

        retranslateUi(UserInterface);

        pushButton_myaccount->setDefault(false);
        stackedWidget->setCurrentIndex(1);
        pushButton->setDefault(true);
        tabWidget->setCurrentIndex(0);
        mymarket->setDefault(false);
        back->setDefault(false);


        QMetaObject::connectSlotsByName(UserInterface);
    } // setupUi

    void retranslateUi(QMainWindow *UserInterface)
    {
        UserInterface->setWindowTitle(QCoreApplication::translate("UserInterface", "MainWindow", nullptr));
        photo->setText(QString());
        username->setText(QCoreApplication::translate("UserInterface", "USERNAME", nullptr));
        pushButton_myaccount->setText(QCoreApplication::translate("UserInterface", "MY ACCOUNT", nullptr));
        pushButton_myorders->setText(QCoreApplication::translate("UserInterface", "MY ORDERS", nullptr));
        lineEdit_phone->setPlaceholderText(QCoreApplication::translate("UserInterface", "Phone", nullptr));
        comboBox_gender->setItemText(0, QCoreApplication::translate("UserInterface", "Male", nullptr));
        comboBox_gender->setItemText(1, QCoreApplication::translate("UserInterface", "Female", nullptr));
        comboBox_gender->setItemText(2, QCoreApplication::translate("UserInterface", "Other", nullptr));

        label_username_3->setText(QCoreApplication::translate("UserInterface", "Phone:", nullptr));
        photo_2->setText(QString());
        lineEdit_account->setText(QString());
        lineEdit_account->setPlaceholderText(QCoreApplication::translate("UserInterface", "Account", nullptr));
        label_username_5->setText(QCoreApplication::translate("UserInterface", "Birthday:", nullptr));
        label_username_2->setText(QCoreApplication::translate("UserInterface", "Account:", nullptr));
        label_username_6->setText(QCoreApplication::translate("UserInterface", "Password:", nullptr));
        label_username_4->setText(QCoreApplication::translate("UserInterface", "Gender:", nullptr));
        lineEdit_username->setText(QString());
        lineEdit_username->setPlaceholderText(QCoreApplication::translate("UserInterface", "Username", nullptr));
        lineEdit_editPWD->setText(QString());
        lineEdit_editPWD->setPlaceholderText(QCoreApplication::translate("UserInterface", "Password", nullptr));
        label_usernameAlert->setText(QString());
        label_accountAlert->setText(QString());
        label_pwdAlert->setText(QString());
        label_phoneAlert->setText(QString());
        comboBox->setItemText(0, QCoreApplication::translate("UserInterface", "@nycu.edu.tw", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("UserInterface", "@gmail.com", nullptr));

        pushButton->setText(QCoreApplication::translate("UserInterface", "change photo", nullptr));
        pushButton_save->setText(QCoreApplication::translate("UserInterface", "Save", nullptr));
        pushButton_edit->setText(QCoreApplication::translate("UserInterface", "Edit", nullptr));
        label_birthday->setText(QCoreApplication::translate("UserInterface", "Birthday", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(placed), QCoreApplication::translate("UserInterface", "Placed", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(toShip), QCoreApplication::translate("UserInterface", "Shipping", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(arrived), QCoreApplication::translate("UserInterface", "Arrived", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(toRate), QCoreApplication::translate("UserInterface", "To Rate", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("UserInterface", "Completed", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(canceled), QCoreApplication::translate("UserInterface", "Canceled", nullptr));
        mymarket->setText(QCoreApplication::translate("UserInterface", "My Market", nullptr));
        home->setText(QCoreApplication::translate("UserInterface", "InsToCart", nullptr));
        back->setText(QCoreApplication::translate("UserInterface", "LOGOUT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserInterface: public Ui_UserInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINTERFACE_H
