#ifndef ENTER_PWD_H
#define ENTER_PWD_H

#include <QDialog>
#include "users.h"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QSqlResult>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "signup.h"
class Users;
class signup;
class MainWindow;
namespace Ui {
class enter_PWD;
}

class enter_PWD : public QDialog
{
    Q_OBJECT
    Users *user;

public:
    explicit enter_PWD(QWidget *parent = nullptr);
    void passUser(Users*);
    void keyPressEvent(QKeyEvent*)override;
    void passQuery(QSqlQuery* q){query = q;};
    void setInterface(void);
    ~enter_PWD();

private slots:
    void on_pushButton_enter_clicked();


    void on_lineEdit_PWD_textChanged(const QString &arg1);

private:
    Ui::enter_PWD *ui;
    QGraphicsScene *scene;
    QPixmap *pixmap;
    QPainter *painter;
    QGraphicsPixmapItem *item;
    QPen pen1;
    QSqlDatabase database;
    QSqlQuery *query;


    QString pwd;
    int addstar;
    bool mask;
    MainWindow *next;
};

#endif // ENTER_PWD_H
