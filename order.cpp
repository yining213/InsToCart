#include "order.h"

Order::Order()
{
    /*
    buyerID = "0"; sellerID = "0";
    total = 0;
    placed = 0;
    state = 0;
    dateData.ship = dateData.receive = dateData.arrived = dateData.completed = dateData.canceled = QDate(2000,02,22);
    */
}
/*
void Order::addItem(int new_itemID, int num, int price){
    qDebug()<<"addItem in";
    if(orderPD.find(new_itemID)!=orderPD.end()){
        orderPD.find(new_itemID).value()+=num;
    }
    else{
        orderPD.insert(new_itemID,num);
    }
    total += num*price;
    qDebug()<<"addItem end";
}
*/
void Order::downloadFromsql(QSqlQuery* query, QString buyerName, int state){
    orderClear(state);
    int orderID;
    QString take, sellerName;
    query->exec("user userdata");
    take = "select * from orders where placed = 1 and buyerName = '"+buyerName+"' and state = "+QString::number(state);
    //qDebug()<<take;
    query->exec(take);
    cartItem* rep;
    while(query->next()){
        sellerName = query->value(sqlOrders::s_sellerName).toString();
        orderID = query->value(sqlOrders::s_orderID).toInt();
        rep = new cartItem;
        rep->copyData(query);
        if(type[state].find(orderID)!=type[state].end()){//order exists
            type[state].find(orderID).value().append(rep);
        }
        else{//order hasn't existed
            itemList *l = new itemList;
            l->append(rep);
            type[state].insert(orderID,*l);
        }
    }
    //qDebug()<<"in download";
    //displayTotalOrder(state);
}
void Order::displayTotalOrder(int index){
    orderMap::iterator itm = type[index].begin();
    while(itm!=type[index].end()){
        qDebug()<<"orderID = "<<itm.key();
        itemList::iterator itl = itm.value().begin();
        while(itl!=itm.value().end()){
            qDebug()<<(*itl)->getSellerName()<<" "<<(*itl)->getName();
            itl++;
        }
        itm++;
    }
}

void Order::copyTable(QSqlQuery* query, int typeIndex, QTableWidget *table){
    qDebug()<<"in copy table";
    enum{EorderID, Eseller, Etotal, Edate};
    int i = 0;
    QString take;
    int subtotal,sf,total;
    table->setRowCount(0);
    for(orderMap::iterator itm = type[typeIndex].begin(); itm!=type[typeIndex].end(); itm++){
        table->insertRow(i);
        table->setItem(i, Eseller, new QTableWidgetItem((*itm.value().begin())->getSellerName()));
        table->setItem(i, EorderID, new QTableWidgetItem(QString::number(itm.key())));
        take = "SELECT sum(total) FROM orders WHERE orderID = " + QString::number(itm.key());
        query->exec(take);
        if(query->next()) subtotal = query->value(0).toInt(); //qDebug()<<"subtotal = "<<subtotal;
        take = "SELECT max(shipping_fee) FROM orders WHERE orderID = " + QString::number(itm.key());
        query->exec(take);
        if(query->next()) sf = query->value(0).toInt(); //qDebug()<<"sf = "<<sf;
        total = subtotal+sf; //qDebug()<<"total = "<<total;
        table->setItem(i, Etotal, new QTableWidgetItem(QString::number(total)));
        switch(typeIndex){
        case 0:
            table->setItem(i, Edate, new QTableWidgetItem((*itm.value().begin())->getDate().placed.toString("yy.MM.dd hh:mm"))); break;
        case 1:
            table->setItem(i, Edate, new QTableWidgetItem((*itm.value().begin())->getDate().ship.toString("yy.MM.dd hh:mm"))); break;
        case 2:
            table->setItem(i, Edate, new QTableWidgetItem((*itm.value().begin())->getDate().arrived.toString("yy.MM.dd hh:mm"))); break;
        case 3:
            table->setItem(i, Edate, new QTableWidgetItem((*itm.value().begin())->getDate().received.toString("yy.MM.dd hh:mm"))); break;
        case 4:
            table->setItem(i, Edate, new QTableWidgetItem((*itm.value().begin())->getDate().completed.toString("yy.MM.dd hh:mm"))); break;
        case 5:
            table->setItem(i, Edate, new QTableWidgetItem((*itm.value().begin())->getDate().canceled.toString("yy.MM.dd hh:mm"))); break;
        }
        i++;
    }
}

void Order::orderClear(int index){
    orderMap::iterator it = type[index].begin();
    while(it!=type[index].end()){
        itemList::iterator itl = it.value().begin();
        while(itl!=it.value().end()){
            delete *itl;
            itl++;
        }
        it.value().clear();
        it++;
    }
    type[index].clear();
}
itemList* Order::getItemset(int typeindex, int id){
    return &type[typeindex].find(id).value();
}
QMap<int, int> &Order::getOrderPD()
{
    return orderPD;
}

void Order::setOrderPD(const QMap<int, int> &newOrderPD)
{
    orderPD = newOrderPD;
}

void Order::setBuyerID(const QString &newBuyerID)
{
    buyerID = newBuyerID;
}

void Order::setSellerID(const QString &newSellerID)
{
    sellerID = newSellerID;
}

int Order::getTotal() const
{
    return total;
}

void Order::setTotal(int newTotal)
{
    total = newTotal;
}
void Order::addTotal(int t){
    total+=t;
}

bool Order::getPlaced() const
{
    return isplaced;
}

void Order::setPlaced(bool newPlaced)
{
    isplaced = newPlaced;
}

unsigned int Order::getState() const
{
    return state;
}
QString Order::getStateName(){
    if(state == 0)
        return "placed";
    if(state==1)
        return "shipping";
    if(state==2)
        return "arrived";
    if(state==3)
        return "to_rate";
    if(state==4)
        return "completed";
    if(state==5)
        return "canceled";

    return QString();
}

void Order::setState(unsigned int newState)
{
    state = newState;
}

void Order::setDateData(DateData newDateData)
{
    dateData = newDateData;
}

const QString &Order::getAddress() const
{
    return address;
}

void Order::setAddress(const QString &newAddress)
{
    address = newAddress;
}

const QString &Order::getBuyerName() const
{
    return buyerName;
}

void Order::setBuyerName(const QString &newBuyerName)
{
    buyerName = newBuyerName;
}

const QString &Order::getSellerName() const
{
    return sellerName;
}

void Order::setSellerName(const QString &newSellerName)
{
    sellerName = newSellerName;
}

const QString &Order::getItemName() const
{
    return itemName;
}

void Order::setItemName(const QString &newItemName)
{
    itemName = newItemName;
}

int Order::getPrice() const
{
    return price;
}

void Order::setPrice(int newPrice)
{
    price = newPrice;
}

int Order::getShipping_fee() const
{
    return shipping_fee;
}

void Order::setShipping_fee(int newShipping_fee)
{
    shipping_fee = newShipping_fee;
}

int Order::getOrderID() const
{
    return orderID;
}

void Order::setOrderID(int newOrderID)
{
    orderID = newOrderID;
}
