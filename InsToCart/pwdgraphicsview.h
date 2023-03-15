#ifndef PWDGRAPHICSVIEW_H
#define PWDGRAPHICSVIEW_H

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
class PWDGraphicsView:public QGraphicsView
{
    Q_OBJECT
    QGraphicsScene *scene;
    QPixmap *pixmap;
    QPainter *painter;
    QGraphicsPixmapItem *item;
    QPen pen1;

    QGraphicsEllipseItem *photo;
    QString account;
public:
    PWDGraphicsView(QWidget*);
    void setAccount(QString);
};

#endif // PWDGRAPHICSVIEW_H
