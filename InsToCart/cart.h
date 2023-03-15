#ifndef CART_H
#define CART_H

#include "order.h"
#include "commodity.h"
#include <QList>
#include <QMap>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "cartitem.h"

class Commodity;
class Order;
class cartItem;
typedef QList<cartItem*> itemSet ;
typedef QMap<QString, itemSet > cartMap;

class Cart
{
public:
    Cart();
    ~Cart(){
        cartMap::iterator it = cartList.begin();
        while(it!=cartList.end()){
            itemSet::iterator its = it.value().begin();
            while(its!=it.value().end()){
                delete its;
                its++;
            }
            it.value().clear();
            it++;
        }
    }
    //void addOrder(QString sellerID, int itemID, int num, int price);
    void intoCart(QSqlQuery* query, Commodity* pd, int num);
    bool sellerExist(QString name);
    void addItemintoCartList(QString seller, cartItem* in);
    void removeItemfromCart(QSqlQuery *query, int row, int col);
    void displayCart();
    int getCartListSize(){return cartList.size();}
    QString getSellerName(int index);
    itemSet* getItemSet(int index);
    QString getBuyerName(int row);
    int getItemID(int row, int col);
    int getItemPrice(int row, int col);
    void clearCart(void);

private:
    cartMap cartList; //key is sellerID

};

#endif // CART_H
