#ifndef CARTWD_H
#define CARTWD_H

#include <QWidget>
#include <QLabel>
#include <QTabWidget>
#include <QSqlResult>
#include <QVBoxLayout>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QPushButton>
#include <QTableWidget>
#include <QHeaderView>
#include <QDoubleSpinBox>
#include <QSet>
#include <QMap>
#include "orderdetail.h"
#include "homepage.h"
#include "cart.h"
#include "user.h"
#include "databaseconnection.h"
class DatabaseConnection;
class User;
class HomePage;
class Cart;
class orderDetail;
namespace Ui {
class CartWD;
}

class CartWD : public QWidget
{
    Q_OBJECT

public:
    explicit CartWD(QWidget *parent = nullptr);
    ~CartWD();

    void passHome(HomePage* home);
    void passQuery(QSqlQuery* qr){query = qr;}
    void passUser(User* copyUser){user = copyUser;}
    void passDB(DatabaseConnection* p){db = p;}
    void setTab(int index);
    void pageSettings(void);
    void update(void);
    QTableWidget* setTabPage(itemSet);
private slots:
    void pressRemove(void);
    void dsValueChanged(double);
    void on_pushButton_place_clicked();

private:
    Ui::CartWD *ui;
    QSqlQuery* query;
    DatabaseConnection* db;
    User* user;

    Cart *cart;
    bool cartNew;

    orderDetail *orderDetailWD;
    bool orderWD;
    HomePage* home;
};

#endif // CARTWD_H
