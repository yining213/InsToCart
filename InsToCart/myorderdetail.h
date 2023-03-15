#ifndef MYORDERDETAIL_H
#define MYORDERDETAIL_H

#include <QDialog>
#include "order.h"
#include<QDebug>
#include<QSqlError>
#include<QListWidget>
#include"commodity.h"
#include "databaseconnection.h"
#include "mymarket.h"
#include "user.h"
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class MyOrderDetail;
}

class MyOrderDetail : public QDialog
{
    Q_OBJECT

public:
    explicit MyOrderDetail(QWidget *parent = nullptr);
    ~MyOrderDetail();
    void passDB(DatabaseConnection* p){db = p;}
    void passUser(User *u){user = u;}
    void passQuery(QSqlQuery* qr){query = qr;}
    void passOrder(Order *o){order = o;}
    void update();
private slots:

private:
    Ui::MyOrderDetail *ui;
    QSqlQuery *query;
    DatabaseConnection *db;
    User *user;
    Order *order;
};

#endif // MYORDERDETAIL_H
