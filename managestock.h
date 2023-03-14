#ifndef MANAGESTOCK_H
#define MANAGESTOCK_H

#include <QDialog>
#include<QDebug>
#include<QSqlError>
#include<QListWidget>
#include"edititem.h"
#include"commodity.h"
#include "databaseconnection.h"
#include "userinterface.h"
#include "user.h"
#include <QSqlDatabase>
#include <QSqlQuery>
class UserInterface;
class EditItem;
namespace Ui {
class ManageStock;
}

class ManageStock : public QDialog
{
    Q_OBJECT

public:
    explicit ManageStock(QWidget *parent = nullptr);
    ~ManageStock();

    void passQuery(QSqlQuery* qr){query = qr;}
    void passDB(DatabaseConnection* p){db = p; }
    void initial();
    void update();
    void passUser(User *u);


private slots:
    void on_addProduct_clicked();
    void on_update_clicked();
    void on_listWidget_currentRowChanged(int currentRow);
    void on_del_clicked();
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_back_clicked();
    void slotRowDoubleClicked(const QModelIndex &index);

    void on_search1_clicked();

    void on_search2_clicked();

    void on_searchType_activated(int index);

private:
    Ui::ManageStock *ui;
    EditItem* newItem;
    EditItem *edit_item;
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
};

#endif // MANAGESTOCK_H
