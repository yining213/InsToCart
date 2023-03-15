#include "cartwd.h"
#include "ui_cartwd.h"

CartWD::CartWD(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CartWD)
{
    ui->setupUi(this);
    cartNew = 0;
    orderWD = 0;

}

CartWD::~CartWD()
{
    delete ui;
}

QTableWidget* CartWD::setTabPage(itemSet input){
    QTableWidget *table = new QTableWidget;
    table->setColumnCount(5);
    QStringList q;
    q.push_back("ITEM NAME");
    q.push_back("PRICE");
    q.push_back("NUMBER");
    q.push_back("TOTAL");
    q.push_back("EDIT");
    table->horizontalHeader()->setDisabled(1);
    table->setHorizontalHeaderLabels(q);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->verticalHeader()->setVisible(false);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionMode(QAbstractItemView::NoSelection);

    table->setRowCount(0);
    enum{name, price, num, total, remove};
    int i = 0;
    cartItem *c;
    QTableWidgetItem *a;
    for(itemSet::iterator iter = input.begin(); iter!=input.end(); iter++){
        table->insertRow(i);
        c = *iter;

        QDoubleSpinBox *ds = new QDoubleSpinBox;
        ds->setDecimals(0);
        ds->setMinimum(1);
        ds->setMaximum(c->getStock());
        ds->setValue(c->getNum());
        connect(ds, SIGNAL(valueChanged(double)), this, SLOT(dsValueChanged(double)));
        //qDebug()<<c->getName()<<" "<<c->getPrice()<<" "<<c->getNum()<<" "<<c->getTotal();
        a = new QTableWidgetItem(c->getName());
        a->setTextAlignment(Qt::AlignCenter);
        table->setItem(i, name, a);
        a = new QTableWidgetItem(QString::number(c->getPrice()));
        a->setTextAlignment(Qt::AlignCenter);
        table->setItem(i, price, a);
        table->setCellWidget(i, num, ds);
        a = new QTableWidgetItem(QString::number(c->getTotal()));
        a->setTextAlignment(Qt::AlignCenter);
        table->setItem(i, total, a);
        QPushButton *rem = new QPushButton("REMOVE");
        connect(rem, SIGNAL(clicked()), this, SLOT(pressRemove(void)));
        table->setCellWidget(i, remove, rem);
        i++;
    }
    return table;
}
void CartWD::passHome(HomePage *home){
    this->home = home;
}
void CartWD::pageSettings(){
    ui->tabWidget->clear();
    if(!cartNew){
        cart = new Cart;
        cartNew = 1;
    }
    query->exec("use userdata");
    QString take = "select * from orders where placed = 0 and buyerID = '" + user->getID() + "'";
    query->exec(take);
    //qDebug()<<"in page setting: "<<take;
    cartItem *add;
    QString seller;
    int itemID;
    while(query->next()){
        add = new cartItem;
        add->copyData(query);
        seller = add->getSellerName();
        itemID = add->getItemID();
        cart->addItemintoCartList(seller, add);
    }
    int tabNum = cart->getCartListSize();
    if(tabNum==0){
        ui->tabWidget->hide();
        ui->text->show();
        ui->pushButton_place->hide();
    }
    else{
        ui->tabWidget->setEnabled(1);
        ui->text->hide();
        ui->pushButton_place->show();
        ui->tabWidget->addTab(setTabPage(*cart->getItemSet(0)),cart->getSellerName(0));

        for(int i=1;i<tabNum;i++){           
           ui->tabWidget->addTab(setTabPage(*cart->getItemSet(i)),cart->getSellerName(i));
        }
    }

}
void CartWD::update(){
    cart->clearCart();
    cart->displayCart();
    pageSettings();
}
void CartWD::pressRemove(void){
    int tab = ui->tabWidget->currentIndex();
    int index = qobject_cast<QTableWidget*>(ui->tabWidget->widget(tab))->currentRow();
    //qDebug()<<index;

    cart->removeItemfromCart(query, tab, index);
    qobject_cast<QTableWidget*>(ui->tabWidget->widget(tab))->removeRow(index);
    if(qobject_cast<QTableWidget*>(ui->tabWidget->widget(tab))->rowCount()==0){
        ui->tabWidget->removeTab(tab);
    }
    if(ui->tabWidget->count()==0){
        ui->tabWidget->hide();
        ui->text->show();
        ui->pushButton_place->hide();
    }
}
void CartWD::dsValueChanged(double value){
    //cart->displayCart();
    int tab = ui->tabWidget->currentIndex();
    int index = qobject_cast<QTableWidget*>(ui->tabWidget->widget(tab))->currentRow();
    //qDebug()<<tab<<" "<<index;
    QString buyerName = cart->getBuyerName(tab);
    QString sellerName = cart->getSellerName(tab);
    QString itemID = QString::number(cart->getItemID(tab, index));

    int price = cart->getItemPrice(tab, index);
    //qDebug()<<itemID<<" "<<price;
    qobject_cast<QTableWidget*>(ui->tabWidget->widget(tab))->item(index, 3)->setText(QString::number((int)value * price));
    QString take = "update orders set number = " + QString::number((int)value) + ", total = " + QString::number((int)value * price) + " where placed = 0 and buyerName = '" + buyerName+"' and sellerName = '" +sellerName+"' and itemID = " +itemID;
    query->exec(take);

}
void CartWD::on_pushButton_place_clicked()
{
    orderDetailWD = new orderDetail;
    //update();
    int row = ui->tabWidget->currentIndex();
    orderDetailWD->passQuery(query);
    orderDetailWD->passOrderItem(*cart->getItemSet(row));
    orderDetailWD->setPage(cart->getBuyerName(row), cart->getSellerName(row));
    orderDetailWD->passCartWD(this);
    orderDetailWD->passHome(home);
    orderDetailWD->show();
}
void CartWD::setTab(int index){
    ui->tabWidget->setTabEnabled(index,1);
}
