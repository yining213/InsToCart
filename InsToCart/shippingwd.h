#ifndef SHIPPINGWD_H
#define SHIPPINGWD_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QTableWidget>
#include <QPushButton>
#include <QList>
#include <QMap>

namespace Ui {
class shippingWD;
}

class shippingWD : public QDialog
{
    Q_OBJECT

public:
    explicit shippingWD(QWidget *parent = nullptr);
    ~shippingWD();

    void passQuery(QSqlQuery* q){query=q;}
    void setPage(void);
    void loadOrder(void);
    void displayTable(int type);
private slots:
    void pressArr();
    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::shippingWD *ui;
    QSqlQuery* query;

    QMap<int, QString> list;
};

#endif // SHIPPINGWD_H
