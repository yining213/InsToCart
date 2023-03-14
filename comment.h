#ifndef COMMENT_H
#define COMMENT_H

#include <QDialog>
#include <QSqlQuery>
#include <QSlider>
#include <QList>
#include <QTextBrowser>
#include <QTextEdit>
#include "userinterface.h"
#include "order.h"
class Order;
class UserInterface;
namespace Ui {
class Comment;
}

class Comment : public QDialog
{
    Q_OBJECT

public:
    enum{
        s_itemID,
        s_itemName,
        s_buyerID,
        s_buyerName,
        s_point,
        s_comment,
        s_avg,
        s_orderID,
        s_completedDate
    };
    struct com{
        int itemID, rating,orderID;
        QString itemName, buyerID, buyerName, comment;
        double average;
        QDateTime completedDate;
    };
    explicit Comment(QWidget *parent = nullptr);
    ~Comment();

    void passQuery(QSqlQuery* q);
    void passUserInterface(UserInterface* u){userI = u;}
    void setPage(int id);
    void insertTosql();
private slots:
    void setPoint(int);
    void on_save_clicked();

private:
    Ui::Comment *ui;
    QSqlQuery *qOrder, *qRate;
    UserInterface* userI;
    int orderID;
    QList<com> comList;
};

#endif // COMMENT_H
