#ifndef COMMODITY_H
#define COMMODITY_H

#include <QMainWindow>
//#include <QObject>
#include <QSharedDataPointer>
//#include <QWidget>
#include <QSqlQuery>
#include<iostream>
#include<string>
//#include<stdio.h>
#include "user.h"
using namespace std;
class User;
class Commodity
{
    friend User;
    //Q_OBJECT
public:
    Commodity();
    Commodity(const Commodity &);
    ~Commodity();

    QPixmap *photo;
    enum category{
        food,
        clothes,
        home_living,
        electric_device
    } ;
    enum sqlTable{
        s_itemID,
        s_name,
        s_price,
        s_shipping_fee,
        s_category,
        s_stock,
        s_imagname,
        s_ownerID,
        s_buyerID,
        s_description
    };
    void setName(QString n){name = n;}
    void setCategory(QString t){
        if(t=="food")
            type = food;
        else if(t=="clothes")
            type = clothes;
        else if(t=="home_living")
            type = home_living;
        else if(t=="electric_device")
            type = electric_device;
    }
    void setItemID(int id){itemID = id;}
    void setPrice(int p){price = p;}
    void setShippingFee(int s){shipping_fee = s;}
    void setStock(int s){stock = s;}
    void setFilename(QString s){filename = s;}
    void setOwnerID(QString s){ownerID = s;}
    void setBuyerID(QString s){buyerID = s;}
    void setDescript(QString s){description = s;}

    bool isAvailable();
    QString getType();
    bool onShelf();

    void setInfo(QString, int, int, int, QString, int, QString, QString, QString, QString);
    QString getName(){return name;}
    int getItemID(){return itemID;}
    int getPrice(){return price;}
    int getCate(){return type;}
    int getSF(){return shipping_fee;}
    int getStock(){return stock;}
    int getLatestID(){return total;}
    QString getFilename(){return filename;}
    QString getOwnerID(){return ownerID;}
    QString getBuyerID(){return buyerID;}
    QString getDescript(){return description;}
    void incTotal(){total++;}
    QString getTypeName(int c);
    int getTypeNum(QString);
    static int total;

private:
    int itemID;
    QString name;
    int price;
    enum category type;
    int shipping_fee;
    int stock;
    QString filename;
    QString ownerID;
    QString buyerID;
    QString description;
};


#endif // COMMODITY_H
