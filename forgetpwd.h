#ifndef FORGETPWD_H
#define FORGETPWD_H

#include <QMainWindow>
#include <QSqlResult>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QKeyEvent>
#include "user.h"
#include "databaseconnection.h"
#include "mainwindow.h"
#include "changepwd.h"
class ChangePWD;
namespace Ui {
class ForgetPWD;
}

class ForgetPWD : public QMainWindow
{
    Q_OBJECT

public:
    explicit ForgetPWD(QWidget *parent = nullptr);
    ~ForgetPWD();

    void passQuery(QSqlQuery* qr){query = qr;}
    void passUser(User* copyUser){user = copyUser;}
    void passDB(DatabaseConnection* p){db=p;}

private slots:
    void keyPressEvent(QKeyEvent*)override;
    void on_pushButton_next_clicked();

    void on_pushButton_back_clicked();

private:
    Ui::ForgetPWD *ui;
    QSqlQuery *query;

    //operational
    User *user;
    bool new_user;

    ChangePWD* nextWD;
    bool new_nextWD;
    MainWindow *lastWD;
    DatabaseConnection* db;

};

#endif // FORGETPWD_H
