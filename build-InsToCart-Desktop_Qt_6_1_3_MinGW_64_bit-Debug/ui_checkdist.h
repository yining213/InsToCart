/********************************************************************************
** Form generated from reading UI file 'checkdist.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKDIST_H
#define UI_CHECKDIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_checkDist
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *enter;
    QLabel *alert;

    void setupUi(QDialog *checkDist)
    {
        if (checkDist->objectName().isEmpty())
            checkDist->setObjectName(QString::fromUtf8("checkDist"));
        checkDist->resize(371, 165);
        lineEdit = new QLineEdit(checkDist);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(150, 30, 171, 31));
        lineEdit->setStyleSheet(QString::fromUtf8("font: 12pt \"Consolas\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        label = new QLabel(checkDist);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 101, 31));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"Consolas\";\n"
"color: rgb(0, 0, 0);"));
        label->setAlignment(Qt::AlignCenter);
        enter = new QPushButton(checkDist);
        enter->setObjectName(QString::fromUtf8("enter"));
        enter->setGeometry(QRect(140, 110, 91, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Consolas")});
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        enter->setFont(font);
        enter->setFocusPolicy(Qt::ClickFocus);
        enter->setAutoFillBackground(false);
        enter->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 2px solid black;\n"
"border-radius:  15px; "));
        enter->setIconSize(QSize(20, 20));
        enter->setAutoDefault(false);
        enter->setFlat(true);
        alert = new QLabel(checkDist);
        alert->setObjectName(QString::fromUtf8("alert"));
        alert->setGeometry(QRect(130, 70, 101, 31));
        alert->setStyleSheet(QString::fromUtf8("font: 12pt \"Consolas\";\n"
"color: rgb(0, 0, 0);"));
        alert->setAlignment(Qt::AlignCenter);

        retranslateUi(checkDist);

        enter->setDefault(false);


        QMetaObject::connectSlotsByName(checkDist);
    } // setupUi

    void retranslateUi(QDialog *checkDist)
    {
        checkDist->setWindowTitle(QCoreApplication::translate("checkDist", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("checkDist", "PASS ID", nullptr));
        enter->setText(QCoreApplication::translate("checkDist", "ENTER", nullptr));
        alert->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class checkDist: public Ui_checkDist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKDIST_H
