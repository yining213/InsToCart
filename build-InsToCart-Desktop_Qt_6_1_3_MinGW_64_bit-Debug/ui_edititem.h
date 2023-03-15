/********************************************************************************
** Form generated from reading UI file 'edititem.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITITEM_H
#define UI_EDITITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditItem
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *photo;
    QPushButton *select_image;
    QLabel *item;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *name;
    QComboBox *category;
    QLineEdit *price;
    QLineEdit *shippin_fee;
    QLineEdit *stock;
    QTextEdit *description;
    QLabel *itemID;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label;

    void setupUi(QDialog *EditItem)
    {
        if (EditItem->objectName().isEmpty())
            EditItem->setObjectName(QString::fromUtf8("EditItem"));
        EditItem->resize(694, 487);
        EditItem->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 188, 46);"));
        buttonBox = new QDialogButtonBox(EditItem);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(530, 380, 121, 71));
        buttonBox->setStyleSheet(QString::fromUtf8("background-color: white;    \n"
"border-style: outset;\n"
"font: 9pt \"Consolas\" ;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 14px;\n"
"    padding: 6px;"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        photo = new QLabel(EditItem);
        photo->setObjectName(QString::fromUtf8("photo"));
        photo->setGeometry(QRect(40, 40, 101, 101));
        photo->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"font: 9pt \"Consolas\";\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: 14px;\n"
""));
        photo->setFrameShape(QFrame::StyledPanel);
        photo->setAlignment(Qt::AlignCenter);
        select_image = new QPushButton(EditItem);
        select_image->setObjectName(QString::fromUtf8("select_image"));
        select_image->setGeometry(QRect(160, 110, 71, 31));
        select_image->setStyleSheet(QString::fromUtf8("background-color: white;    \n"
"border-style: outset;\n"
"font: 9pt \"Consolas\" ;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 14px;\n"
"    padding: 6px;"));
        item = new QLabel(EditItem);
        item->setObjectName(QString::fromUtf8("item"));
        item->setGeometry(QRect(40, 160, 121, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("Consolas")});
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        item->setFont(font);
        item->setStyleSheet(QString::fromUtf8("font: 12pt \"Consolas\";"));
        verticalLayoutWidget = new QWidget(EditItem);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(100, 190, 161, 231));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        name = new QLineEdit(verticalLayoutWidget);
        name->setObjectName(QString::fromUtf8("name"));
        name->setStyleSheet(QString::fromUtf8("background-color: rgba(0,0,0,50);    \n"
"border-style: outset;\n"
"font: 9pt \"Consolas\" ;\n"
"color: white;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 14px;\n"
"    padding: 6px;"));
        name->setCursorMoveStyle(Qt::LogicalMoveStyle);
        name->setClearButtonEnabled(true);

        verticalLayout->addWidget(name);

        category = new QComboBox(verticalLayoutWidget);
        category->addItem(QString());
        category->addItem(QString());
        category->addItem(QString());
        category->addItem(QString());
        category->setObjectName(QString::fromUtf8("category"));
        category->setStyleSheet(QString::fromUtf8("background-color: rgba(0,0,0,50);    \n"
"border-style: outset;\n"
"font: 9pt \"Consolas\";\n"
"color: white;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 14px;\n"
"    padding: 6px;\n"
""));

        verticalLayout->addWidget(category);

        price = new QLineEdit(verticalLayoutWidget);
        price->setObjectName(QString::fromUtf8("price"));
        price->setStyleSheet(QString::fromUtf8("background-color: rgba(0,0,0,50);    \n"
"border-style: outset;\n"
"font: 9pt \"Consolas\";\n"
"color: white;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 14px;\n"
"    padding: 6px;"));

        verticalLayout->addWidget(price);

        shippin_fee = new QLineEdit(verticalLayoutWidget);
        shippin_fee->setObjectName(QString::fromUtf8("shippin_fee"));
        shippin_fee->setStyleSheet(QString::fromUtf8("background-color: rgba(0,0,0,50);    \n"
"border-style: outset;\n"
"font: 9pt \"Consolas\";\n"
"color: white;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 14px;\n"
"    padding: 6px;"));

        verticalLayout->addWidget(shippin_fee);

        stock = new QLineEdit(verticalLayoutWidget);
        stock->setObjectName(QString::fromUtf8("stock"));
        stock->setStyleSheet(QString::fromUtf8("background-color: rgba(0,0,0,50);    \n"
"border-style: outset;\n"
"font: 9pt \"Consolas\";\n"
"color: white;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 14px;\n"
"    padding: 6px;"));

        verticalLayout->addWidget(stock);

        description = new QTextEdit(EditItem);
        description->setObjectName(QString::fromUtf8("description"));
        description->setGeometry(QRect(290, 40, 361, 311));
        description->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        description->setStyleSheet(QString::fromUtf8("background-color: rgba(0,0,0,50);    \n"
"border-style: outset;\n"
"font: 9pt \"Consolas\";\n"
"color: white;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 14px;\n"
"    padding: 6px;"));
        description->setFrameShape(QFrame::NoFrame);
        description->setTabChangesFocus(false);
        itemID = new QLabel(EditItem);
        itemID->setObjectName(QString::fromUtf8("itemID"));
        itemID->setGeometry(QRect(120, 160, 111, 21));
        itemID->setFont(font);
        itemID->setStyleSheet(QString::fromUtf8("font: 12pt \"Consolas\";"));
        verticalLayoutWidget_2 = new QWidget(EditItem);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 190, 82, 231));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 9pt \"Consolas\";\n"
""));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_2);

        label_4 = new QLabel(verticalLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 9pt \"Consolas\";\n"
""));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 9pt \"Consolas\";\n"
""));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_5);

        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 9pt \"Consolas\";\n"
""));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_3);

        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 9pt \"Consolas\";\n"
""));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label);


        retranslateUi(EditItem);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, EditItem, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, EditItem, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(EditItem);
    } // setupUi

    void retranslateUi(QDialog *EditItem)
    {
        EditItem->setWindowTitle(QCoreApplication::translate("EditItem", "Dialog", nullptr));
        photo->setText(QCoreApplication::translate("EditItem", "PHOTO", nullptr));
        select_image->setText(QCoreApplication::translate("EditItem", "select", nullptr));
        item->setText(QCoreApplication::translate("EditItem", "ItemID : ", nullptr));
        name->setText(QString());
        name->setPlaceholderText(QCoreApplication::translate("EditItem", "NAME", nullptr));
        category->setItemText(0, QCoreApplication::translate("EditItem", "FOOD", nullptr));
        category->setItemText(1, QCoreApplication::translate("EditItem", "CLOTHES", nullptr));
        category->setItemText(2, QCoreApplication::translate("EditItem", "HOME LIVING", nullptr));
        category->setItemText(3, QCoreApplication::translate("EditItem", "ELECTRIC DEVICE", nullptr));

        category->setPlaceholderText(QCoreApplication::translate("EditItem", "CATEGORY", nullptr));
        price->setText(QString());
        price->setPlaceholderText(QCoreApplication::translate("EditItem", "PRICE", nullptr));
        shippin_fee->setText(QString());
        shippin_fee->setPlaceholderText(QCoreApplication::translate("EditItem", "SHIPPING FEE", nullptr));
        stock->setText(QString());
        stock->setPlaceholderText(QCoreApplication::translate("EditItem", "STOCK", nullptr));
        description->setDocumentTitle(QString());
        description->setPlaceholderText(QCoreApplication::translate("EditItem", "DESCRIPTION", nullptr));
        itemID->setText(QString());
        label_2->setText(QCoreApplication::translate("EditItem", "NAME", nullptr));
        label_4->setText(QCoreApplication::translate("EditItem", "CATEGORY", nullptr));
        label_5->setText(QCoreApplication::translate("EditItem", "PRICE", nullptr));
        label_3->setText(QCoreApplication::translate("EditItem", "SHIPPING FEE", nullptr));
        label->setText(QCoreApplication::translate("EditItem", "STOCK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditItem: public Ui_EditItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITITEM_H
