#include "mygraphicsview.h"

MyGraphicsView::MyGraphicsView(QWidget *parent):QGraphicsView(parent)
{
    scene1 = new QGraphicsScene(0, 0, 598, 358);
    pixmap1 = new QPixmap(598, 358);
    pixmap1->fill(QColor(31, 78, 121, 255));
    //pixmap1->fill(QColor(255, 78, 121, 255));
    painter1 = new QPainter(pixmap1);
    item1 = new QGraphicsPixmapItem(*pixmap1);

    scene1->addItem(item1);
    this->setScene(scene1);
}

void MyGraphicsView::passAcount(QString a){
    account = a;
}
/*
void MyGraphicsView::keyPressEvent(QKeyEvent *event){

    if(event->key() == Qt::Key_Enter){
        QString take = "select * from users where account = '" + account +"'";
        qDebug()<<take;
        query->exec(take);
    }
}
*/
