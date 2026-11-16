#include "sqlitebackend.h"
#include <QDir>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

bool SQLiteBackend::open(const QString &dataDirectory, QString *error) {
    if (!QDir().mkpath(dataDirectory)) {
        *error = "Cannot create data directory: " + dataDirectory;
        return false;
    }
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QDir(dataDirectory).filePath("instocart.sqlite"));
    if (!db.open()) { *error = db.lastError().text(); return false; }
    QSqlQuery foreignKeys;
    if (!foreignKeys.exec("PRAGMA foreign_keys = ON")) {
        *error = foreignKeys.lastError().text(); return false;
    }
    return true;
}
