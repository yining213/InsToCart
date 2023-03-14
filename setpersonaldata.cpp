#include "setpersonaldata.h"
#include "ui_setpersonaldata.h"

setPersonalData::setPersonalData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setPersonalData)
{
    ui->setupUi(this);
}

setPersonalData::~setPersonalData()
{
    delete ui;
}
