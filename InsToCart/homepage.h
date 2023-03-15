#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QMainWindow>
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
#include "databaseconnection.h"
#include <algorithm>
#include <QDoubleSpinBox>
#include "productsubpage.h"
#include "cartwd.h"
class CartWD;
class ProductSubPage;
class enter_PWD;
class signup;
class User;
class ForgetPWD;
class UserInterface;
namespace Ui {
class HomePage;
}

class HomePage : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = nullptr);
    ~HomePage();

    void passQuery(QSqlQuery* qr){query = qr;}
    void passUser(User* copyUser){user = copyUser;}
    void passDB(DatabaseConnection* p){db = p;qDebug()<<"pass!";}
    void setPage(int, vector<Commodity*>*);
    void initial();
    //bool cmpPirce_acc(Commodity a, Commodity b){return a.getPrice()<b.getPrice();}
    //bool cmpPirce_desc(Commodity a, Commodity b){return a.getPrice()>b.getPrice();}

    //productSubPage
    void PassSth(Commodity* pd);
    void passDBptr(void);

private slots:
    void on_settings_clicked();
    void on_pushButton_back_0_clicked();
    void on_pushButton_back_1_clicked();
    void on_pushButton_2_back_clicked();
    void on_pushButton_3_back_clicked();
    void on_pushButton_7_back_clicked();
    void on_pushButton_6_back_clicked();
    void on_pushButton_5_back_clicked();
    void on_pushButton_4_back_clicked();
    void on_left_arrow_clicked();
    void on_right_arrow_clicked();
    void on_up_clicked();
    void on_down_clicked();

    void on_search_comboBox_activated(int index);

    void on_search_clicked();

    void on_plus_0_clicked();

    void on_plus_1_clicked();

    void on_plus_3_clicked();

    void on_plus_2_clicked();

    void on_plus_4_clicked();

    void on_plus_5_clicked();

    void on_plus_6_clicked();

    void on_plus_7_clicked();

    void on_cart_clicked();

    void on_doubleSpinBox_0_valueChanged(double arg1);

    void on_doubleSpinBox_1_valueChanged(double arg1);

    void on_doubleSpinBox_2_valueChanged(double arg1);

    void on_doubleSpinBox_3_valueChanged(double arg1);

    void on_doubleSpinBox_4_valueChanged(double arg1);

    void on_doubleSpinBox_5_valueChanged(double arg1);

    void on_doubleSpinBox_6_valueChanged(double arg1);

    void on_doubleSpinBox_7_valueChanged(double arg1);

private:
    Ui::HomePage *ui;

    QSqlQuery *query;
    DatabaseConnection *db;
    User *user;
    UserInterface* settings;
    vector<Commodity*> items;
    vector<Commodity*> search_cat;
    vector<Commodity*> search_name;
    vector<Commodity*> *curItems;//目前正在做顯示頁面使用的item vector
    vector<QLabel*>name;
    vector<QLabel*>price;
    vector<QLabel*>id;
    vector<QLabel*>img;
    vector<QDoubleSpinBox*>num;
    vector<QPushButton*>plus;
    vector<QFrame*>frame;
    int curPage;
    int curIndex;
    int maxpage;

    //ProductSubPage
    ProductSubPage* pdSub;

    //cart window
    CartWD *cartWD;

};

#endif // HOMEPAGE_H
