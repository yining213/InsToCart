#ifndef ORDERINFO_H
#define ORDERINFO_H

#include <QWidget>
#include "cartitem.h"
class cartItem;
namespace Ui {
class orderINFO;
}

class orderINFO : public QWidget
{
    Q_OBJECT

public:
    explicit orderINFO(QWidget *parent = nullptr);
    ~orderINFO();

    void pageSetting(itemList* item);
    void setTable(itemList* item, int&, int&, QString&);

private:
    Ui::orderINFO *ui;
};

#endif // ORDERINFO_H
