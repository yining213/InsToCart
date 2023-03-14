#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <QDebug>
#include <QSqlResult>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "commodity.h"

class DatabaseConnection
{
public:
    DatabaseConnection(QString dbname);
    void insertData(Commodity &c);
    void del(int id);
    void exec(QString e);
    void printerr();
    bool next();
    QVariant getValue(int idx);
    int getSize();
    int getMaxID();
    Commodity search(int id);
    void selectAllItems(){query->exec("use productsdb"); query->exec("select * from class;");}
    Commodity getCurrentItem();
    vector<Commodity> getSelleritems(int ownerID);
    void setQuery(QSqlQuery *q){query = q;}

    const QSqlDatabase &getDatabase() const;
    QSqlQuery *getQuery() const;

private:
    QSqlDatabase database;
    QSqlQuery *query;
};



#endif // DATABASECONNECTION_H
