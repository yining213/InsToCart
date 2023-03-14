#include "user.h"

User::User()
{
    ID = "0";
    account = "0";
    password = "0";
    authority = 0; //default: buyer
    cart = new Cart;
    order= new Order;
}
void User::setAccount(QString acc){account = acc;}
void User::setPWD(QString pwd){password = pwd;}
void User::changePWD(QString pwd){password = pwd;}
void User::setPersonalData(PersonalData pd){personalData = pd;}
void User::changePersonalData(PersonalData pd){personalData = pd;}
void User::setAuthority(bool au){authority = au;}
bool isDigit(QChar a){ return ('0'<=a && a<='9');}
bool isChar(QChar a){return (('A'<=a && a<='Z')||('a'<=a && a<='z'));}
bool checkAccountformat(QString input){
    //false for not valid account
    if(input.length()==0) return 0;
    for(int i=0;i<input.length();i++){
        if(!(isDigit(input[i]) || isChar(input[i]))) return 0;
    }
    return 1;
}
int checkPWDformat(QString input){
    //1: not enough length, 2: no eng char, 4: no digit
    int alert = 0;
    bool eng = 0, digit = 0;
    if(input.length()<8) alert|=0x01;
    for(int i=0;i<input.length();i++){
        if(!digit && isDigit(input[i])) digit = 1;
        else if(!eng && isChar(input[i]))eng = 1;
        if(eng && digit) break;
    }
    if(!eng) alert|=0x02;
    if(!digit) alert|=0x04;
    //qDebug()<<"alert = "<<alert;
    return alert;
}
/*
int checkPersonalData(PersonalData input, QSqlQuery* query){
     //1: name conflict
     //2: phone number
    int alert = 0;
    QString take = "select * from users where name = '" + input.name +"'";
    query->exec(take);
    if(query->next()) alert|=0x01;
    if(input.phone.length()!=10) alert|=0x02;
    else{
        if(input.phone[0]!='0' && input.phone[1]!='9') alert|=0x02;
        else{
            for(int i=2;i<input.phone.length();i++){
                if(!isDigit(input.phone[i])){
                    alert|=0x02;
                    break;
                }
            }
        }
    }
    return alert;
}
*/
bool checkPhoneformat(QString input){
    if(input.length()!=10 || (input[0]!='0' && input[1]!='9')) return false;
    else{
        for(int i=2;i<input.length();i++){
            if(!isDigit(input[i])){
                return false;
            }
        }
    }
    return true;
}

void User::addItemToCart(Commodity *pd, int num){
    //cart->addOrder(sellerID, itemID, num, price);
    cart->intoCart(query, pd, num);
}
/*
void User::setOrder(void){
    order->downloadFromsql(personalData.name);
    //order->displayTotalOrder();
}
*/
void User::setTable(int typeIndex, QTableWidget *table){
    table->clearContents();
    loadOrders(typeIndex);
    order->copyTable(query, typeIndex, table);
}

void User::clearOrder(int index){
    order->orderClear(index);
}
void User::loadOrders(int state){
    order->downloadFromsql(query, personalData.name, state);
}
itemList* User::getItemList(int typeindex, int id){
    return order->getItemset(typeindex, id);
}
orderMap User::getorderMap(int typeIndex){
    return order->getorderMap(typeIndex);
}
