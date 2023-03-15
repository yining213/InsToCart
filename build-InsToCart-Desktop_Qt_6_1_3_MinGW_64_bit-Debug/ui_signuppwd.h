/********************************************************************************
** Form generated from reading UI file 'signuppwd.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPPWD_H
#define UI_SIGNUPPWD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_signupPWD
{
public:
    QGraphicsView *background;
    QGraphicsView *foreground;
    QLabel *label_signup;
    QLabel *label_acount;
    QLineEdit *lineEdit_PWD;
    QPushButton *pushButton;

    void setupUi(QDialog *signupPWD)
    {
        if (signupPWD->objectName().isEmpty())
            signupPWD->setObjectName(QString::fromUtf8("signupPWD"));
        signupPWD->resize(1200, 720);
        background = new QGraphicsView(signupPWD);
        background->setObjectName(QString::fromUtf8("background"));
        background->setGeometry(QRect(0, 0, 1200, 720));
        foreground = new QGraphicsView(signupPWD);
        foreground->setObjectName(QString::fromUtf8("foreground"));
        foreground->setGeometry(QRect(300, 180, 600, 360));
        label_signup = new QLabel(signupPWD);
        label_signup->setObjectName(QString::fromUtf8("label_signup"));
        label_signup->setGeometry(QRect(330, 240, 191, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Consolas")});
        font.setPointSize(28);
        font.setBold(false);
        font.setUnderline(false);
        font.setKerning(true);
        label_signup->setFont(font);
        label_signup->setAutoFillBackground(false);
        label_signup->setFrameShape(QFrame::NoFrame);
        label_signup->setTextFormat(Qt::AutoText);
        label_signup->setScaledContents(false);
        label_signup->setAlignment(Qt::AlignCenter);
        label_signup->setMargin(0);
        label_acount = new QLabel(signupPWD);
        label_acount->setObjectName(QString::fromUtf8("label_acount"));
        label_acount->setGeometry(QRect(340, 310, 331, 41));
        lineEdit_PWD = new QLineEdit(signupPWD);
        lineEdit_PWD->setObjectName(QString::fromUtf8("lineEdit_PWD"));
        lineEdit_PWD->setGeometry(QRect(340, 380, 331, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Consolas")});
        font1.setPointSize(14);
        lineEdit_PWD->setFont(font1);
        lineEdit_PWD->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(signupPWD);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(730, 470, 121, 41));
        pushButton->setFont(font1);
        background->raise();
        foreground->raise();
        label_acount->raise();
        label_signup->raise();
        lineEdit_PWD->raise();
        pushButton->raise();

        retranslateUi(signupPWD);

        QMetaObject::connectSlotsByName(signupPWD);
    } // setupUi

    void retranslateUi(QDialog *signupPWD)
    {
        signupPWD->setWindowTitle(QCoreApplication::translate("signupPWD", "Dialog", nullptr));
        label_signup->setText(QCoreApplication::translate("signupPWD", "SIGN UP", nullptr));
        label_acount->setText(QString());
        lineEdit_PWD->setPlaceholderText(QCoreApplication::translate("signupPWD", "PASSWORD", nullptr));
        pushButton->setText(QCoreApplication::translate("signupPWD", "ENTER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signupPWD: public Ui_signupPWD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPPWD_H
