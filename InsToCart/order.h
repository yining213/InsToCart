#ifndef ORDER_H
#define ORDER_H

#include <QList>
#include <QMap>
#include <QString>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QTableWidget>
#include <QDate>
#include "commodity.h"
#include "cartitem.h"

class cartItem;
class Commodity;
typedef QList<cartItem*> itemList;
typedef QMap<int, itemList> orderMap ;
class Order
{
public:
    enum sqlOrders{
        s_buyerID,
        s_buyerName,
        s_sellerID,
        s_sellerName,
        s_itemID,
        s_itemName,
        s_stock,
        s_price,
        s_number,
        s_SF,
        s_total,
        s_placed, //to identify whether the product is in the cart or in an order
        s_state, //once the seller takes the packge to the distribution center, this state would change to true
        s_placedDate,
        s_shipDate,
        s_arrivedDate,
        s_receivedDate,
        s_completedDate,
        s_canceledDate,
        s_orderID,
        s_orderAddr
    };
    struct DateData{
        QDateTime placed;
        QDateTime ship;
        QDateTime arrived;
        QDateTime received;
        QDateTime completed;
        QDateTime canceled;
    };
    enum order_state{
        placed,
        shipping,
        arrived,
        to_rate,
        completed,
        canceled
    };
    Order();
    //void addOrderPD(Commodity* orderPD);
    //QString getSellerID(void){return sellerID;}
    //QString getBuyerID(void){return buyerID;}
    //void addItem(int new_itemID, int num, int price);

    //MIMI version
    void downloadFromsql(QSqlQuery* query, QString name, int state);
    void displayTotalOrder(int index);
    void copyTable(QSqlQuery* query, int typeIndex, QTableWidget* table);
    void orderClear(int index);
    itemList* getItemset(int typeindex, int id);
    QString getSellerID(void){return sellerID;}
    QString getBuyerID(void){return buyerID;}
    void addItem(int new_itemID, int num, int price);
    void addOrderPD(int itemID,int number){
        orderPD.insert(itemID, number);
    }
    orderMap getorderMap(int typeIndex){return type[typeIndex];}


    QMap<int, int> &getOrderPD();
    void setOrderPD(const QMap<int, int> &newOrderPD);
    void setBuyerID(const QString &newBuyerID);
    void setSellerID(const QString &newSellerID);
    int getTotal() const;
    void setTotal(int newTotal);
    void addTotal(int);
    bool getPlaced() const;
    void setPlaced(bool newPlaced);
    unsigned int getState() const;
    QString getStateName();
    void setState(unsigned int newState);
    void setDateData(DateData newDateData);
    const QString &getAddress() const;
    void setAddress(const QString &newAddress);
    const QString &getBuyerName() const;
    void setBuyerName(const QString &newBuyerName);
    const QString &getSellerName() const;
    void setSellerName(const QString &newSellerName);
    const QString &getItemName() const;
    void setItemName(const QString &newItemName);
    int getPrice() const;
    void setPrice(int newPrice);
    int getShipping_fee() const;
    void setShipping_fee(int newShipping_fee);

    void setPlaceDate(QDateTime d){dateData.placed = d;}
    void setShipDate(QDateTime d){dateData.ship = d;}
    void setArrivedDate(QDateTime d){dateData.arrived = d;}
    void setReceiveDate(QDateTime d){dateData.received = d;}
    void setCompletedDate(QDateTime d){dateData.completed = d;}
    void setCanceldDate(QDateTime d){dateData.canceled = d;}


    int getItemID() const;
    void setItemID(int newItemID);

    int getOrderID() const;
    void setOrderID(int newOrderID);

private:
    QMap<int,int> orderPD; //store itemID and number
    QString buyerID, sellerID;
    QString buyerName, sellerName, itemName;
    int price;
    int shipping_fee;
    int total;
    bool isplaced;
    unsigned int state;
    QString address;
    int orderID;
    DateData dateData;

    //MIMI version
    orderMap type[7];

};

#endif // ORDER_H
