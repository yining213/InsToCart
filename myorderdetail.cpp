#include "myorderdetail.h"
#include "ui_myorderdetail.h"

MyOrderDetail::MyOrderDetail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyOrderDetail)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QStringList headerList={"NAME", "NUMBER", "PRICE / PER", "TOTAL PRICE"};
    ui->tableWidget->setHorizontalHeaderLabels(headerList);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MyOrderDetail::~MyOrderDetail()
{
    delete ui;
}

void MyOrderDetail::update(){
    QMap<int,int>::iterator it;
    enum{NAME, NUMBER, PRICE, TOTAL};
    int m_price=0,ship_price=0;
    ui->tableWidget->setRowCount(0);
    for(it = order->getOrderPD().begin(); it!=order->getOrderPD().end();it++){
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        int curr = ui->tableWidget->rowCount()-1;
        Commodity c = db->search(it.key());
        ui->tableWidget->setItem(curr, NAME, new QTableWidgetItem(c.getName()));
        ui->tableWidget->setItem(curr, NUMBER, new QTableWidgetItem(QString::number(it.value())));
        ui->tableWidget->setItem(curr, PRICE, new QTableWidgetItem(QString::number(c.getPrice())+"$"));
        ui->tableWidget->setItem(curr, TOTAL, new QTableWidgetItem(QString::number(c.getPrice()*it.value()+order->getShipping_fee())+"$"));
        //ui->tableWidget->setCellWidget(curr, TOTAL, new QSpinBox());


        m_price += c.getPrice()*it.value();
        if(c.getSF()>ship_price)
            ship_price = order->getShipping_fee();
    }
    ui->address->setText(order->getAddress());
    ui->m_price->setText(QString::number(m_price)+"$");
    ui->ship_price->setText(QString::number(ship_price)+"$");
    ui->total_price->setText(QString::number(m_price+ship_price)+"$");
}



