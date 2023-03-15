/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_signup
{
public:
    QLabel *label_signup;
    QPushButton *pushButton_next;
    QLineEdit *lineEdit_account;
    QGraphicsView *foreground;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton_back;
    QComboBox *comboBox;
    QLabel *label;
    QLabel *label_2;
    QTextBrowser *textBrowser_alert;

    void setupUi(QDialog *signup)
    {
        if (signup->objectName().isEmpty())
            signup->setObjectName(QString::fromUtf8("signup"));
        signup->resize(1200, 720);
        signup->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 188, 46);"));
        label_signup = new QLabel(signup);
        label_signup->setObjectName(QString::fromUtf8("label_signup"));
        label_signup->setGeometry(QRect(455, 240, 290, 60));
        QFont font;
        font.setFamilies({QString::fromUtf8("Consolas")});
        font.setPointSize(48);
        font.setBold(false);
        font.setUnderline(false);
        font.setKerning(true);
        label_signup->setFont(font);
        label_signup->setAutoFillBackground(false);
        label_signup->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        label_signup->setFrameShape(QFrame::NoFrame);
        label_signup->setTextFormat(Qt::AutoText);
        label_signup->setScaledContents(false);
        label_signup->setAlignment(Qt::AlignCenter);
        label_signup->setMargin(0);
        pushButton_next = new QPushButton(signup);
        pushButton_next->setObjectName(QString::fromUtf8("pushButton_next"));
        pushButton_next->setGeometry(QRect(760, 480, 101, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Consolas")});
        font1.setPointSize(14);
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
        lineEdit_account = new QLineEdit(signup);
        lineEdit_account->setObjectName(QString::fromUtf8("lineEdit_account"));
        lineEdit_account->setGeometry(QRect(380, 332, 271, 36));
        lineEdit_account->setFont(font1);
        lineEdit_account->setStyleSheet(QString::fromUtf8("border-radius:  10px; \n"
"background-color: rgb(255, 255, 255);\n"
"\n"
"color: rgb(127, 127, 127);"));
        lineEdit_account->setAlignment(Qt::AlignCenter);
        foreground = new QGraphicsView(signup);
        foreground->setObjectName(QString::fromUtf8("foreground"));
        foreground->setEnabled(false);
        foreground->setGeometry(QRect(300, 180, 600, 360));
        foreground->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 40);\n"
"border-radius:  20px; "));
        lineEdit_password = new QLineEdit(signup);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(380, 390, 271, 36));
        lineEdit_password->setFont(font1);
        lineEdit_password->setStyleSheet(QString::fromUtf8("border-radius:  10px; \n"
"background-color: rgb(255, 255, 255);\n"
"\n"
"color: rgb(127, 127, 127);"));
        lineEdit_password->setEchoMode(QLineEdit::Password);
        lineEdit_password->setAlignment(Qt::AlignCenter);
        pushButton_back = new QPushButton(signup);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));
        pushButton_back->setGeometry(QRect(320, 200, 61, 41));
        pushButton_back->setStyleSheet(QString::fromUtf8("image: url(:/back arrow.png);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        pushButton_back->setFlat(true);
        comboBox = new QComboBox(signup);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(660, 332, 151, 36));
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
        label = new QLabel(signup);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(670, 380, 161, 36));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Consolas")});
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setItalic(false);
        label->setFont(font3);
        label->setStyleSheet(QString::fromUtf8("border-radius:  12px; \n"
"background-color: rgb(255, 255, 255,0);\n"
"color: rgb(255, 255, 255);\n"
"font: 10pt \"Consolas\";"));
        label_2 = new QLabel(signup);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(670, 400, 171, 36));
        label_2->setFont(font3);
        label_2->setStyleSheet(QString::fromUtf8("border-radius:  12px; \n"
"background-color: rgb(255, 255, 255,0);\n"
"color: rgb(255, 255, 255);\n"
"font: 10pt \"Consolas\";"));
        textBrowser_alert = new QTextBrowser(signup);
        textBrowser_alert->setObjectName(QString::fromUtf8("textBrowser_alert"));
        textBrowser_alert->setGeometry(QRect(380, 440, 361, 81));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Consolas")});
        font4.setPointSize(11);
        font4.setBold(false);
        font4.setItalic(false);
        textBrowser_alert->setFont(font4);
        textBrowser_alert->setStyleSheet(QString::fromUtf8("font: 11pt \"Consolas\";\n"
"color: rgb(64, 64, 64);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"border: 3px;\n"
"\n"
""));
        foreground->raise();
        label_signup->raise();
        lineEdit_account->raise();
        pushButton_next->raise();
        lineEdit_password->raise();
        pushButton_back->raise();
        comboBox->raise();
        label->raise();
        label_2->raise();
        textBrowser_alert->raise();

        retranslateUi(signup);

        pushButton_next->setDefault(false);


        QMetaObject::connectSlotsByName(signup);
    } // setupUi

    void retranslateUi(QDialog *signup)
    {
        signup->setWindowTitle(QCoreApplication::translate("signup", "Dialog", nullptr));
        label_signup->setText(QCoreApplication::translate("signup", "SIGN UP", nullptr));
        pushButton_next->setText(QCoreApplication::translate("signup", "NEXT", nullptr));
        lineEdit_account->setPlaceholderText(QCoreApplication::translate("signup", "EMAIL", nullptr));
        lineEdit_password->setPlaceholderText(QCoreApplication::translate("signup", "PASSWORD", nullptr));
        pushButton_back->setText(QString());
        comboBox->setItemText(0, QCoreApplication::translate("signup", "@nycu.edu.tw", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("signup", "@gmail.com", nullptr));

        label->setText(QCoreApplication::translate("signup", "8~15 characters", nullptr));
        label_2->setText(QCoreApplication::translate("signup", "at least 1 digit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signup: public Ui_signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
