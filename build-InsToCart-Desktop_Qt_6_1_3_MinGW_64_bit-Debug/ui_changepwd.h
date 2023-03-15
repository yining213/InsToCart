/********************************************************************************
** Form generated from reading UI file 'changepwd.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPWD_H
#define UI_CHANGEPWD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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

class Ui_ChangePWD
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit_password1;
    QLabel *label_title;
    QGraphicsView *foreground;
    QPushButton *pushButton_next;
    QLineEdit *lineEdit_password2;
    QLabel *label_2;
    QLabel *label;
    QTextBrowser *textBrowser_alert;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChangePWD)
    {
        if (ChangePWD->objectName().isEmpty())
            ChangePWD->setObjectName(QString::fromUtf8("ChangePWD"));
        ChangePWD->resize(1200, 720);
        ChangePWD->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 188, 46);"));
        centralwidget = new QWidget(ChangePWD);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lineEdit_password1 = new QLineEdit(centralwidget);
        lineEdit_password1->setObjectName(QString::fromUtf8("lineEdit_password1"));
        lineEdit_password1->setGeometry(QRect(380, 310, 291, 36));
        QFont font;
        font.setFamilies({QString::fromUtf8("Consolas")});
        font.setPointSize(14);
        lineEdit_password1->setFont(font);
        lineEdit_password1->setStyleSheet(QString::fromUtf8("border-radius:  10px; \n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(127, 127, 127);\n"
"\n"
"selection-background-color: rgb(170, 0, 0);\n"
""));
        lineEdit_password1->setEchoMode(QLineEdit::Password);
        lineEdit_password1->setAlignment(Qt::AlignCenter);
        label_title = new QLabel(centralwidget);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setGeometry(QRect(400, 220, 411, 71));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Consolas")});
        font1.setPointSize(32);
        font1.setBold(false);
        font1.setUnderline(false);
        font1.setKerning(true);
        label_title->setFont(font1);
        label_title->setAutoFillBackground(false);
        label_title->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        label_title->setFrameShape(QFrame::NoFrame);
        label_title->setTextFormat(Qt::AutoText);
        label_title->setScaledContents(false);
        label_title->setAlignment(Qt::AlignCenter);
        label_title->setMargin(0);
        foreground = new QGraphicsView(centralwidget);
        foreground->setObjectName(QString::fromUtf8("foreground"));
        foreground->setEnabled(false);
        foreground->setGeometry(QRect(300, 180, 600, 360));
        foreground->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 40);\n"
"border-radius:  20px; "));
        pushButton_next = new QPushButton(centralwidget);
        pushButton_next->setObjectName(QString::fromUtf8("pushButton_next"));
        pushButton_next->setGeometry(QRect(740, 460, 111, 41));
        pushButton_next->setFont(font);
        pushButton_next->setFocusPolicy(Qt::ClickFocus);
        pushButton_next->setAutoFillBackground(false);
        pushButton_next->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 2px solid white;\n"
"border-radius:  15px; "));
        pushButton_next->setIconSize(QSize(20, 20));
        pushButton_next->setAutoDefault(false);
        pushButton_next->setFlat(true);
        lineEdit_password2 = new QLineEdit(centralwidget);
        lineEdit_password2->setObjectName(QString::fromUtf8("lineEdit_password2"));
        lineEdit_password2->setGeometry(QRect(380, 360, 291, 36));
        lineEdit_password2->setFont(font);
        lineEdit_password2->setStyleSheet(QString::fromUtf8("border-radius:  10px; \n"
"background-color: rgb(255, 255, 255);\n"
"\n"
"color: rgb(127, 127, 127);"));
        lineEdit_password2->setEchoMode(QLineEdit::Password);
        lineEdit_password2->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(690, 350, 171, 36));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Consolas")});
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setItalic(false);
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("border-radius:  12px; \n"
"background-color: rgb(255, 255, 255,0);\n"
"color: rgb(255, 255, 255);\n"
"font: 10pt \"Consolas\";"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(690, 320, 161, 36));
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("border-radius:  12px; \n"
"background-color: rgb(255, 255, 255,0);\n"
"color: rgb(255, 255, 255);\n"
"font: 10pt \"Consolas\";"));
        textBrowser_alert = new QTextBrowser(centralwidget);
        textBrowser_alert->setObjectName(QString::fromUtf8("textBrowser_alert"));
        textBrowser_alert->setGeometry(QRect(380, 420, 331, 81));
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
        ChangePWD->setCentralWidget(centralwidget);
        foreground->raise();
        lineEdit_password1->raise();
        label_title->raise();
        pushButton_next->raise();
        lineEdit_password2->raise();
        label_2->raise();
        label->raise();
        textBrowser_alert->raise();
        menubar = new QMenuBar(ChangePWD);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 22));
        ChangePWD->setMenuBar(menubar);
        statusbar = new QStatusBar(ChangePWD);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ChangePWD->setStatusBar(statusbar);

        retranslateUi(ChangePWD);

        pushButton_next->setDefault(false);


        QMetaObject::connectSlotsByName(ChangePWD);
    } // setupUi

    void retranslateUi(QMainWindow *ChangePWD)
    {
        ChangePWD->setWindowTitle(QCoreApplication::translate("ChangePWD", "MainWindow", nullptr));
        lineEdit_password1->setText(QString());
        lineEdit_password1->setPlaceholderText(QCoreApplication::translate("ChangePWD", "PASSWORD", nullptr));
        label_title->setText(QCoreApplication::translate("ChangePWD", "CHANGE PASSWORD", nullptr));
        pushButton_next->setText(QCoreApplication::translate("ChangePWD", "FINISH", nullptr));
        lineEdit_password2->setText(QString());
        lineEdit_password2->setPlaceholderText(QCoreApplication::translate("ChangePWD", "COMFIRM PASSWORD", nullptr));
        label_2->setText(QCoreApplication::translate("ChangePWD", "at least 1 digit", nullptr));
        label->setText(QCoreApplication::translate("ChangePWD", "8~15 characters", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangePWD: public Ui_ChangePWD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPWD_H
