#include "pwdgraphicsview.h"

PWDGraphicsView::PWDGraphicsView(QWidget *parent):QGraphicsView(parent)
{
    scene = new QGraphicsScene(0, 0, 598, 358);
    pixmap = new QPixmap(598, 358);
    pixmap->fill(QColor(31, 78, 121, 255));

    painter = new QPainter(pixmap);
    item = new QGraphicsPixmapItem(*pixmap);

    scene->addItem(item);
    this->setScene(scene);
}
void PWDGraphicsView::setAccount(QString a){
    qDebug()<<"set account\n";
    account = a;
}
