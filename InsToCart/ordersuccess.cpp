#include "ordersuccess.h"
#include "ui_ordersuccess.h"

orderSuccess::orderSuccess(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::orderSuccess)
{
    ui->setupUi(this);
}

orderSuccess::~orderSuccess()
{
    delete ui;
}


