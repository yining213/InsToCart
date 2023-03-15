#include "orderdetail.h"
#include "ui_orderdetail.h"

orderDetail::orderDetail(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::orderDetail)
{
    ui->setupUi(this);
    this->setWindowTitle("Order Detail");


}

orderDetail::~orderDetail()
{
    delete ui;
}
void orderDetail::passHome(HomePage *h){
    home = h;
}
void orderDetail::setPage(QString buyerName, QString sellerName){
    this->setWindowTitle("Order Details");
    int merSubtotal, sf, total;
    QString take = "SELECT sum(total) FROM orders WHERE placed = 0 and buyerName = '"+buyerName+"' and sellerName = '"+sellerName+"'";
    query->exec(take);
    if(query->next()) merSubtotal = query->value(0).toInt();
    take = "SELECT max(shipping_fee) FROM orders WHERE placed = 0 and buyerName = '"+buyerName+"' and sellerName = '"+sellerName+"'";
    query->exec(take);
    if(query->next()) sf = query->value(0).toInt();
    total = merSubtotal + sf;
    ui->label_subtotal->setText("$ " +QString::number(merSubtotal));
    ui->label_SF->setText("$ " +QString::number(sf));
    ui->label_total->setText("$ " +QString::number(total));
}

void orderDetail::on_pushButton_place_clicked()
{
    query->exec("use userdata");
    int maxOrderID;
    QString take = "SELECT max(orderID) from orders";
    query->exec(take);
    if(query->next()) maxOrderID = query->value(0).toInt()+1;


    QString addr = ui->lineEdit->text();
    take = "update orders set placedDate = NOW(), orderID = "+ QString::number(maxOrderID)+", address = '" + addr + "', placed = 1 , state = 0 where placed = 0 and buyerName = '" + (*curOrderitem.begin())->getBuyerName() +"' and sellerName = '" +(*curOrderitem.begin())->getSellerName()+"'";
    //qDebug()<<take;
    query->exec(take);
    updateStock(maxOrderID);

    this->close();

    congrats = new orderSuccess;
    congrats->show();
    home->initial();
    lastCartWD->update();
}

void orderDetail::passCartWD(CartWD *wd){
    lastCartWD = wd;
}
void orderDetail::updateStock(int orderID){
    query->exec("use userdata");
    QMap<int, int> idandnum;
    QString take = "select itemID, number from orders where orderID = " + QString::number(orderID);
    query->exec(take);
    while(query->next()){
        idandnum.insert(query->value(0).toInt(), query->value(1).toInt());
    }
    query->exec("use productsdb;");
    for(QMap<int,int>::iterator it = idandnum.begin();it!=idandnum.end();it++){
        take = "update class set stock = stock - " + QString::number(it.value()) + " where itemID = " + QString::number(it.key());
        //qDebug()<<take;
        query->exec(take);
    }
    //take = "delete from class where stock<=0";
    //query->exec(take);
    query->exec("use userdata");
}

