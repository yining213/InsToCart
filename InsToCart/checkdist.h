#ifndef CHECKDIST_H
#define CHECKDIST_H

#include <QDialog>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QSqlQuery>
#include <QSqlDatabase>
#include "shippingwd.h"
class shippingWD;


namespace Ui {
class checkDist;
}

class checkDist : public QDialog
{
    Q_OBJECT

public:
    explicit checkDist(QWidget *parent = nullptr);
    ~checkDist();
    void passQuery(QSqlQuery* q){query=q;}

private slots:
    void on_enter_clicked();
    void keyPressEvent(QKeyEvent*)override;

private:
    Ui::checkDist *ui;
    QSqlQuery* query;

    shippingWD *sh;
};

#endif // CHECKDIST_H
