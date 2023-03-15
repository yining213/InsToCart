#ifndef SIGNUPGRAPHICSVIEW_H
#define SIGNUPGRAPHICSVIEW_H

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
using namespace std;
class signupGraphicsView:public QGraphicsView
{
    Q_OBJECT
    QGraphicsScene *scene;
    QPixmap *pixmap;
    QPainter *painter;
    QGraphicsPixmapItem *item;
    QPen pen1;
public:
    signupGraphicsView(QWidget*);
};

#endif // SIGNUPGRAPHICSVIEW_H
