#ifndef PERSONAL_SETTING_H
#define PERSONAL_SETTING_H

#include <QObject>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QDebug>
#include <QPixmap>
#include <vector>
#include <QVector>
#include <QLabel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDialog>
#include "mainwindow.h"
#include "databaseconnection.h"
#include "signup.h"
#include "user.h"
using namespace std;
class User;
class MainWindow;
class signup;
struct PersonalData;
int checkPersonalDataformat(PersonalData input, QSqlQuery* query);
namespace Ui {class personal_setting;}

class personal_setting : public QDialog
{
    Q_OBJECT
public:
    explicit personal_setting(QWidget *parent = nullptr);
    ~personal_setting();

    //operational
    void keyPressEvent(QKeyEvent*)override;
    int checkPersonalDataformat(PersonalData input);
    void printAlert(int num);

    //data transfer
    void passUser(User* u){user = u;};
    void passQuery(QSqlQuery* q){query = q;};
    void passDB(DatabaseConnection* p){db=p;}
private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_finish_clicked();

private:
    Ui::personal_setting *ui;
    QSqlQuery *query;

    User *user;
    MainWindow* nextWD;
    bool new_nextWD;
    signup* lastWD;
    DatabaseConnection* db;

    PersonalData rep;
};

#endif // PERSONAL_SETTING_H
