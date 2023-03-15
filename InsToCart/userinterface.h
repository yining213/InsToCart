#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <QMainWindow>
#include <QMainWindow>
#include<QGraphicsScene>
#include <QSlider>
#include <qheaderview.h>
#include <QTableWidget>
#include<QGraphicsItem>
#include <QComboBox>
#include <QPushButton>
#include<QPainter>
#include<qpainter.h>
#include<QVector>
#include<QDebug>
#include <QDebug>
#include <QSqlResult>
#include <QSqlDatabase>
#include <QSqlQuery>
#include"mymarket.h"
#include"commodity.h"
#include "databaseconnection.h"
#include "homepage.h"
#include "user.h"
#include "orderinfo.h"
#include "comment.h"
class Comment;
class orderINFO;
class User;
class MyMarket;
class HomePage;
namespace Ui {
class UserInterface;
}

class UserInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserInterface(QWidget *parent = nullptr);
    ~UserInterface();
    void passQuery(QSqlQuery* qr){query = qr;}
    void passUser(User* copyUser){user = copyUser;}
    void passDB(DatabaseConnection *t){db = t;}
    void keepLast(MainWindow *p){login = p;}
    /*
    void passQuery(QSqlQuery* qr){query = qr;}
    //void passDB(DatabaseConnection* p){db = p; qDebug()<<"pass success!";}
    void passUser(User *u);
    */
    //data setting
    bool checkUsername(QString);
    //page setting
    void page_accountSet(void);
    void page_ordersSet(void);
    void page_couponsSet(void);
    void tableInitial(QTableWidget* table, int index);
    void displayTable(int index);

    bool checkAccount(void);
    bool checkName(void);
    bool checkPwd(void);
    bool checkPhone(void);
private slots:
    void on_mymarket_clicked();
    void on_pushButton_myaccount_clicked();
    void on_pushButton_myorders_clicked();
    void on_pushButton_save_clicked();
    void on_tabWidget_tabBarClicked(int index);
    void on_back_clicked();
    void on_home_clicked();
    void on_tabWidget_currentChanged(int index);

    void on_tableWidget_1_doubleClicked(const QModelIndex &index);
    void on_tableWidget_2_doubleClicked(const QModelIndex &index);
    void on_tableWidget_3_doubleClicked(const QModelIndex &index);
    void on_tableWidget_4_doubleClicked(const QModelIndex &index);
    void on_tableWidget_5_doubleClicked(const QModelIndex &index);
    void on_tableWidget_6_doubleClicked(const QModelIndex &index);

    void pressCancel(void);
    void pressReceived(void);
    void pressComment(void);
    void setPoint(int);


    void on_pushButton_edit_clicked();

private:

    Ui::UserInterface *ui;
    QSqlQuery *query;
    DatabaseConnection *db;
    User *user;

    MyMarket *manage_stock;
    HomePage* home;
    MainWindow *login;
    orderINFO* infoWD;
    Comment* comWD;
    bool newInfo;

    //page flags
    bool save;
    bool edit_username, edit_account, edit_phone, edit_PWD;
};

#endif // USERINTERFACE_H
