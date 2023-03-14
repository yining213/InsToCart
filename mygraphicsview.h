#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

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
#include <QMouseEvent>
#include <QKeyEvent>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
using namespace std;

class MyGraphicsView:public QGraphicsView
{
    Q_OBJECT
    QGraphicsScene *scene1, *scene_PWD;
    QPixmap *pixmap1, *pixmap_PWD;
    QPainter *painter1, *painter_PWD;
    QGraphicsPixmapItem *item1, *item_PWD;
    QPen pen1;

    QSqlDatabase database;
    //QSqlQuery *query;

    QString account;

public:
    MyGraphicsView(QWidget*);
    void passAcount(QString a);
    bool AccountExist(QSqlQuery*);
};

#endif // MYGRAPHICSVIEW_H
