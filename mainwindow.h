#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QPalette>
#include <QSqlResult>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QFrame>
#include "user.h"
#include "signup.h"
#include "forgetpwd.h"
#include "userinterface.h"
#include "homepage.h"
#include "checkdist.h"
class checkDist;
class HomePage;
class enter_PWD;
class signup;
class User;
class ForgetPWD;
class UserInterface;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void insertDatatoUser(void);
    void loadDtabase(bool);
    void sqlConnection(void);
    void passQuery(QSqlQuery* qr){query = qr;}
    void passUser(User* copyUser){user = copyUser;}
    void passDB(DatabaseConnection* p){db = p;}

    void userSetting(void);

    ~MainWindow();

private slots:
    void keyPressEvent(QKeyEvent*)override;
    void on_pushButton_signup_clicked();
    void on_pushButton_clicked();

    void on_pushButton_forgetPWD_clicked();

    void on_dist_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase database;
    QSqlQuery *query;
    DatabaseConnection *db;
    signup *signupPage;
    ForgetPWD* forgetPWDPage;

    User *user;
    bool new_user;

    HomePage* nextWD;
    bool new_nextWD;

    checkDist* check;
    static bool sqlInitial;
};

#endif // MAINWINDOW_H
