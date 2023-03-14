#ifndef PRODUCTSUBPAGE_H
#define PRODUCTSUBPAGE_H

#include <QWidget>
#include <QDialog>
#include <QSqlResult>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QTableWidget>
#include <QFrame>
#include "user.h"
#include "commodity.h"
class User;
class Commodity;
namespace Ui {
class ProductSubPage;
}

class ProductSubPage : public QWidget
{
    Q_OBJECT

public:
    explicit ProductSubPage(QWidget *parent = nullptr);
    ~ProductSubPage();
    void passQuery(QSqlQuery* qr){query = qr;}
    void passUser(User* copyUser){user = copyUser;}
    void passCom(Commodity* com){this->pd = com;}

    void pageSetting(void);
    QString getPDowner(void);

private slots:
    void on_pushButton_addToCart_clicked();

    void on_doubleSpinBox_valueChanged(double arg1);

private:
    Ui::ProductSubPage *ui;
    QSqlQuery* query;
    User* user;
    Commodity* pd;
};

#endif // PRODUCTSUBPAGE_H
