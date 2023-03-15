/********************************************************************************
** Form generated from reading UI file 'forgetpwd.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORGETPWD_H
#define UI_FORGETPWD_H

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
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ForgetPWD
{
public:
    QWidget *centralwidget;
    QGraphicsView *foreground;
    QLabel *label_title;
    QPushButton *pushButton_back;
    QLabel *label;
    QLineEdit *lineEdit_phone;
    QLineEdit *lineEdit_name;
    QComboBox *comboBox;
    QLineEdit *lineEdit_account;
    QPushButton *pushButton_next;
    QTextBrowser *textBrowser_alert;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ForgetPWD)
    {
        if (ForgetPWD->objectName().isEmpty())
            ForgetPWD->setObjectName(QString::fromUtf8("ForgetPWD"));
        ForgetPWD->resize(1200, 720);
        ForgetPWD->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 188, 46);"));
        centralwidget = new QWidget(ForgetPWD);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        foreground = new QGraphicsView(centralwidget);
        foreground->setObjectName(QString::fromUtf8("foreground"));
        foreground->setEnabled(false);
        foreground->setGeometry(QRect(300, 180, 600, 360));
        foreground->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 40);\n"
"border-radius:  20px; "));
        label_title = new QLabel(centralwidget);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setGeometry(QRect(400, 230, 411, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("Consolas")});
        font.setPointSize(32);
        font.setBold(false);
        font.setUnderline(false);
        font.setKerning(true);
        label_title->setFont(font);
        label_title->setAutoFillBackground(false);
        label_title->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        label_title->setFrameShape(QFrame::NoFrame);
        label_title->setTextFormat(Qt::AutoText);
        label_title->setScaledContents(false);
        label_title->setAlignment(Qt::AlignCenter);
        label_title->setMargin(0);
        pushButton_back = new QPushButton(centralwidget);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));
        pushButton_back->setGeometry(QRect(320, 200, 61, 41));
        pushButton_back->setStyleSheet(QString::fromUtf8("image: url(:/back arrow.png);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        pushButton_back->setFlat(true);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(620, 380, 51, 36));
        label->setStyleSheet(QString::fromUtf8("font: 13pt \"Consolas\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 0);"));
        lineEdit_phone = new QLineEdit(centralwidget);
        lineEdit_phone->setObjectName(QString::fromUtf8("lineEdit_phone"));
        lineEdit_phone->setGeometry(QRect(670, 380, 181, 36));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Consolas")});
        font1.setPointSize(14);
        lineEdit_phone->setFont(font1);
        lineEdit_phone->setStyleSheet(QString::fromUtf8("border-radius:  10px; \n"
"background-color: rgb(255, 255, 255);\n"
"\n"
"color: rgb(127, 127, 127);"));
        lineEdit_phone->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_name = new QLineEdit(centralwidget);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(370, 380, 231, 36));
        lineEdit_name->setFont(font1);
        lineEdit_name->setStyleSheet(QString::fromUtf8("border-radius:  10px; \n"
"background-color: rgb(255, 255, 255);\n"
"\n"
"color: rgb(127, 127, 127);"));
        lineEdit_name->setAlignment(Qt::AlignCenter);
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(670, 320, 151, 36));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Consolas")});
        font2.setPointSize(12);
        comboBox->setFont(font2);
        comboBox->setAutoFillBackground(false);
        comboBox->setStyleSheet(QString::fromUtf8("border-radius:  10px; \n"
"color: rgb(255, 255, 255);\n"
"selection-background-color: rgba(255, 255, 255, 0);\n"
"background-color: rgba(0, 0, 0, 0);"));
        comboBox->setFrame(false);
        lineEdit_account = new QLineEdit(centralwidget);
        lineEdit_account->setObjectName(QString::fromUtf8("lineEdit_account"));
        lineEdit_account->setGeometry(QRect(390, 320, 271, 36));
        lineEdit_account->setFont(font1);
        lineEdit_account->setStyleSheet(QString::fromUtf8("border-radius:  10px; \n"
"background-color: rgb(255, 255, 255);\n"
"\n"
"color: rgb(127, 127, 127);"));
        lineEdit_account->setAlignment(Qt::AlignCenter);
        pushButton_next = new QPushButton(centralwidget);
        pushButton_next->setObjectName(QString::fromUtf8("pushButton_next"));
        pushButton_next->setGeometry(QRect(760, 470, 101, 41));
        pushButton_next->setFont(font1);
        pushButton_next->setFocusPolicy(Qt::ClickFocus);
        pushButton_next->setAutoFillBackground(false);
        pushButton_next->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 2px solid white;\n"
"border-radius:  15px; "));
        pushButton_next->setIconSize(QSize(20, 20));
        pushButton_next->setAutoDefault(false);
        pushButton_next->setFlat(true);
        textBrowser_alert = new QTextBrowser(centralwidget);
        textBrowser_alert->setObjectName(QString::fromUtf8("textBrowser_alert"));
        textBrowser_alert->setGeometry(QRect(380, 440, 341, 81));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Consolas")});
        font3.setPointSize(11);
        font3.setBold(false);
        font3.setItalic(false);
        textBrowser_alert->setFont(font3);
        textBrowser_alert->setStyleSheet(QString::fromUtf8("font: 11pt \"Consolas\";\n"
"color: rgb(64, 64, 64);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"border: 3px;\n"
"\n"
""));
        ForgetPWD->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ForgetPWD);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 21));
        ForgetPWD->setMenuBar(menubar);
        statusbar = new QStatusBar(ForgetPWD);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ForgetPWD->setStatusBar(statusbar);

        retranslateUi(ForgetPWD);

        pushButton_next->setDefault(false);


        QMetaObject::connectSlotsByName(ForgetPWD);
    } // setupUi

    void retranslateUi(QMainWindow *ForgetPWD)
    {
        ForgetPWD->setWindowTitle(QCoreApplication::translate("ForgetPWD", "MainWindow", nullptr));
        label_title->setText(QCoreApplication::translate("ForgetPWD", "CHANGE PASSWORD", nullptr));
        pushButton_back->setText(QString());
        label->setText(QCoreApplication::translate("ForgetPWD", "+886|", nullptr));
        lineEdit_phone->setPlaceholderText(QCoreApplication::translate("ForgetPWD", "PHONE", nullptr));
        lineEdit_name->setPlaceholderText(QCoreApplication::translate("ForgetPWD", "NAME", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("ForgetPWD", "@nycu.edu.tw", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("ForgetPWD", "@gmail.com", nullptr));
        comboBox->setItemText(2, QString());

        lineEdit_account->setPlaceholderText(QCoreApplication::translate("ForgetPWD", "EMAIL", nullptr));
        pushButton_next->setText(QCoreApplication::translate("ForgetPWD", "NEXT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ForgetPWD: public Ui_ForgetPWD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORGETPWD_H
