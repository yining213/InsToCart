#include "cartitem.h"

cartItem::cartItem()
{

}
void cartItem::copyData(QSqlQuery *query){
    setBuyerID(query->value(Order::sqlOrders::s_buyerID).toString());
    buyerName = query->value(Order::sqlOrders::s_buyerName).toString();
    setSellerID(query->value(Order::sqlOrders::s_sellerID).toString());
    sellerName = query->value(Order::sqlOrders::s_sellerName).toString();
    setItemID(query->value(Order::sqlOrders::s_itemID).toInt());
    setName(query->value(Order::sqlOrders::s_itemName).toString());
    setPrice(query->value(Order::sqlOrders::s_price).toInt());
    setNum(query->value(Order::sqlOrders::s_number).toInt());
    setTotal();
    setOrderID(Order::sqlOrders::s_orderID);
    setStock(query->value(Order::sqlOrders::s_stock).toInt());
    setShippingFee(query->value(Order::sqlOrders::s_SF).toInt());
    setAddr(query->value(Order::sqlOrders::s_orderAddr).toString());
    DateData rep;
    rep.placed = query->value(Order::sqlOrders::s_placedDate).toDateTime();
    rep.ship = query->value(Order::sqlOrders::s_shipDate).toDateTime();
    rep.arrived = query->value(Order::sqlOrders::s_arrivedDate).toDateTime();
    rep.received = query->value(Order::sqlOrders::s_receivedDate).toDateTime();
    rep.completed = query->value(Order::sqlOrders::s_completedDate).toDateTime();
    rep.canceled = query->value(Order::sqlOrders::s_canceledDate).toDateTime();
    setDate(rep);
}
void cartItem::setDate(DateData d){
    date.placed = d.placed;
    date.ship = d.ship;
    date.arrived = d.arrived;
    date.received = d.received;
    date.completed = d.completed;
    date.canceled = d.canceled;
}
