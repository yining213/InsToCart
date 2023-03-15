/********************************************************************************
** Form generated from reading UI file 'enter_pwd.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTER_PWD_H
#define UI_ENTER_PWD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_enter_PWD
{
public:
    QGraphicsView *background;
    QPushButton *pushButton_enter;
    QLabel *label_account;
    QLabel *label_photo;
    QLineEdit *lineEdit_PWD;
    QGraphicsView *foreground;

    void setupUi(QDialog *enter_PWD)
    {
        if (enter_PWD->objectName().isEmpty())
            enter_PWD->setObjectName(QString::fromUtf8("enter_PWD"));
        enter_PWD->resize(1200, 720);
        background = new QGraphicsView(enter_PWD);
        background->setObjectName(QString::fromUtf8("background"));
        background->setGeometry(QRect(0, 0, 1200, 720));
        pushButton_enter = new QPushButton(enter_PWD);
        pushButton_enter->setObjectName(QString::fromUtf8("pushButton_enter"));
        pushButton_enter->setGeometry(QRect(545, 440, 111, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Consolas")});
        font.setPointSize(14);
        pushButton_enter->setFont(font);
        pushButton_enter->setFocusPolicy(Qt::ClickFocus);
        pushButton_enter->setAutoFillBackground(false);
        pushButton_enter->setIconSize(QSize(20, 20));
        pushButton_enter->setAutoDefault(false);
        pushButton_enter->setFlat(true);
        label_account = new QLabel(enter_PWD);
        label_account->setObjectName(QString::fromUtf8("label_account"));
        label_account->setGeometry(QRect(460, 320, 280, 30));
        label_account->setFont(font);
        label_account->setFocusPolicy(Qt::StrongFocus);
        label_account->setAutoFillBackground(false);
        label_account->setAlignment(Qt::AlignCenter);
        label_photo = new QLabel(enter_PWD);
        label_photo->setObjectName(QString::fromUtf8("label_photo"));
        label_photo->setGeometry(QRect(550, 200, 100, 100));
        lineEdit_PWD = new QLineEdit(enter_PWD);
        lineEdit_PWD->setObjectName(QString::fromUtf8("lineEdit_PWD"));
        lineEdit_PWD->setGeometry(QRect(440, 370, 320, 36));
        lineEdit_PWD->setFont(font);
        lineEdit_PWD->setAlignment(Qt::AlignCenter);
        foreground = new QGraphicsView(enter_PWD);
        foreground->setObjectName(QString::fromUtf8("foreground"));
        foreground->setGeometry(QRect(300, 180, 600, 360));
        background->raise();
        foreground->raise();
        label_photo->raise();
        pushButton_enter->raise();
        lineEdit_PWD->raise();
        label_account->raise();

        retranslateUi(enter_PWD);

        pushButton_enter->setDefault(false);


        QMetaObject::connectSlotsByName(enter_PWD);
    } // setupUi

    void retranslateUi(QDialog *enter_PWD)
    {
        enter_PWD->setWindowTitle(QCoreApplication::translate("enter_PWD", "Dialog", nullptr));
        pushButton_enter->setText(QCoreApplication::translate("enter_PWD", "ENTER", nullptr));
        label_account->setText(QString());
        label_photo->setText(QString());
        lineEdit_PWD->setPlaceholderText(QCoreApplication::translate("enter_PWD", "PASSWORD", nullptr));
    } // retranslateUi

};

namespace Ui {
    class enter_PWD: public Ui_enter_PWD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTER_PWD_H
