#ifndef EDITITEM_H
#define EDITITEM_H

#include <QDialog>
#include<QFileDialog>
#include"commodity.h"
#include "databaseconnection.h"
#include "mymarket.h"
#include "user.h"
#include <QSqlDatabase>
#include <QSqlQuery>

class MyMarket;
namespace Ui {
class EditItem;
}

class EditItem : public QDialog
{
    Q_OBJECT

public:
    explicit EditItem(QWidget *parent = nullptr);
    ~EditItem();
    void setInfo(Commodity *c);
    void setID(int);
    void setAddNew(bool b){addnew = b;}
    void passQuery(QSqlQuery* qr){query = qr;}
    void passDB(DatabaseConnection* p){db = p;}
    void passUser(User *u);
    void passMS(MyMarket* t){MS = t;}
    void passItem(Commodity* t){c=t;}

private slots:
    void on_select_image_clicked();
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();


private:
    Ui::EditItem *ui;
    MyMarket *MS;
    Commodity *c;
    bool addnew;
    QSqlQuery *query;
    DatabaseConnection *db;
    User *user;
};

#endif // EDITITEM_H
