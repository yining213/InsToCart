#include "shippingwd.h"
#include "ui_shippingwd.h"

shippingWD::shippingWD(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::shippingWD)
{
    ui->setupUi(this);

    //ui->comboBox->setItemData(0, 0,  Qt::UserRole - 1);
    //ui->comboBox->setDisabled(1);

    //table initial
    ui->table->setColumnCount(3);
    QStringList q;
    q.push_back("Order ID");
    q.push_back("Seller");
    q.push_back("");

    ui->table->horizontalHeader()->setDisabled(1);
    ui->table->setHorizontalHeaderLabels(q);
    ui->table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->table->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->table->verticalHeader()->setVisible(false);
    ui->table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->table->setSelectionMode(QAbstractItemView::NoSelection);
}

shippingWD::~shippingWD()
{
    delete ui;
}
void shippingWD::setPage(){
    loadOrder();
    displayTable(-1);
}
void shippingWD::loadOrder(){
    query->exec("use userdata");
    list.clear();
    QString take = "select orderID, sellerName from orders where placed = 1 and state = 1;";
    //qDebug()<<take;
    query->exec(take);

    while(query->next()){
        list.insert(query->value(0).toInt(), query->value(1).toString());
    }
}
void shippingWD::pressArr(void){
    int id = ui->table->item(ui->table->currentRow(), 0)->text().toInt();
    //qDebug()<<"order id = "<<id;
    if(list.find(id)!=list.end()) list.erase(list.find(id));
    ui->table->removeRow(ui->table->currentRow());
    query->exec("update orders set state = 2, arrivedDate = NOW() where orderID = " + QString::number(id));
}
void shippingWD::displayTable(int id){
    ui->table->clearContents();
    ui->table->setRowCount(0);
    int row = 0;
    QTableWidgetItem *a;
    if(id==-1){
        //display total
        for(auto it = list.begin(); it!=list.end();it++){
            ui->table->insertRow(row);
            a = new QTableWidgetItem(QString::number(it.key()), Qt::AlignCenter);
            a->setTextAlignment(Qt::AlignCenter);
            ui->table->setItem(row, 0, a);
            a = new QTableWidgetItem(it.value(), Qt::AlignCenter);
            a->setTextAlignment(Qt::AlignCenter);
            ui->table->setItem(row, 1, a);
            QPushButton* arr = new QPushButton("Arrived");
            connect(arr, SIGNAL(clicked()), this, SLOT(pressArr()));
            ui->table->setCellWidget(row, 2, arr);
            ++row;
        }
    }
    else if(list.find(id)!=list.end()){
        ui->table->insertRow(row);
        a = new QTableWidgetItem(QString::number(id), Qt::AlignCenter);
        a->setTextAlignment(Qt::AlignCenter);
        ui->table->setItem(row, 0, a);
        a = new QTableWidgetItem(list.find(id).value(), Qt::AlignCenter);
        a->setTextAlignment(Qt::AlignCenter);
        ui->table->setItem(row, 1, a);
        QPushButton* arr = new QPushButton("Arrived");
        connect(arr, SIGNAL(clicked()), this, SLOT(pressArr()));
        ui->table->setCellWidget(row, 2, arr);
    }
}

void shippingWD::on_lineEdit_textChanged(const QString &arg1)
{
    if(arg1.size()==0){
        displayTable(-1);
    }
    else displayTable(arg1.toInt());
}

