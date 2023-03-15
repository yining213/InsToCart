#include "cart.h"

Cart::Cart()
{

}
void Cart::intoCart(QSqlQuery *query, Commodity *pd, int num){ //only update database
    query->exec("use userdata");
    //copy buyerName and sellerName
    QString buyerName, sellerName;
    QString get = "select name from users where ID = '" + pd->getBuyerID() + "'";
    query->exec(get);
    //qDebug()<<get;
    if(query->next()) buyerName = query->value(0).toString();
    get = "select name from users where ID = '" + pd->getOwnerID() + "'";
    query->exec(get);
    if(query->next()) sellerName = query->value(0).toString();

    //check whether the same cartItem exist or not
    //select * from orders where placed = 0 and buyerID = '16' and sellerID = '2' and itemID = 20;
    QString take = "select * from orders where placed = 0 and buyerID = '" + pd->getBuyerID() + "' ";
    take +="and sellerID = '" + pd->getOwnerID() + "' ";
    take +="and itemID = " + QString::number(pd->getItemID());
    //qDebug()<<"in addOrder:\ntake = "<<take;
    query->exec(take);

    if(query->next()){
        int postNum;
        if(query->value(Order::sqlOrders::s_number).toInt() + num > query->value(Order::sqlOrders::s_stock).toInt()) postNum = query->value(Order::sqlOrders::s_stock).toInt();
        else postNum = query->value(Order::sqlOrders::s_number).toInt() + num;
        qDebug()<<"postNum = "<<postNum;
        int postTotal = postNum*pd->getPrice();
        //update orders set number = 20, total = 30 where placed = 0 and buyerID = '16' and sellerID = '2' and itemID = 20;
        take = "update orders set number = " + QString::number(postNum) + ", total = " + QString::number(postTotal) + " where placed = 0 and buyerID = '" + pd->getBuyerID() + "' and sellerID = '" + pd->getOwnerID() + "' and itemID = " + QString::number(pd->getItemID());
        //qDebug()<<"take = "<<take;
        query->exec(take);
    }
    else{
        int postTotal = num * pd->getPrice();
        //insert into orders (buyerID, sellerID, itemID, number, total, placed) values('16', '16', 2, 2,2000, 0);
        take = "insert into orders (buyerID, buyerName, sellerID, sellerName, itemID, itemName, number, total, placed, shipping_fee, price, stock) values('" + pd->getBuyerID() + "', '" + buyerName + "', '" + pd->getOwnerID() + "', '" + sellerName + "', " + QString::number(pd->getItemID()) + ", '" + pd->getName() + "', " + QString::number(num) + ", " + QString::number(postTotal) + ", 0, " + QString::number(pd->getSF()) + ", " + QString::number(pd->getPrice()) +", " + QString::number(pd->getStock()) +" )";
        //qDebug()<<take;
        query->exec(take);
    }
    /*
    if(cartList.find(sellerID)!=cartList.end()){
        cartList.find(sellerID).value()->addItem(itemID, num, price);
    }
    else{
        Order *o = new Order;
        o->addItem(itemID, num, price);
        cartList.insert(sellerID, o);
    }
    */
}
bool Cart::sellerExist(QString name){
    if(cartList.find(name)!=cartList.end()) return 1;
    return 0;
}
void Cart::addItemintoCartList(QString seller, cartItem *in){
    if(sellerExist(seller)){
        cartList.find(seller).value().append(in);
    }
    else{
        itemSet* s = new itemSet;
        s->append(in);
        cartList.insert(seller, *s);
    }
}
void Cart::displayCart(){
    qDebug()<<"in display cart: "<<cartList.size();

    cartMap::iterator it = cartList.begin();
    while(it != cartList.end()){
        qDebug()<<it.key();
        itemSet::iterator its = it.value().begin();
        while(its!=it.value().end()){
            qDebug()<<(*its)->getName();
            its++;
        }
        it++;
    }
}
QString Cart::getSellerName(int index){
    cartMap::iterator it = cartList.begin();
    for(int i=0;i<index;i++) it++;
    return it.key();
}
itemSet* Cart::getItemSet(int index){
    cartMap::iterator it = cartList.begin();
    for(int i=0;i<index;i++) it++;
    return &it.value();
}
int Cart::getItemID(int row, int col){
    cartMap::iterator it = cartList.begin();
    for(int i=0;i<row;i++) it++;
    return (*(it.value().begin()+col))->getItemID();
}
int Cart::getItemPrice(int row, int col){
    cartMap::iterator it = cartList.begin();
    for(int i=0;i<row;i++) it++;
    return (*(it.value().begin()+col))->getPrice();
}
void Cart::removeItemfromCart(QSqlQuery* query,  int row, int col){
    cartMap::iterator it = cartList.begin();
    for(int i=0;i<row;i++) it++;
    QString buyerID = it.value().at(0)->getBuyerID();
    QString sellerID = it.value().at(0)->getSellerID();
    QString itemID = QString::number(it.value().at(0)->getItemID());
    QString take = "DELETE FROM orders where buyerID = '"+buyerID+"' and sellerID = '"+sellerID+"' and itemID = "+itemID;
    query->exec(take);
    it.value().erase(it.value().begin()+col);

    //remove from sql
    if(it.value().size()==0) cartList.erase(it);
}
QString Cart::getBuyerName(int row){
    cartMap::iterator it = cartList.begin();
    for(int i=0;i<row;i++) it++;
    return (*it.value().begin())->getBuyerName();
}
void Cart::clearCart(){
    cartMap::iterator it = cartList.begin();
    while(it!=cartList.end()){
        cartItem* rep;
        itemSet::iterator its = it.value().begin();
        while(its!=it.value().end()){
            rep = *its;
            its++;
            delete rep;
        }
        it.value().clear();
        it++;
    }
    cartList.clear();
}
