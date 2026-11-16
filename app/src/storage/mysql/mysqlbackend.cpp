#include "mysqlbackend.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QStringList>

bool MySQLBackend::open(QString *error) {
    if (!QSqlDatabase::drivers().contains("QMYSQL")) {
        *error = "The QMYSQL Qt SQL driver is unavailable. Install the Qt MySQL driver; see docs/mysql-setup.md.";
        return false;
    }
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(qEnvironmentVariable("INSTOCART_MYSQL_HOST", "127.0.0.1"));
    db.setPort(qEnvironmentVariableIntValue("INSTOCART_MYSQL_PORT") > 0
                   ? qEnvironmentVariableIntValue("INSTOCART_MYSQL_PORT") : 3306);
    db.setDatabaseName(qEnvironmentVariable("INSTOCART_MYSQL_DATABASE", "instocart"));
    db.setUserName(qEnvironmentVariable("INSTOCART_MYSQL_USER", "instocart"));
    db.setPassword(qEnvironmentVariable("INSTOCART_MYSQL_PASSWORD"));
    if (!db.open()) { *error = db.lastError().text(); return false; }
    return true;
}
