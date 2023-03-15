#include "checkdist.h"
#include "ui_checkdist.h"

checkDist::checkDist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkDist)
{
    ui->setupUi(this);
    this->setWindowTitle("Distribution Center Login");
}

checkDist::~checkDist()
{
    delete ui;
}

void checkDist::on_enter_clicked()
{
    ui->alert->clear();
    if(ui->lineEdit->text()=="1234"){
        sh = new shippingWD;
        sh->passQuery(query);
        sh->setPage();
        sh->show();
        this->close();
    }
    else{
        ui->alert->setText("ID incorrect");
    }
}
void checkDist::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Return){
        ui->alert->clear();
        if(ui->lineEdit->text()=="1234"){
            sh = new shippingWD;
            sh->passQuery(query);
            sh->setPage();
            sh->show();
            this->close();
        }
        else{
            ui->alert->setText("ID incorrect");
        }
    }
}
