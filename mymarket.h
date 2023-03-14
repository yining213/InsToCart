#ifndef MYMARKET_H
#define MYMARKET_H

#include <QDialog>
#include<QDebug>
#include<QSqlError>
#include<QListWidget>
#include <QComboBox>
#include"edititem.h"
#include"commodity.h"
#include "databaseconnection.h"
#include "userinterface.h"
#include "user.h"
#include "myorderdetail.h"
#include <QSqlDatabase>
#include <QTableWidget>
#include <QSqlQuery>
using namespace std;
#include <iostream>
class UserInterface;
class EditItem;
class OrderDetail;
class MyOrderDetail;

namespace Ui {
class MyMarket;
}

class MyMarket : public QDialog
{
    Q_OBJECT

public:
    explicit MyMarket(QWidget *parent = nullptr);
    ~MyMarket();

    void passQuery(QSqlQuery* qr){query = qr;}
    void passDB(DatabaseConnection* p){db = p; }
    void initial();
    void update();
    void passUser(User *u);


private slots:
    void on_addProduct_clicked();
    void on_update_clicked();
    void on_del_clicked();

    void on_back_clicked();
    void slotRowDoubleClicked(const QModelIndex &index);
    void slotRowDoubleClicked_completed(const QModelIndex &index);
    void slotRowDoubleClicked_tobecompleted(const QModelIndex &index);
    void slotComboboxIndexChanged_tobecompleted(int index);

    void on_search1_clicked();

    void on_search2_clicked();

    void on_searchType_activated(int index);

    void on_managestock_clicked();

    void on_manageorder_clicked();

    void on_save_clicked();

private:
    Ui::MyMarket *ui;
    EditItem* newItem;
    EditItem *edit_item;
    MyOrderDetail *myorderdetail;
    UserInterface *prev;
    int mnSelected = -1;
    QSqlDatabase database;
    QSqlQuery *query;
    DatabaseConnection *db;
    User *user;
    vector<Commodity*> myItems;
    vector<Commodity*> search_name;
    vector<Commodity*> search_cat;
    vector<Commodity*> search_id;
    vector<Commodity*> *cur;
    vector<Order*> myorders, myorders_c, myorders_tbc;
    vector<QComboBox*> comboboxs;
};

#endif // MYMARKET_H
