#ifndef SELLER_H
#define SELLER_H

#include <QList>
#include "buyer.h"
#include "order.h"

class Buyer;
class Order;
class Seller:public Buyer
{

public:
    Seller();
};

#endif // SELLER_H
