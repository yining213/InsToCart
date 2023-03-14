#include "comment.h"
#include "ui_comment.h"

Comment::Comment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Comment)
{
    ui->setupUi(this);

    ui->table->setColumnCount(4);
    QStringList q;
    q.push_back("Product");
    q.push_back("");
    q.push_back("Points");
    q.push_back("Comment");

    ui->table->horizontalHeader()->setDisabled(1);
    ui->table->setHorizontalHeaderLabels(q);
    ui->table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->table->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->table->verticalHeader()->setVisible(false);
    ui->table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->table->setSelectionMode(QAbstractItemView::NoSelection);
}

Comment::~Comment()
{
    delete ui;
}
void Comment::passQuery(QSqlQuery *q){qOrder = qRate = q;}
void Comment::setPage(int id){
    orderID = id;
    qOrder->exec("use userdata;");
    qRate->exec("use userdata;");

    qOrder->exec("select * from orders where orderID = "+QString::number(id));
    qDebug()<<"select * from orders where orderID = "+QString::number(id);
    enum{eName, eSlider, ePoint, eComment};
    ui->table->setRowCount(0);
    int row = 0;
    com rep;
    QSlider* slider;
    QTextEdit* text;
    QTableWidgetItem *a;
    while(qOrder->next()){
        ui->table->insertRow(row);
        rep.itemID = qOrder->value(Order::s_itemID).toInt();
        rep.itemName = qOrder->value(Order::s_itemName).toString();
        //qDebug()<<rep.itemID<<" "<<rep.itemName;
        rep.buyerID = qOrder->value(Order::s_buyerID).toString();
        rep.buyerName = qOrder->value(Order::s_buyerName).toString();
        //qDebug()<<rep.buyerID<<" "<<rep.buyerName;
        rep.rating = 3;
        comList.append(rep);
        a = new QTableWidgetItem(rep.itemName, Qt::AlignHCenter);
        a->setTextAlignment(Qt::AlignCenter);
        ui->table->setItem(row, eName, a);
        a = new QTableWidgetItem("0", Qt::AlignHCenter);
        a->setTextAlignment(Qt::AlignCenter);
        ui->table->setItem(row, ePoint, a);
        slider = new QSlider(Qt::Horizontal);
        QObject::connect(slider, SIGNAL(valueChanged(int)), SLOT(setPoint(int)));
        //slider->setValue(3);
        slider->setMaximum(5);
        slider->setMinimum(0);
        slider->setPageStep(1);
        slider->setSingleStep(1);
        ui->table->setCellWidget(row, eSlider, slider);
        text = new QTextEdit("");
        ui->table->setCellWidget(row, eComment, text);

        ++row;
    }
}
void Comment::setPoint(int point)
{
    int curr = ui->table->currentRow();
    ui->table->item(curr, 2)->setText(QString::number(point));
}
void Comment::on_save_clicked()
{
    int row = 0;
    for(auto it = comList.begin(); it!=comList.end();it++){
        (*it).rating = ui->table->item(row,2)->text().toInt();
        (*it).comment = dynamic_cast<QTextEdit*>(ui->table->cellWidget(row,3))->toPlainText();
        row++;
    }
    insertTosql();
    qOrder->exec("update orders set state = 4, completedDate = NOW() where orderID = "+QString::number(orderID));
    userI->displayTable(3);
    this->close();
}

void Comment::insertTosql(void){
    int avg;
    QString take;
    for(auto it = comList.begin();it!=comList.end();it++){
        take = "insert into rate (itemID, itemName, buyerID, buyerName, point, comment,orderID, completedDate) value("+QString::number((*it).itemID);
        take+= ",'" +(*it).itemName;
        take+= "','"+(*it).buyerID+"','"+(*it).buyerName;
        take+="',"+QString::number((*it).rating);
        take+=",'"+(*it).comment+"',"+QString::number(orderID)+", NOW())";
        qDebug()<<take;
        qRate->exec(take);

        qRate->exec("select avg(point) from rate where itemID = "+QString::number((*it).itemID));
        if(qRate->next()) avg = qRate->value(0).toDouble();
        qRate->exec("update rate set avg = "+QString::number(avg)+" where itemID = "+QString::number((*it).itemID));
    }
}
