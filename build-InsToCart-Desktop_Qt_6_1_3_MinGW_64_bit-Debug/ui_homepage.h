/********************************************************************************
** Form generated from reading UI file 'homepage.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEPAGE_H
#define UI_HOMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomePage
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *settings;
    QLineEdit *search_lineEdit;
    QComboBox *search_comboBox;
    QPushButton *search;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QFrame *frame_7;
    QPushButton *plus_5;
    QLabel *label_5_name;
    QLabel *label_5_img;
    QPushButton *pushButton_5_back;
    QWidget *layoutWidget_12;
    QHBoxLayout *horizontalLayout_13;
    QDoubleSpinBox *doubleSpinBox_5;
    QLabel *label_5_price;
    QFrame *frame_4;
    QPushButton *plus_2;
    QLabel *label_2_name;
    QLabel *label_2_img;
    QPushButton *pushButton_2_back;
    QWidget *layoutWidget_7;
    QHBoxLayout *horizontalLayout_8;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label_2_price;
    QFrame *frame_8;
    QPushButton *plus_6;
    QLabel *label_6_name;
    QLabel *label_6_img;
    QPushButton *pushButton_6_back;
    QWidget *layoutWidget_13;
    QHBoxLayout *horizontalLayout_14;
    QDoubleSpinBox *doubleSpinBox_6;
    QLabel *label_6_price;
    QFrame *frame_9;
    QPushButton *plus_7;
    QLabel *label_7_name;
    QLabel *label_7_img;
    QPushButton *pushButton_7_back;
    QWidget *layoutWidget_14;
    QHBoxLayout *horizontalLayout_15;
    QDoubleSpinBox *doubleSpinBox_7;
    QLabel *label_7_price;
    QFrame *frame_6;
    QPushButton *plus_4;
    QLabel *label_4_name;
    QLabel *label_4_img;
    QPushButton *pushButton_4_back;
    QWidget *layoutWidget_11;
    QHBoxLayout *horizontalLayout_12;
    QDoubleSpinBox *doubleSpinBox_4;
    QLabel *label_4_price;
    QFrame *frame_0;
    QPushButton *plus_0;
    QLabel *label_0_name;
    QLabel *label_0_img;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QDoubleSpinBox *doubleSpinBox_0;
    QLabel *label_0_price;
    QPushButton *pushButton_back_0;
    QFrame *frame_1;
    QPushButton *plus_1;
    QLabel *label_1_name;
    QLabel *label_1_img;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QDoubleSpinBox *doubleSpinBox_1;
    QLabel *label_1_price;
    QPushButton *pushButton_back_1;
    QFrame *frame_5;
    QPushButton *plus_3;
    QLabel *label_3_name;
    QLabel *label_3_img;
    QPushButton *pushButton_3_back;
    QWidget *layoutWidget_9;
    QHBoxLayout *horizontalLayout_10;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_3_price;
    QPushButton *right_arrow;
    QPushButton *left_arrow;
    QPushButton *up;
    QPushButton *down;
    QPushButton *message;
    QPushButton *cart;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HomePage)
    {
        if (HomePage->objectName().isEmpty())
            HomePage->setObjectName(QString::fromUtf8("HomePage"));
        HomePage->resize(1200, 720);
        HomePage->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 188, 46);"));
        HomePage->setTabShape(QTabWidget::Rounded);
        centralwidget = new QWidget(HomePage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 20, 221, 81));
        label->setStyleSheet(QString::fromUtf8("color: rgb(50, 50, 50);\n"
"font: 25pt \"Impact\";\n"
"background-color: rgba(255, 255, 255, 0);"));
        label->setAlignment(Qt::AlignCenter);
        settings = new QPushButton(centralwidget);
        settings->setObjectName(QString::fromUtf8("settings"));
        settings->setGeometry(QRect(1090, 40, 61, 41));
        settings->setCursor(QCursor(Qt::PointingHandCursor));
        settings->setStyleSheet(QString::fromUtf8("image: url(./img/person.png);"));
        settings->setFlat(true);
        search_lineEdit = new QLineEdit(centralwidget);
        search_lineEdit->setObjectName(QString::fromUtf8("search_lineEdit"));
        search_lineEdit->setGeometry(QRect(460, 40, 251, 41));
        search_lineEdit->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-radius:  10px; \n"
"border-width: 2px;\n"
"border-color: black;\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(127, 127, 127); \n"
"min-width: 10em;\n"
""));
        search_comboBox = new QComboBox(centralwidget);
        search_comboBox->addItem(QString());
        search_comboBox->addItem(QString());
        search_comboBox->addItem(QString());
        search_comboBox->addItem(QString());
        search_comboBox->addItem(QString());
        search_comboBox->setObjectName(QString::fromUtf8("search_comboBox"));
        search_comboBox->setGeometry(QRect(240, 40, 161, 41));
        search_comboBox->setStyleSheet(QString::fromUtf8("background-color: rgba(0,0,0,50);    \n"
"font: 9pt \"Consolas\";\n"
"color: white;\n"
"border-radius: 10px;\n"
"border-color: beige;\n"
"font: bold 18px;\n"
""));
        search_comboBox->setFrame(false);
        search = new QPushButton(centralwidget);
        search->setObjectName(QString::fromUtf8("search"));
        search->setGeometry(QRect(730, 40, 41, 41));
        search->setStyleSheet(QString::fromUtf8(""));
        search->setFlat(true);
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(80, 120, 1041, 551));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(15);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame_7 = new QFrame(gridLayoutWidget);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-style: outset;\n"
"font: 12pt \"Consolas\";\n"
"\n"
"border-radius: 15px;\n"
"padding: 6px;\n"
"\n"
""));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        plus_5 = new QPushButton(frame_7);
        plus_5->setObjectName(QString::fromUtf8("plus_5"));
        plus_5->setGeometry(QRect(210, 10, 31, 31));
        plus_5->setCursor(QCursor(Qt::PointingHandCursor));
        plus_5->setStyleSheet(QString::fromUtf8(""));
        label_5_name = new QLabel(frame_7);
        label_5_name->setObjectName(QString::fromUtf8("label_5_name"));
        label_5_name->setGeometry(QRect(0, 10, 250, 31));
        label_5_name->setAlignment(Qt::AlignCenter);
        label_5_img = new QLabel(frame_7);
        label_5_img->setObjectName(QString::fromUtf8("label_5_img"));
        label_5_img->setGeometry(QRect(10, 100, 211, 121));
        label_5_img->setAlignment(Qt::AlignCenter);
        pushButton_5_back = new QPushButton(frame_7);
        pushButton_5_back->setObjectName(QString::fromUtf8("pushButton_5_back"));
        pushButton_5_back->setGeometry(QRect(80, 230, 91, 31));
        pushButton_5_back->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_5_back->setStyleSheet(QString::fromUtf8("color:rgb(50, 50, 50);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 2px solid rgb(50, 50, 50);\n"
"border-radius:  12px; \n"
"font: 12pt \"Consolas\";"));
        layoutWidget_12 = new QWidget(frame_7);
        layoutWidget_12->setObjectName(QString::fromUtf8("layoutWidget_12"));
        layoutWidget_12->setGeometry(QRect(10, 50, 224, 42));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget_12);
        horizontalLayout_13->setSpacing(20);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        doubleSpinBox_5 = new QDoubleSpinBox(layoutWidget_12);
        doubleSpinBox_5->setObjectName(QString::fromUtf8("doubleSpinBox_5"));
        doubleSpinBox_5->setStyleSheet(QString::fromUtf8("color: rgb(50, 50, 50);\n"
"font: 12pt \"Consolas\";"));
        doubleSpinBox_5->setDecimals(0);

        horizontalLayout_13->addWidget(doubleSpinBox_5);

        label_5_price = new QLabel(layoutWidget_12);
        label_5_price->setObjectName(QString::fromUtf8("label_5_price"));

        horizontalLayout_13->addWidget(label_5_price);

        label_5_name->raise();
        label_5_img->raise();
        pushButton_5_back->raise();
        layoutWidget_12->raise();
        plus_5->raise();

        gridLayout->addWidget(frame_7, 1, 1, 1, 1);

        frame_4 = new QFrame(gridLayoutWidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy);
        frame_4->setMinimumSize(QSize(248, 0));
        frame_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-style: outset;\n"
"font: 12pt \"Consolas\";\n"
"\n"
"border-radius: 15px;\n"
"padding: 6px;\n"
"\n"
""));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        plus_2 = new QPushButton(frame_4);
        plus_2->setObjectName(QString::fromUtf8("plus_2"));
        plus_2->setGeometry(QRect(210, 10, 31, 31));
        plus_2->setCursor(QCursor(Qt::PointingHandCursor));
        plus_2->setStyleSheet(QString::fromUtf8(""));
        label_2_name = new QLabel(frame_4);
        label_2_name->setObjectName(QString::fromUtf8("label_2_name"));
        label_2_name->setGeometry(QRect(0, 10, 250, 31));
        label_2_name->setStyleSheet(QString::fromUtf8("font: 12pt \"Consolas\";"));
        label_2_name->setAlignment(Qt::AlignCenter);
        label_2_img = new QLabel(frame_4);
        label_2_img->setObjectName(QString::fromUtf8("label_2_img"));
        label_2_img->setGeometry(QRect(20, 100, 211, 121));
        label_2_img->setAlignment(Qt::AlignCenter);
        pushButton_2_back = new QPushButton(frame_4);
        pushButton_2_back->setObjectName(QString::fromUtf8("pushButton_2_back"));
        pushButton_2_back->setGeometry(QRect(70, 230, 101, 31));
        pushButton_2_back->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2_back->setStyleSheet(QString::fromUtf8("color:rgb(50, 50, 50);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 2px solid rgb(50, 50, 50);\n"
"border-radius:  12px; \n"
"font: 12pt \"Consolas\";"));
        layoutWidget_7 = new QWidget(frame_4);
        layoutWidget_7->setObjectName(QString::fromUtf8("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(20, 50, 224, 42));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget_7);
        horizontalLayout_8->setSpacing(20);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        doubleSpinBox_2 = new QDoubleSpinBox(layoutWidget_7);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setStyleSheet(QString::fromUtf8("color: rgb(50, 50, 50);\n"
"font: 12pt \"Consolas\";"));
        doubleSpinBox_2->setDecimals(0);

        horizontalLayout_8->addWidget(doubleSpinBox_2);

        label_2_price = new QLabel(layoutWidget_7);
        label_2_price->setObjectName(QString::fromUtf8("label_2_price"));

        horizontalLayout_8->addWidget(label_2_price);

        label_2_img->raise();
        label_2_name->raise();
        pushButton_2_back->raise();
        layoutWidget_7->raise();
        plus_2->raise();

        gridLayout->addWidget(frame_4, 0, 3, 1, 1);

        frame_8 = new QFrame(gridLayoutWidget);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-style: outset;\n"
"font: 12pt \"Consolas\";\n"
"\n"
"border-radius: 15px;\n"
"padding: 6px;\n"
"\n"
""));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        plus_6 = new QPushButton(frame_8);
        plus_6->setObjectName(QString::fromUtf8("plus_6"));
        plus_6->setGeometry(QRect(210, 10, 31, 31));
        plus_6->setCursor(QCursor(Qt::PointingHandCursor));
        plus_6->setStyleSheet(QString::fromUtf8(""));
        label_6_name = new QLabel(frame_8);
        label_6_name->setObjectName(QString::fromUtf8("label_6_name"));
        label_6_name->setGeometry(QRect(0, 10, 250, 31));
        label_6_name->setAlignment(Qt::AlignCenter);
        label_6_img = new QLabel(frame_8);
        label_6_img->setObjectName(QString::fromUtf8("label_6_img"));
        label_6_img->setGeometry(QRect(20, 100, 211, 121));
        label_6_img->setAlignment(Qt::AlignCenter);
        pushButton_6_back = new QPushButton(frame_8);
        pushButton_6_back->setObjectName(QString::fromUtf8("pushButton_6_back"));
        pushButton_6_back->setGeometry(QRect(80, 230, 101, 31));
        pushButton_6_back->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_6_back->setStyleSheet(QString::fromUtf8("color:rgb(50, 50, 50);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 2px solid rgb(50, 50, 50);\n"
"border-radius:  12px; \n"
"font: 12pt \"Consolas\";"));
        layoutWidget_13 = new QWidget(frame_8);
        layoutWidget_13->setObjectName(QString::fromUtf8("layoutWidget_13"));
        layoutWidget_13->setGeometry(QRect(20, 50, 224, 42));
        horizontalLayout_14 = new QHBoxLayout(layoutWidget_13);
        horizontalLayout_14->setSpacing(20);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        doubleSpinBox_6 = new QDoubleSpinBox(layoutWidget_13);
        doubleSpinBox_6->setObjectName(QString::fromUtf8("doubleSpinBox_6"));
        doubleSpinBox_6->setStyleSheet(QString::fromUtf8("color: rgb(50, 50, 50);\n"
"font: 12pt \"Consolas\";"));
        doubleSpinBox_6->setDecimals(0);

        horizontalLayout_14->addWidget(doubleSpinBox_6);

        label_6_price = new QLabel(layoutWidget_13);
        label_6_price->setObjectName(QString::fromUtf8("label_6_price"));

        horizontalLayout_14->addWidget(label_6_price);

        label_6_img->raise();
        label_6_name->raise();
        pushButton_6_back->raise();
        layoutWidget_13->raise();
        plus_6->raise();

        gridLayout->addWidget(frame_8, 1, 3, 1, 1);

        frame_9 = new QFrame(gridLayoutWidget);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_9->sizePolicy().hasHeightForWidth());
        frame_9->setSizePolicy(sizePolicy1);
        frame_9->setMinimumSize(QSize(0, 267));
        frame_9->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 12pt \"Consolas\";\n"
"border-radius: 15px;\n"
"padding: 6px;\n"
"\n"
""));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        plus_7 = new QPushButton(frame_9);
        plus_7->setObjectName(QString::fromUtf8("plus_7"));
        plus_7->setGeometry(QRect(210, 10, 31, 31));
        plus_7->setCursor(QCursor(Qt::PointingHandCursor));
        plus_7->setStyleSheet(QString::fromUtf8(""));
        label_7_name = new QLabel(frame_9);
        label_7_name->setObjectName(QString::fromUtf8("label_7_name"));
        label_7_name->setGeometry(QRect(0, 10, 250, 31));
        label_7_name->setStyleSheet(QString::fromUtf8("font: 12pt \"Consolas\";"));
        label_7_name->setAlignment(Qt::AlignCenter);
        label_7_img = new QLabel(frame_9);
        label_7_img->setObjectName(QString::fromUtf8("label_7_img"));
        label_7_img->setGeometry(QRect(20, 100, 211, 121));
        label_7_img->setAlignment(Qt::AlignCenter);
        pushButton_7_back = new QPushButton(frame_9);
        pushButton_7_back->setObjectName(QString::fromUtf8("pushButton_7_back"));
        pushButton_7_back->setGeometry(QRect(80, 230, 101, 31));
        pushButton_7_back->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_7_back->setStyleSheet(QString::fromUtf8("color:rgb(50, 50, 50);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 2px solid rgb(50, 50, 50);\n"
"border-radius:  12px; \n"
"font: 12pt \"Consolas\";"));
        layoutWidget_14 = new QWidget(frame_9);
        layoutWidget_14->setObjectName(QString::fromUtf8("layoutWidget_14"));
        layoutWidget_14->setGeometry(QRect(20, 50, 224, 38));
        horizontalLayout_15 = new QHBoxLayout(layoutWidget_14);
        horizontalLayout_15->setSpacing(20);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        doubleSpinBox_7 = new QDoubleSpinBox(layoutWidget_14);
        doubleSpinBox_7->setObjectName(QString::fromUtf8("doubleSpinBox_7"));
        doubleSpinBox_7->setStyleSheet(QString::fromUtf8("color: rgb(50, 50, 50);\n"
"font: 12pt \"Consolas\";"));
        doubleSpinBox_7->setDecimals(0);

        horizontalLayout_15->addWidget(doubleSpinBox_7);

        label_7_price = new QLabel(layoutWidget_14);
        label_7_price->setObjectName(QString::fromUtf8("label_7_price"));

        horizontalLayout_15->addWidget(label_7_price);

        label_7_img->raise();
        label_7_name->raise();
        pushButton_7_back->raise();
        layoutWidget_14->raise();
        plus_7->raise();

        gridLayout->addWidget(frame_9, 1, 6, 1, 1);

        frame_6 = new QFrame(gridLayoutWidget);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-style: outset;\n"
"font: 12pt \"Consolas\";\n"
"\n"
"border-radius: 15px;\n"
"padding: 6px;\n"
"\n"
""));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        plus_4 = new QPushButton(frame_6);
        plus_4->setObjectName(QString::fromUtf8("plus_4"));
        plus_4->setGeometry(QRect(210, 10, 31, 31));
        plus_4->setCursor(QCursor(Qt::PointingHandCursor));
        plus_4->setStyleSheet(QString::fromUtf8(""));
        label_4_name = new QLabel(frame_6);
        label_4_name->setObjectName(QString::fromUtf8("label_4_name"));
        label_4_name->setGeometry(QRect(0, 10, 250, 31));
        label_4_name->setAlignment(Qt::AlignCenter);
        label_4_img = new QLabel(frame_6);
        label_4_img->setObjectName(QString::fromUtf8("label_4_img"));
        label_4_img->setGeometry(QRect(20, 100, 211, 121));
        label_4_img->setAlignment(Qt::AlignCenter);
        pushButton_4_back = new QPushButton(frame_6);
        pushButton_4_back->setObjectName(QString::fromUtf8("pushButton_4_back"));
        pushButton_4_back->setGeometry(QRect(80, 230, 101, 31));
        pushButton_4_back->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_4_back->setStyleSheet(QString::fromUtf8("color:rgb(50, 50, 50);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 2px solid rgb(50, 50, 50);\n"
"border-radius:  12px; \n"
"font: 12pt \"Consolas\";"));
        layoutWidget_11 = new QWidget(frame_6);
        layoutWidget_11->setObjectName(QString::fromUtf8("layoutWidget_11"));
        layoutWidget_11->setGeometry(QRect(20, 50, 224, 42));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget_11);
        horizontalLayout_12->setSpacing(20);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        doubleSpinBox_4 = new QDoubleSpinBox(layoutWidget_11);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));
        doubleSpinBox_4->setStyleSheet(QString::fromUtf8("color: rgb(50, 50, 50);\n"
"font: 12pt \"Consolas\";"));
        doubleSpinBox_4->setDecimals(0);

        horizontalLayout_12->addWidget(doubleSpinBox_4);

        label_4_price = new QLabel(layoutWidget_11);
        label_4_price->setObjectName(QString::fromUtf8("label_4_price"));

        horizontalLayout_12->addWidget(label_4_price);

        label_4_name->raise();
        label_4_img->raise();
        pushButton_4_back->raise();
        layoutWidget_11->raise();
        plus_4->raise();

        gridLayout->addWidget(frame_6, 1, 0, 1, 1);

        frame_0 = new QFrame(gridLayoutWidget);
        frame_0->setObjectName(QString::fromUtf8("frame_0"));
        frame_0->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame_0->sizePolicy().hasHeightForWidth());
        frame_0->setSizePolicy(sizePolicy2);
        frame_0->setMinimumSize(QSize(249, 267));
        frame_0->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-style: outset;\n"
"font: 12pt \"Consolas\";\n"
"\n"
"border-radius: 15px;\n"
"padding: 6px;\n"
"\n"
""));
        frame_0->setFrameShape(QFrame::StyledPanel);
        frame_0->setFrameShadow(QFrame::Raised);
        plus_0 = new QPushButton(frame_0);
        plus_0->setObjectName(QString::fromUtf8("plus_0"));
        plus_0->setGeometry(QRect(210, 10, 31, 31));
        plus_0->setCursor(QCursor(Qt::PointingHandCursor));
        plus_0->setStyleSheet(QString::fromUtf8(""));
        label_0_name = new QLabel(frame_0);
        label_0_name->setObjectName(QString::fromUtf8("label_0_name"));
        label_0_name->setGeometry(QRect(0, 10, 250, 31));
        label_0_name->setStyleSheet(QString::fromUtf8("font: 12pt \"Consolas\";"));
        label_0_name->setAlignment(Qt::AlignCenter);
        label_0_img = new QLabel(frame_0);
        label_0_img->setObjectName(QString::fromUtf8("label_0_img"));
        label_0_img->setGeometry(QRect(10, 100, 211, 121));
        label_0_img->setAlignment(Qt::AlignCenter);
        layoutWidget_3 = new QWidget(frame_0);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 50, 224, 42));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_4->setSpacing(20);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        doubleSpinBox_0 = new QDoubleSpinBox(layoutWidget_3);
        doubleSpinBox_0->setObjectName(QString::fromUtf8("doubleSpinBox_0"));
        doubleSpinBox_0->setStyleSheet(QString::fromUtf8("color: rgb(50, 50, 50);\n"
"font: 12pt \"Consolas\";"));
        doubleSpinBox_0->setDecimals(0);

        horizontalLayout_4->addWidget(doubleSpinBox_0);

        label_0_price = new QLabel(layoutWidget_3);
        label_0_price->setObjectName(QString::fromUtf8("label_0_price"));

        horizontalLayout_4->addWidget(label_0_price);

        pushButton_back_0 = new QPushButton(frame_0);
        pushButton_back_0->setObjectName(QString::fromUtf8("pushButton_back_0"));
        pushButton_back_0->setGeometry(QRect(80, 230, 91, 31));
        pushButton_back_0->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_back_0->setStyleSheet(QString::fromUtf8("color:rgb(50, 50, 50);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 2px solid rgb(50, 50, 50);\n"
"border-radius:  12px; \n"
"font: 12pt \"Consolas\";"));
        label_0_img->raise();
        label_0_name->raise();
        pushButton_back_0->raise();
        layoutWidget_3->raise();
        plus_0->raise();

        gridLayout->addWidget(frame_0, 0, 0, 1, 1);

        frame_1 = new QFrame(gridLayoutWidget);
        frame_1->setObjectName(QString::fromUtf8("frame_1"));
        sizePolicy.setHeightForWidth(frame_1->sizePolicy().hasHeightForWidth());
        frame_1->setSizePolicy(sizePolicy);
        frame_1->setMinimumSize(QSize(248, 0));
        frame_1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-style: outset;\n"
"font: 12pt \"Consolas\";\n"
"\n"
"border-radius: 15px;\n"
"padding: 6px;\n"
"\n"
""));
        frame_1->setFrameShape(QFrame::StyledPanel);
        frame_1->setFrameShadow(QFrame::Raised);
        plus_1 = new QPushButton(frame_1);
        plus_1->setObjectName(QString::fromUtf8("plus_1"));
        plus_1->setGeometry(QRect(210, 10, 31, 31));
        plus_1->setCursor(QCursor(Qt::PointingHandCursor));
        plus_1->setStyleSheet(QString::fromUtf8(""));
        label_1_name = new QLabel(frame_1);
        label_1_name->setObjectName(QString::fromUtf8("label_1_name"));
        label_1_name->setGeometry(QRect(0, 10, 250, 31));
        label_1_name->setStyleSheet(QString::fromUtf8("font: 12pt \"Consolas\";"));
        label_1_name->setAlignment(Qt::AlignCenter);
        label_1_img = new QLabel(frame_1);
        label_1_img->setObjectName(QString::fromUtf8("label_1_img"));
        label_1_img->setGeometry(QRect(20, 100, 211, 121));
        label_1_img->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(frame_1);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 50, 224, 42));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        doubleSpinBox_1 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_1->setObjectName(QString::fromUtf8("doubleSpinBox_1"));
        doubleSpinBox_1->setStyleSheet(QString::fromUtf8("color: rgb(50, 50, 50);\n"
"font: 12pt \"Consolas\";"));
        doubleSpinBox_1->setDecimals(0);

        horizontalLayout->addWidget(doubleSpinBox_1);

        label_1_price = new QLabel(layoutWidget);
        label_1_price->setObjectName(QString::fromUtf8("label_1_price"));

        horizontalLayout->addWidget(label_1_price);

        pushButton_back_1 = new QPushButton(frame_1);
        pushButton_back_1->setObjectName(QString::fromUtf8("pushButton_back_1"));
        pushButton_back_1->setGeometry(QRect(80, 230, 91, 31));
        pushButton_back_1->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_back_1->setStyleSheet(QString::fromUtf8("color:rgb(50, 50, 50);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 2px solid rgb(50, 50, 50);\n"
"border-radius:  12px; \n"
"font: 12pt \"Consolas\";"));
        label_1_img->raise();
        label_1_name->raise();
        layoutWidget->raise();
        plus_1->raise();
        pushButton_back_1->raise();

        gridLayout->addWidget(frame_1, 0, 1, 1, 1);

        frame_5 = new QFrame(gridLayoutWidget);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        sizePolicy.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy);
        frame_5->setMinimumSize(QSize(248, 0));
        frame_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-style: outset;\n"
"font:12pt \"Consolas\";\n"
"\n"
"border-radius: 15px;\n"
"padding: 6px;\n"
"\n"
""));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        plus_3 = new QPushButton(frame_5);
        plus_3->setObjectName(QString::fromUtf8("plus_3"));
        plus_3->setGeometry(QRect(210, 10, 31, 31));
        plus_3->setCursor(QCursor(Qt::PointingHandCursor));
        plus_3->setStyleSheet(QString::fromUtf8("qproperty-icon: url(\":/img/plus.png\");\n"
""));
        label_3_name = new QLabel(frame_5);
        label_3_name->setObjectName(QString::fromUtf8("label_3_name"));
        label_3_name->setGeometry(QRect(0, 10, 250, 31));
        label_3_name->setStyleSheet(QString::fromUtf8("font: 12pt \"Consolas\";"));
        label_3_name->setAlignment(Qt::AlignCenter);
        label_3_img = new QLabel(frame_5);
        label_3_img->setObjectName(QString::fromUtf8("label_3_img"));
        label_3_img->setGeometry(QRect(20, 100, 211, 121));
        label_3_img->setAlignment(Qt::AlignCenter);
        pushButton_3_back = new QPushButton(frame_5);
        pushButton_3_back->setObjectName(QString::fromUtf8("pushButton_3_back"));
        pushButton_3_back->setGeometry(QRect(80, 230, 101, 31));
        pushButton_3_back->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_3_back->setStyleSheet(QString::fromUtf8("color:rgb(50, 50, 50);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 2px solid rgb(50, 50, 50);\n"
"border-radius:  12px; \n"
"font: 12pt \"Consolas\";"));
        layoutWidget_9 = new QWidget(frame_5);
        layoutWidget_9->setObjectName(QString::fromUtf8("layoutWidget_9"));
        layoutWidget_9->setGeometry(QRect(20, 50, 224, 42));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget_9);
        horizontalLayout_10->setSpacing(20);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        doubleSpinBox_3 = new QDoubleSpinBox(layoutWidget_9);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        doubleSpinBox_3->setStyleSheet(QString::fromUtf8("color: rgb(50, 50, 50);\n"
"font: 12pt \"Consolas\";"));
        doubleSpinBox_3->setDecimals(0);

        horizontalLayout_10->addWidget(doubleSpinBox_3);

        label_3_price = new QLabel(layoutWidget_9);
        label_3_price->setObjectName(QString::fromUtf8("label_3_price"));

        horizontalLayout_10->addWidget(label_3_price);

        label_3_img->raise();
        label_3_name->raise();
        pushButton_3_back->raise();
        layoutWidget_9->raise();
        plus_3->raise();

        gridLayout->addWidget(frame_5, 0, 6, 1, 1);

        frame_7->raise();
        frame_4->raise();
        frame_8->raise();
        frame_9->raise();
        frame_6->raise();
        frame_1->raise();
        frame_5->raise();
        frame_0->raise();
        right_arrow = new QPushButton(centralwidget);
        right_arrow->setObjectName(QString::fromUtf8("right_arrow"));
        right_arrow->setGeometry(QRect(1130, 370, 51, 51));
        right_arrow->setStyleSheet(QString::fromUtf8(""));
        right_arrow->setFlat(true);
        left_arrow = new QPushButton(centralwidget);
        left_arrow->setObjectName(QString::fromUtf8("left_arrow"));
        left_arrow->setGeometry(QRect(20, 370, 51, 51));
        left_arrow->setStyleSheet(QString::fromUtf8(""));
        left_arrow->setFlat(true);
        up = new QPushButton(centralwidget);
        up->setObjectName(QString::fromUtf8("up"));
        up->setGeometry(QRect(800, 40, 16, 41));
        up->setFlat(true);
        down = new QPushButton(centralwidget);
        down->setObjectName(QString::fromUtf8("down"));
        down->setGeometry(QRect(820, 40, 16, 41));
        down->setFlat(true);
        message = new QPushButton(centralwidget);
        message->setObjectName(QString::fromUtf8("message"));
        message->setGeometry(QRect(1030, 40, 61, 41));
        message->setCursor(QCursor(Qt::PointingHandCursor));
        message->setStyleSheet(QString::fromUtf8("image: url(:/message.png);"));
        message->setFlat(true);
        cart = new QPushButton(centralwidget);
        cart->setObjectName(QString::fromUtf8("cart"));
        cart->setGeometry(QRect(970, 40, 61, 41));
        cart->setCursor(QCursor(Qt::PointingHandCursor));
        cart->setStyleSheet(QString::fromUtf8("image: url(:/cart.png);"));
        cart->setFlat(true);
        HomePage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(HomePage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 22));
        HomePage->setMenuBar(menubar);
        statusbar = new QStatusBar(HomePage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        HomePage->setStatusBar(statusbar);

        retranslateUi(HomePage);

        QMetaObject::connectSlotsByName(HomePage);
    } // setupUi

    void retranslateUi(QMainWindow *HomePage)
    {
        HomePage->setWindowTitle(QCoreApplication::translate("HomePage", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("HomePage", "InsToCart", nullptr));
        settings->setText(QString());
        search_comboBox->setItemText(0, QCoreApplication::translate("HomePage", "ALL", nullptr));
        search_comboBox->setItemText(1, QCoreApplication::translate("HomePage", "FOOD", nullptr));
        search_comboBox->setItemText(2, QCoreApplication::translate("HomePage", "CLOTHES", nullptr));
        search_comboBox->setItemText(3, QCoreApplication::translate("HomePage", "HOME LIVING", nullptr));
        search_comboBox->setItemText(4, QCoreApplication::translate("HomePage", "ELECTRIC DEVICE", nullptr));

        search->setText(QString());
        plus_5->setText(QString());
        label_5_name->setText(QCoreApplication::translate("HomePage", "TextLabel", nullptr));
        label_5_img->setText(QCoreApplication::translate("HomePage", "TextLabel", nullptr));
        pushButton_5_back->setText(QCoreApplication::translate("HomePage", "DETAILS", nullptr));
        label_5_price->setText(QCoreApplication::translate("HomePage", "TextLabel", nullptr));
        plus_2->setText(QString());
        label_2_name->setText(QCoreApplication::translate("HomePage", "TextLabel", nullptr));
        label_2_img->setText(QCoreApplication::translate("HomePage", "TextLabel", nullptr));
        pushButton_2_back->setText(QCoreApplication::translate("HomePage", "DETAILS", nullptr));
        label_2_price->setText(QCoreApplication::translate("HomePage", "TextLabel", nullptr));
        plus_6->setText(QString());
        label_6_name->setText(QCoreApplication::translate("HomePage", "TextLabel", nullptr));
        label_6_img->setText(QCoreApplication::translate("HomePage", "TextLabel", nullptr));
        pushButton_6_back->setText(QCoreApplication::translate("HomePage", "DETAILS", nullptr));
        label_6_price->setText(QCoreApplication::translate("HomePage", "TextLabel", nullptr));
        plus_7->setText(QString());
        label_7_name->setText(QCoreApplication::translate("HomePage", "TextLabel", nullptr));
        label_7_img->setText(QCoreApplication::translate("HomePage", "TextLabel", nullptr));
        pushButton_7_back->setText(QCoreApplication::translate("HomePage", "DETAILS", nullptr));
        label_7_price->setText(QCoreApplication::translate("HomePage", "TextLabel", nullptr));
        plus_4->setText(QString());
        label_4_name->setText(QCoreApplication::translate("HomePage", "TextLabel", nullptr));
        label_4_img->setText(QCoreApplication::translate("HomePage", "TextLabel", nullptr));
        pushButton_4_back->setText(QCoreApplication::translate("HomePage", "DETAILS", nullptr));
        label_4_price->setText(QCoreApplication::translate("HomePage", "TextLabel", nullptr));
        plus_0->setText(QString());
        label_0_name->setText(QCoreApplication::translate("HomePage", "TextLabel", nullptr));
        label_0_img->setText(QCoreApplication::translate("HomePage", "TextLabel", nullptr));
        label_0_price->setText(QCoreApplication::translate("HomePage", "TextLabel", nullptr));
        pushButton_back_0->setText(QCoreApplication::translate("HomePage", "DETAILS", nullptr));
        plus_1->setText(QString());
        label_1_name->setText(QCoreApplication::translate("HomePage", "TextLabel", nullptr));
        label_1_img->setText(QCoreApplication::translate("HomePage", "TextLabel", nullptr));
        label_1_price->setText(QCoreApplication::translate("HomePage", "TextLabel", nullptr));
        pushButton_back_1->setText(QCoreApplication::translate("HomePage", "DETAILS", nullptr));
        plus_3->setText(QString());
        label_3_name->setText(QCoreApplication::translate("HomePage", "TextLabel", nullptr));
        label_3_img->setText(QCoreApplication::translate("HomePage", "TextLabel", nullptr));
        pushButton_3_back->setText(QCoreApplication::translate("HomePage", "DETAILS", nullptr));
        label_3_price->setText(QCoreApplication::translate("HomePage", "TextLabel", nullptr));
        right_arrow->setText(QString());
        left_arrow->setText(QString());
        up->setText(QString());
        down->setText(QString());
        message->setText(QString());
        cart->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HomePage: public Ui_HomePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGE_H
