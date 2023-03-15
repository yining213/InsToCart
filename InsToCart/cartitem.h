#ifndef CARTITEM_H
#define CARTITEM_H

#include <QSqlQuery>
#include <QSqlDatabase>

#include "cart.h"
#include "commodity.h"
class Commodity;
class Cart;
class cartItem
{
public:
    struct DateData{
        QDateTime placed;
        QDateTime ship;
        QDateTime received;
        QDateTime arrived;
        //QDateTime toRate;
        QDateTime completed;
        QDateTime canceled;
    };
private:
    friend Cart;
    QString buyerID, sellerID, buyerName, sellerName, name, description, address;
    int itemID, price, num, total, shipping_fee, stock, orderID;
    DateData date;

public:

    cartItem();
    //basic function
    //set
    void setName(QString itemName){name = itemName;}
    void setItemID(int id){itemID = id;}
    void setPrice(int p){price = p;}
    void setShippingFee(int s){shipping_fee = s;}
    void setStock(int s){stock = s;}
    void setSellerID(QString s){sellerID = s;}
    void setSellerName(QString name){sellerName = name;}
    void setBuyerID(QString s){buyerID = s;}
    void setBuyerName(QString name){buyerName = name;}
    void setDescript(QString s){description = s;}
    void setOrderID(int n){orderID = n;}
    void setAddr(QString addr){address = addr;}
    void setDate(DateData d);

    //get
    QString getName(){return name;}
    int getNum(){return num;}
    int getTotal(){return total;}
    int getItemID(){return itemID;}
    int getPrice(){return price;}
    int getSF(){return shipping_fee;}
    int getStock(){return stock;}
    QString getSellerID(){return sellerID;}
    QString getSellerName(){return sellerName;}
    QString getBuyerID(){return buyerID;}
    QString getBuyerName(){return buyerName;}
    QString getDescript(){return description;}
    int getOrderID(){return orderID;}
    QString getAddr(void){return address;}
    DateData getDate(void){return date;}

    void copyData(QSqlQuery* query);
    void setNum(int n){num = n;}
    void setTotal(void){total = num * price;}

};

#endif // CARTITEM_H
