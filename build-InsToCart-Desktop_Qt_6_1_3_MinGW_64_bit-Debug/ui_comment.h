/********************************************************************************
** Form generated from reading UI file 'comment.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMENT_H
#define UI_COMMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Comment
{
public:
    QTableWidget *table;
    QLabel *label;
    QPushButton *save;

    void setupUi(QDialog *Comment)
    {
        if (Comment->objectName().isEmpty())
            Comment->setObjectName(QString::fromUtf8("Comment"));
        Comment->resize(645, 390);
        table = new QTableWidget(Comment);
        table->setObjectName(QString::fromUtf8("table"));
        table->setGeometry(QRect(50, 70, 541, 241));
        table->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 12pt \"Consolas\";\n"
"background-color: rgb(255, 255, 255);"));
        label = new QLabel(Comment);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 30, 211, 31));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"Consolas\";\n"
"color: rgb(0, 0, 0);"));
        label->setAlignment(Qt::AlignCenter);
        save = new QPushButton(Comment);
        save->setObjectName(QString::fromUtf8("save"));
        save->setGeometry(QRect(270, 330, 91, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Consolas")});
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        save->setFont(font);
        save->setFocusPolicy(Qt::ClickFocus);
        save->setAutoFillBackground(false);
        save->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 2px solid black;\n"
"border-radius:  15px; "));
        save->setIconSize(QSize(20, 20));
        save->setAutoDefault(false);
        save->setFlat(true);

        retranslateUi(Comment);

        save->setDefault(false);


        QMetaObject::connectSlotsByName(Comment);
    } // setupUi

    void retranslateUi(QDialog *Comment)
    {
        Comment->setWindowTitle(QCoreApplication::translate("Comment", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Comment", "LEAVE A COMMENT", nullptr));
        save->setText(QCoreApplication::translate("Comment", "SAVE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Comment: public Ui_Comment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMENT_H
