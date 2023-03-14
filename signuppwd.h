#ifndef SIGNUPPWD_H
#define SIGNUPPWD_H

#include <QObject>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QKeyEvent>
//#include <QPainter>
#include <QDebug>
#include <QPixmap>
#include <vector>
#include <QVector>
#include <QLabel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDialog>
#include "users.h"
#include "personal_setting.h"
using namespace std;
class Users;
class personal_setting;
namespace Ui {
class signupPWD;
}

class signupPWD : public QDialog
{
    Q_OBJECT
    Users *user;

public:
    explicit signupPWD(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent*)override;
    void passUser(Users* u){user = u;};
    void setInterface(void);
    void passQuery(QSqlQuery* q){query = q;};
    ~signupPWD();

private slots:
    void on_pushButton_clicked();

private:
    Ui::signupPWD *ui;
    QGraphicsScene *scene;
    QPixmap *pixmap;
    QPainter *painter;
    QGraphicsPixmapItem *item;
    QPen pen1;

    QSqlDatabase database;
    QSqlQuery *query;


    personal_setting *ps;
};

#endif // SIGNUPPWD_H
