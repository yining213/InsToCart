#include "databaseconnection.h"

DatabaseConnection::DatabaseConnection(QString dbname)
{
    //dbcon();
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("140.113.141.194");
    //database.setHostName("127.0.0.1");
    database.setDatabaseName(dbname); // schema name
    database.setUserName("wangmimi");
    //database.setUserName("root");
    database.setPassword("tsaimailoveyou"); // your password
    database.setPort(3306);
    bool ok = database.open();
    if(ok){
        qDebug()<<"Successful Connection.";

    }else{
        qDebug()<<"Error: Cannot connect!!!";
    }
    query = new QSqlQuery(database);
}
void DatabaseConnection::insertData(Commodity &c){
    QString e = "INSERT INTO class VALUES (";
    QString itemID = QString::number( c.getItemID());
    QString name = c.getName();
    QString price = QString::number(c.getPrice());
    QString shipping_fee = QString::number(c.getSF());
    QString catecory = c.getTypeName(c.getCate());
    QString stock = QString::number(c.getStock());
    QString filename = c.getFilename();
    QString ownerID = c.getOwnerID();
    QString buyerID = c.getBuyerID();
    QString descript = c.getDescript();
    e += itemID + ", ";
    e +=  "'" + name + "', ";
    e += price + ", ";
    e += shipping_fee + ", ";
    e += "'"+catecory+"'" + ", ";
    e += stock + ", ";
    e += "'"+filename+"'"+", ";
    e += "'"+ownerID+"'"+", ";
    e += "'"+buyerID+"'"+", ";
    e += "'"+descript+"'";
    e += ");";
    qDebug()<<e;
    query->exec("use productsdb;");
    query->exec(e);
}
Commodity DatabaseConnection::search(int id){
    Commodity c;
    c.setItemID(id);
    query->exec("use productsdb;");
    query->exec("select * from class where itemID = " + QString::number(id));
    if(query->next()){
        c.setName(query->value(1).toString());
        c.setPrice(query->value(2).toInt());
        c.setShippingFee(query->value(3).toInt());
        c.setCategory(query->value(4).toString());
        c.setStock(query->value(5).toInt());
        c.setFilename(query->value(6).toString());
        c.setOwnerID(query->value(7).toString());
        c.setBuyerID(query->value(8).toString());
        c.setDescript(query->value(9).toString());
    }
    return c;
}

const QSqlDatabase &DatabaseConnection::getDatabase() const
{
    return database;
}

QSqlQuery *DatabaseConnection::getQuery() const
{
    return query;
}
int DatabaseConnection::getSize(){
    qDebug()<<query->size();
    return query->size();
}
int DatabaseConnection::getMaxID(){
    QString e = "SELECT MAX(itemID) AS 'Maximum Value' FROM class;";
    query->exec(e);
    if(query->next())
        return query->value(0).toInt();
    return -1;
}
void DatabaseConnection::del(int id){
    QString delexe = "DELETE FROM class WHERE itemID = ";
    delexe += QString::number(id);
    query->exec("use productsdb;");
    query->exec(delexe);
    qDebug()<<delexe;
    qDebug()<<query->lastError();
}
void DatabaseConnection::exec(QString e){
    query->exec(e);
}
void DatabaseConnection::printerr(){
    qDebug()<<query->lastError();
}
bool DatabaseConnection::next(){
    return (query->next());
}
QVariant DatabaseConnection::getValue(int idx){
    return query->value(idx);
}
Commodity DatabaseConnection::getCurrentItem()
{
    Commodity item;
    item.setItemID(query->value(0).toInt());
    item.setName(query->value(1).toString());
    item.setPrice(query->value(2).toInt());
    item.setShippingFee(query->value(3).toInt());
    item.setCategory(query->value(4).toString());
    item.setStock(query->value(5).toInt());
    item.setFilename(query->value(6).toString());
    item.setOwnerID(query->value(7).toString());
    item.setBuyerID(query->value(8).toString());
    item.setDescript(query->value(9).toString());
    return item;
}
