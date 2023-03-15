#include "orderinfo.h"
#include "ui_orderinfo.h"

orderINFO::orderINFO(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::orderINFO)
{
    ui->setupUi(this);
    this->setWindowTitle("Order Detail");

    ui->lineEdit->setEnabled(0);
    //table initial
    ui->table->setColumnCount(4);
    QStringList q;
    q.push_back("PRODUCT");
    q.push_back("PRICE");
    q.push_back("NUMBER");
    q.push_back("TOTAL");

    ui->table->horizontalHeader()->setDisabled(1);
    ui->table->setHorizontalHeaderLabels(q);
    ui->table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->table->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->table->verticalHeader()->setVisible(false);
    ui->table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->table->setSelectionMode(QAbstractItemView::NoSelection);

}

orderINFO::~orderINFO()
{
    delete ui;
}
void orderINFO::setTable(itemList *item, int& sub, int& sf, QString& addr){
    ui->table->clearContents();
    ui->table->setRowCount(0);
    itemList::iterator it = item->begin();
    sub = 0, sf = 0;
    int curTotal, curSF, i = 0;
    enum{pd, price, num, total};
    addr = (*it)->getAddr();
    QTableWidgetItem *a;
    while(it!=item->end()){
        ui->table->insertRow(i);
        curTotal = (*it)->getPrice()*(*it)->getNum();
        curSF = (*it)->getSF();
        sf = max(sf, curSF);
        sub+=curTotal;

        a = new QTableWidgetItem((*it)->getName());
        a->setTextAlignment(Qt::AlignCenter);
        ui->table->setItem(i, pd, a);
        a = new QTableWidgetItem(QString::number((*it)->getPrice()));
        a->setTextAlignment(Qt::AlignCenter);
        ui->table->setItem(i, price, a);
        a = new QTableWidgetItem(QString::number((*it)->getNum()));
        a->setTextAlignment(Qt::AlignCenter);
        ui->table->setItem(i, num, a);
        a = new QTableWidgetItem(QString::number(curTotal));
        a->setTextAlignment(Qt::AlignCenter);
        ui->table->setItem(i, total, a);
        i++;
        it++;
    }
}
void orderINFO::pageSetting(itemList *item){
    int subtotal, sf, total;
    QString addr;
    setTable(item, subtotal, sf, addr);
    total = subtotal+sf;

    ui->label_subtotal->setText(QString::number(subtotal));
    ui->label_SF->setText(QString::number(sf));
    ui->label_total->setText(QString::number(total));
    ui->lineEdit->setText(addr);
}
