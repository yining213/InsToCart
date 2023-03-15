#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QSqlResult>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "personal_setting.h"
#include "databaseconnection.h"
#include "user.h"
#include "mainwindow.h"
class MainWindow;
class personal_setting;
namespace Ui {class signup;}

class signup : public QDialog
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

    //opeartional
    void keyPressEvent(QKeyEvent*)override;
    void printAlert(int num);

    //data transfer
    void passUser(User* u){user = u;};
    void passDB(DatabaseConnection* p){db=p;}
    void passQuery(QSqlQuery* q){query = q;};

private slots:
    void on_pushButton_next_clicked();  
    void on_pushButton_back_clicked();

private:
    Ui::signup *ui;
    QSqlQuery *query;

    //personal


    //operational
    User *user;
    bool new_user;
    DatabaseConnection* db;

    personal_setting* nextWD;
    bool new_nextWD;
    MainWindow *lastWD;
};

#endif // SIGNUP_H
