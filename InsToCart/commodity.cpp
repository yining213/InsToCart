#include "commodity.h"

int Commodity::total = 0;

Commodity::Commodity(){
}
Commodity::Commodity(const Commodity &c){
    itemID = c.itemID;
    name = c.name;
    price = c.price;
    type = c.type;
    shipping_fee = c.shipping_fee;
    stock = c.stock;
    filename = c.filename;
    ownerID = c.ownerID;
    buyerID = c.buyerID;
    description = c.description;
}

Commodity::~Commodity()
{

}

void Commodity::setInfo(QString Name, int ItemID, int Price, int Shipping_fee,QString cate, int Stock, QString Img, QString Des, QString Owner, QString Buyer){
    name = Name;
    itemID = ItemID;
    price = Price;
    shipping_fee = Shipping_fee;
    type = (category)getTypeNum(cate);
    stock = Stock;
    filename = Img;
    description = Des;
    ownerID = Owner;
    buyerID = Buyer;
}

QString Commodity::getType(){
    if(type == food){
        return "food";
    }
    else if(type == clothes){
        return "clothes";
    }
    else if(type == home_living){
        return "home_living";
    }
    else if(type == electric_device){
        return "electric_device";
    }
    return "";
}

QString Commodity::getTypeName(int c){
    if(c==0)
        return "food";
    else if(c==1)
        return "clothes";
    else if(c==2)
        return "home_living";
    else if(c==3)
        return "electric_device";
    return "";
}
int Commodity::getTypeNum(QString t){
    if(t=="food")
        return 0;
    else if(t=="clothes")
        return 1;
    else if(t=="home_living")
        return 2;
    else if(t=="electric_device")
        return 3;
    else
        return -1;
}
