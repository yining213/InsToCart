/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_login;
    QPushButton *pushButton_signup;
    QPushButton *pushButton_forgetPWD;
    QLineEdit *lineEdit_account;
    QPushButton *pushButton;
    QLabel *label_prompt;
    QLineEdit *lineEdit_password;
    QComboBox *comboBox;
    QGraphicsView *foreground;
    QPushButton *dist;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1200, 720);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 188, 46);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_login = new QLabel(centralwidget);
        label_login->setObjectName(QString::fromUtf8("label_login"));
        label_login->setGeometry(QRect(410, 230, 371, 60));
        QFont font;
        font.setFamilies({QString::fromUtf8("Consolas")});
        font.setPointSize(48);
        font.setBold(false);
        font.setUnderline(false);
        font.setKerning(true);
        label_login->setFont(font);
        label_login->setAutoFillBackground(false);
        label_login->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        label_login->setFrameShape(QFrame::NoFrame);
        label_login->setTextFormat(Qt::AutoText);
        label_login->setScaledContents(false);
        label_login->setAlignment(Qt::AlignCenter);
        label_login->setMargin(0);
        pushButton_signup = new QPushButton(centralwidget);
        pushButton_signup->setObjectName(QString::fromUtf8("pushButton_signup"));
        pushButton_signup->setGeometry(QRect(770, 460, 91, 21));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Consolas")});
        font1.setPointSize(12);
        pushButton_signup->setFont(font1);
        pushButton_signup->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_signup->setFlat(true);
        pushButton_forgetPWD = new QPushButton(centralwidget);
        pushButton_forgetPWD->setObjectName(QString::fromUtf8("pushButton_forgetPWD"));
        pushButton_forgetPWD->setGeometry(QRect(700, 490, 161, 20));
        pushButton_forgetPWD->setFont(font1);
        pushButton_forgetPWD->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_forgetPWD->setFlat(true);
        lineEdit_account = new QLineEdit(centralwidget);
        lineEdit_account->setObjectName(QString::fromUtf8("lineEdit_account"));
        lineEdit_account->setGeometry(QRect(420, 320, 201, 36));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Consolas")});
        font2.setPointSize(14);
        lineEdit_account->setFont(font2);
        lineEdit_account->setStyleSheet(QString::fromUtf8("border-radius:  10px; \n"
"background-color: rgb(255, 255, 255);\n"
"\n"
"color: rgb(127, 127, 127);"));
        lineEdit_account->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(550, 460, 101, 41));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Consolas")});
        font3.setPointSize(14);
        font3.setKerning(true);
        pushButton->setFont(font3);
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 2px solid white;\n"
"border-radius:  15px; "));
        pushButton->setAutoDefault(false);
        pushButton->setFlat(true);
        label_prompt = new QLabel(centralwidget);
        label_prompt->setObjectName(QString::fromUtf8("label_prompt"));
        label_prompt->setGeometry(QRect(450, 420, 300, 30));
        label_prompt->setFont(font1);
        label_prompt->setStyleSheet(QString::fromUtf8("color: rgb(64, 64, 64);\n"
"selection-color: rgba(255, 255, 255, 0);\n"
"background-color: rgba(255, 255, 255, 0);"));
        label_prompt->setFrameShape(QFrame::NoFrame);
        label_prompt->setAlignment(Qt::AlignCenter);
        lineEdit_password = new QLineEdit(centralwidget);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(420, 370, 360, 36));
        lineEdit_password->setFont(font2);
        lineEdit_password->setStyleSheet(QString::fromUtf8("border-radius:  10px; \n"
"background-color: rgb(255, 255, 255);\n"
"\n"
"color: rgb(127, 127, 127);"));
        lineEdit_password->setEchoMode(QLineEdit::Password);
        lineEdit_password->setAlignment(Qt::AlignCenter);
        lineEdit_password->setClearButtonEnabled(false);
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(630, 320, 151, 36));
        comboBox->setFont(font1);
        comboBox->setAutoFillBackground(false);
        comboBox->setStyleSheet(QString::fromUtf8("border-radius:  10px; \n"
"color: rgb(255, 255, 255);\n"
"selection-background-color: rgba(255, 255, 255, 0);\n"
"background-color: rgba(0, 0, 0, 0);"));
        comboBox->setFrame(false);
        foreground = new QGraphicsView(centralwidget);
        foreground->setObjectName(QString::fromUtf8("foreground"));
        foreground->setEnabled(true);
        foreground->setGeometry(QRect(315, 190, 570, 340));
        foreground->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 40);\n"
"border-radius:  20px; "));
        dist = new QPushButton(centralwidget);
        dist->setObjectName(QString::fromUtf8("dist"));
        dist->setGeometry(QRect(340, 470, 121, 41));
        dist->setFont(font1);
        dist->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        dist->setFlat(true);
        MainWindow->setCentralWidget(centralwidget);
        foreground->raise();
        pushButton_forgetPWD->raise();
        pushButton_signup->raise();
        lineEdit_account->raise();
        pushButton->raise();
        label_prompt->raise();
        label_login->raise();
        lineEdit_password->raise();
        comboBox->raise();
        dist->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(lineEdit_account, lineEdit_password);
        QWidget::setTabOrder(lineEdit_password, pushButton);
        QWidget::setTabOrder(pushButton, pushButton_signup);
        QWidget::setTabOrder(pushButton_signup, pushButton_forgetPWD);
        QWidget::setTabOrder(pushButton_forgetPWD, comboBox);
        QWidget::setTabOrder(comboBox, foreground);

        retranslateUi(MainWindow);

        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_login->setText(QCoreApplication::translate("MainWindow", "InsToCart", nullptr));
        pushButton_signup->setText(QCoreApplication::translate("MainWindow", "SIGN UP", nullptr));
        pushButton_forgetPWD->setText(QCoreApplication::translate("MainWindow", "FORGET PASSWORD", nullptr));
        lineEdit_account->setPlaceholderText(QCoreApplication::translate("MainWindow", "ACCOUNT", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "ENTER", nullptr));
        label_prompt->setText(QCoreApplication::translate("MainWindow", "WELCOME", nullptr));
        lineEdit_password->setPlaceholderText(QCoreApplication::translate("MainWindow", "PASSWORD", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "@nycu.edu.tw", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "@gmail.com", nullptr));

        dist->setText(QCoreApplication::translate("MainWindow", "DISTRIBUTION\n"
"CENTER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
