/********************************************************************************
** Form generated from reading UI file 'personal_setting.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONAL_SETTING_H
#define UI_PERSONAL_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_personal_setting
{
public:
    QGraphicsView *foreground;
    QLabel *label_signup;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_phone;
    QComboBox *comboBox_gender;
    QDateEdit *dateEdit_birthday;
    QLabel *label;
    QPushButton *pushButton_back;
    QTextBrowser *textBrowser_alert;
    QPushButton *pushButton_finish;

    void setupUi(QDialog *personal_setting)
    {
        if (personal_setting->objectName().isEmpty())
            personal_setting->setObjectName(QString::fromUtf8("personal_setting"));
        personal_setting->resize(1200, 720);
        personal_setting->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 188, 46);"));
        foreground = new QGraphicsView(personal_setting);
        foreground->setObjectName(QString::fromUtf8("foreground"));
        foreground->setEnabled(false);
        foreground->setGeometry(QRect(300, 180, 600, 360));
        foreground->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 40);\n"
"border-radius:  20px; "));
        label_signup = new QLabel(personal_setting);
        label_signup->setObjectName(QString::fromUtf8("label_signup"));
        label_signup->setGeometry(QRect(350, 240, 241, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("Consolas")});
        font.setPointSize(40);
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
        lineEdit_name = new QLineEdit(personal_setting);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(360, 320, 231, 36));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Consolas")});
        font1.setPointSize(14);
        lineEdit_name->setFont(font1);
        lineEdit_name->setStyleSheet(QString::fromUtf8("border-radius:  10px; \n"
"background-color: rgb(255, 255, 255);\n"
"\n"
"color: rgb(127, 127, 127);"));
        lineEdit_name->setAlignment(Qt::AlignCenter);
        lineEdit_phone = new QLineEdit(personal_setting);
        lineEdit_phone->setObjectName(QString::fromUtf8("lineEdit_phone"));
        lineEdit_phone->setGeometry(QRect(670, 320, 181, 36));
        lineEdit_phone->setFont(font1);
        lineEdit_phone->setStyleSheet(QString::fromUtf8("border-radius:  10px; \n"
"background-color: rgb(255, 255, 255);\n"
"\n"
"color: rgb(127, 127, 127);"));
        lineEdit_phone->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        comboBox_gender = new QComboBox(personal_setting);
        comboBox_gender->addItem(QString());
        comboBox_gender->addItem(QString());
        comboBox_gender->addItem(QString());
        comboBox_gender->setObjectName(QString::fromUtf8("comboBox_gender"));
        comboBox_gender->setGeometry(QRect(360, 380, 231, 36));
        comboBox_gender->setFont(font1);
        comboBox_gender->setStyleSheet(QString::fromUtf8("border-radius:  10px; \n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(127, 127, 127);"));
        dateEdit_birthday = new QDateEdit(personal_setting);
        dateEdit_birthday->setObjectName(QString::fromUtf8("dateEdit_birthday"));
        dateEdit_birthday->setGeometry(QRect(620, 380, 231, 36));
        dateEdit_birthday->setFont(font1);
        dateEdit_birthday->setStyleSheet(QString::fromUtf8("border-radius:  10px; \n"
"background-color: rgb(255, 255, 255);\n"
"\n"
"color: rgb(127, 127, 127);"));
        dateEdit_birthday->setAlignment(Qt::AlignCenter);
        label = new QLabel(personal_setting);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(620, 320, 51, 36));
        label->setStyleSheet(QString::fromUtf8("font: 13pt \"Consolas\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 0);"));
        pushButton_back = new QPushButton(personal_setting);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));
        pushButton_back->setGeometry(QRect(320, 200, 61, 41));
        pushButton_back->setStyleSheet(QString::fromUtf8("image: url(:/back arrow.png);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        pushButton_back->setFlat(true);
        textBrowser_alert = new QTextBrowser(personal_setting);
        textBrowser_alert->setObjectName(QString::fromUtf8("textBrowser_alert"));
        textBrowser_alert->setGeometry(QRect(360, 440, 341, 81));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Consolas")});
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setItalic(false);
        textBrowser_alert->setFont(font2);
        textBrowser_alert->setStyleSheet(QString::fromUtf8("font: 11pt \"Consolas\";\n"
"color: rgb(64, 64, 64);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"border: 3px;\n"
"\n"
""));
        pushButton_finish = new QPushButton(personal_setting);
        pushButton_finish->setObjectName(QString::fromUtf8("pushButton_finish"));
        pushButton_finish->setGeometry(QRect(740, 480, 121, 41));
        pushButton_finish->setFont(font1);
        pushButton_finish->setFocusPolicy(Qt::ClickFocus);
        pushButton_finish->setAutoFillBackground(false);
        pushButton_finish->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 2px solid white;\n"
"border-radius:  15px; "));
        pushButton_finish->setIconSize(QSize(20, 20));
        pushButton_finish->setAutoDefault(false);
        pushButton_finish->setFlat(true);
        QWidget::setTabOrder(lineEdit_name, lineEdit_phone);
        QWidget::setTabOrder(lineEdit_phone, comboBox_gender);
        QWidget::setTabOrder(comboBox_gender, dateEdit_birthday);
        QWidget::setTabOrder(dateEdit_birthday, foreground);
        QWidget::setTabOrder(foreground, pushButton_back);
        QWidget::setTabOrder(pushButton_back, textBrowser_alert);

        retranslateUi(personal_setting);

        pushButton_finish->setDefault(false);


        QMetaObject::connectSlotsByName(personal_setting);
    } // setupUi

    void retranslateUi(QDialog *personal_setting)
    {
        personal_setting->setWindowTitle(QCoreApplication::translate("personal_setting", "Dialog", nullptr));
        label_signup->setText(QCoreApplication::translate("personal_setting", "SIGN UP", nullptr));
        lineEdit_name->setPlaceholderText(QCoreApplication::translate("personal_setting", "NAME", nullptr));
        lineEdit_phone->setPlaceholderText(QCoreApplication::translate("personal_setting", "PHONE", nullptr));
        comboBox_gender->setItemText(0, QCoreApplication::translate("personal_setting", "Male", nullptr));
        comboBox_gender->setItemText(1, QCoreApplication::translate("personal_setting", "Female", nullptr));
        comboBox_gender->setItemText(2, QCoreApplication::translate("personal_setting", "Other", nullptr));

        label->setText(QCoreApplication::translate("personal_setting", "+886|", nullptr));
        pushButton_back->setText(QString());
        pushButton_finish->setText(QCoreApplication::translate("personal_setting", "FINISH", nullptr));
    } // retranslateUi

};

namespace Ui {
    class personal_setting: public Ui_personal_setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONAL_SETTING_H
