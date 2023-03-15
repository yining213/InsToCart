#ifndef CHANGEPWD_H
#define CHANGEPWD_H

#include <QMainWindow>
#include <QSqlResult>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QKeyEvent>
#include "user.h"
#include "mainwindow.h"
#include "databaseconnection.h"
class MainWindow;
namespace Ui { class ChangePWD;}

class ChangePWD : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChangePWD(QWidget *parent = nullptr);
    ~ChangePWD();

    void passQuery(QSqlQuery* qr){query = qr;}
    void passUser(User* copyUser){user = copyUser;}

    void printAlert(int num);
    void passDB(DatabaseConnection* p){db=p;}

private slots:
    void keyPressEvent(QKeyEvent*)override;
    void on_pushButton_next_clicked();

private:
    Ui::ChangePWD *ui;
    QSqlQuery *query;

    //operational
    User *user;
    bool new_user;

    MainWindow* nextWD;
    bool new_nextWD;
    DatabaseConnection* db;
};

#endif // CHANGEPWD_H
