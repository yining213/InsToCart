#include "edititem.h"
#include "ui_edititem.h"
#include<string>
#include<QDebug>
#include<QSqlError>
#include <QMessageBox>

EditItem::EditItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditItem)
{
    ui->setupUi(this);
    ui->name->setPlaceholderText("NAME");
    ui->name->placeholderText();

    addnew = 0;

}

EditItem::~EditItem()
{
    delete ui;
}

void EditItem::on_select_image_clicked()
{
    QString curDir = QDir::currentPath();
    QString fileDir = QFileDialog::getOpenFileName(this, tr("Choose"), "./img", tr("Images(*.png *.jpg *.jpeg *.bmp *.gif)")).mid(curDir.length()+1);
    //qDebug()<<curDir;
    c->setFilename(fileDir);

    if(QString::compare(c->getFilename(), QString()) != 0){
        c->photo = new QPixmap;
        bool valid = c->photo->load(c->getFilename());
        if(valid){
            int w = ui->photo->width();
            int h = ui->photo->height();
            //c->photo->scaled(w, h, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            //ui->photo->setScaledContents(1);
            ui->photo->setPixmap(c->photo->scaled(w, h, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
        else{
        }
    }

}


void EditItem::on_buttonBox_accepted()
{
    //item exist
    if(ui->name->text()==QString()){
        return;
    }
    if(!addnew){
        db->del(c->getItemID());
    }
    else{
        Commodity::total++;
    }
    c->setItemID(ui->itemID->text().toInt());
    c->setName(ui->name->text());
    c->setPrice(ui->price->text().toInt());
    c->setShippingFee(ui->shippin_fee->text().toInt());
    switch (ui->category->currentIndex()) {
    case 0:
        c->setCategory("food");
        break;
    case 1:
        c->setCategory("clothes");
        break;
    case 2:
        c->setCategory("home_living");
        break;
    case 3:
        c->setCategory("electric_device");
        break;
    }
    c->setStock(ui->stock->text().toInt());
    c->setDescript(ui->description->toPlainText());
    c->setOwnerID(user->getID());

    db->insertData(*c);
    MS->initial();
}

void EditItem::setInfo(Commodity *t){
    c=t;
    ui->name->setText(c->getName());
    ui->category->setCurrentIndex(c->getCate());
    ui->itemID->setText(QString::number(c->getItemID()));
    ui->price->setText(QString::number(c->getPrice()));
    ui->shippin_fee->setText(QString::number(c->getSF()));
    ui->stock->setText(QString::number(c->getStock()));
    ui->description->setText(c->getDescript());
    qDebug()<<c->getFilename();
    if(QString::compare(c->getFilename(), QString()) != 0){
        c->photo = new QPixmap;
        bool valid = c->photo->load(c->getFilename());
        if(valid){
            int w = ui->photo->width();
            int h = ui->photo->height();
            //c.photo->scaledToHeight(h, Qt::SmoothTransformation);
            //c->photo->scaled(w, h, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
            //ui->photo->setScaledContents(1);
            ui->photo->setPixmap(c->photo->scaled(w, h, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
    }
}
void EditItem::setID(int id){
    ui->itemID->setText(QString::number(id));
}

void EditItem::on_buttonBox_rejected(){
    if(addnew)
        delete c;
}
void EditItem::passUser(User *u){
    user = u;
}


