#ifndef ORDERSUCCESS_H
#define ORDERSUCCESS_H

#include <QWidget>
#include "homepage.h"

namespace Ui {
class orderSuccess;
}

class orderSuccess : public QWidget
{
    Q_OBJECT

public:
    explicit orderSuccess(QWidget *parent = nullptr);
    ~orderSuccess();

private slots:

private:
    Ui::orderSuccess *ui;
};

#endif // ORDERSUCCESS_H
