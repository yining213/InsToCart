#ifndef USER_H
#define USER_H

#include <QString>
#include <QDate>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QTableWidget>
#include <QList>
#include "order.h"
#include "cart.h"
#include "commodity.h"
#include "cartitem.h"
class cartItem;
class Order;
class Cart;
class Commodity;
typedef QList<cartItem*> itemList;
typedef QMap<int, itemList> orderMap ;
struct PersonalData{
    QString name;
    int gender;
    QString phone;
    QDate birthday;
};
class User
{
private:
    QSqlQuery* query;
    QString ID;
    QString account; //email
    QString password;
    PersonalData personalData;
    bool authority;

    //buyer
    Order *order;
    Cart* cart;

    //seller
    QList<Order*> sellerOrder;
public:
    User();
    //personal
    void setID(int id){ID = QString::number(id);}
    QString getID(void){return ID;}
    void setAccount(QString);
    QString getAccount(void){return account;};
    void setPWD(QString);
    void changePWD(QString);
    QString getPWD(void){return password;};
    void setPersonalData(PersonalData);
    PersonalData getPersonalData(void){return personalData;}
    int getGender(void){return personalData.gender;}
    QString getPhone(void){return personalData.phone;}
    QString getName(void){return personalData.name;}
    QDate getBirthday(void){return personalData.birthday;}
    void changePersonalData(PersonalData);
    void setAuthority(bool);
    void setOrder(void);
    void setTable(int typeIndex, QTableWidget* table);
    void clearOrder(int index);

    //operational
    bool isSeller(void){return authority;}

    enum sqlTable{sID, sName, sGender, sAccount, sPWD, sPhone, sBirthday};

    //buyer
    bool SellerInCart(QString sellerID);
    void addItemToCart(Commodity* pd, int num);
    void loadOrders(int state);
    itemList* getItemList(int typeindex, int id);
    orderMap getorderMap(int typeIndex);

    //sql
    void setQuery(QSqlQuery* q){query = q;}
};
int checkPWDformat(QString input);
bool checkAccountformat(QString input);
bool checkPhoneformat(QString input);
bool isDigit(QChar a);
bool isChar(QChar a);
//int checkPersonalDataformat(PersonalData input, QSqlQuery* query);
#endif // USER_H
