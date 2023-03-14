#ifndef ORDERDETAIL_H
#define ORDERDETAIL_H

#include <QWidget>
#include <QSet>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDateTime>
#include "cartwd.h"
#include "cartitem.h"
#include "homepage.h"
#include "ordersuccess.h"
class CartWD;
class HomePage;
class orderSuccess;
namespace Ui {
class orderDetail;
}

class orderDetail : public QWidget
{
    Q_OBJECT
    CartWD *lastCartWD;

public:
    explicit orderDetail(QWidget *parent = nullptr);
    ~orderDetail();
    void passHome(HomePage* h);
    void passQuery(QSqlQuery* q){query = q;}
    void passOrderItem(itemSet s){curOrderitem = s;}
    void passCartWD(CartWD* wd);
    void setPage(QString buyerName, QString sellerName);
    void updateStock(int orderID);

private slots:
    void on_pushButton_place_clicked();

private:
    Ui::orderDetail *ui;
    itemSet curOrderitem;
    QSqlQuery* query;

    HomePage *home;
    orderSuccess *congrats;
};

#endif // ORDERDETAIL_H
