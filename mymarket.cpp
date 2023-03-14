#include <QFont>
#include "mymarket.h"
#include "ui_mymarket.h"
#include "edititem.h"
#include "commodity.h"
#include <vector>
#include <QDate>

MyMarket::MyMarket(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyMarket)
{
    ui->setupUi(this);



    QPalette palette = ui->label->palette();
    QPixmap *add = new QPixmap("./add.png");

    int w = ui->label_4->width();
    int h = ui->label_4->height();

    // set a scaled pixmap to a w x h window keeping its aspect ratio
    ui->label_4->setPixmap(add->scaled(w,h,Qt::KeepAspectRatio,  Qt::SmoothTransformation));
    ui->addProduct->setPalette(palette);

    //set stock table
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QStringList headerList={"ID", "NAME", "STOCK"};
    ui->tableWidget->setHorizontalHeaderLabels(headerList);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    bool value = connect(ui->tableWidget, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(slotRowDoubleClicked(const QModelIndex &)));
    if(!value){
        qDebug()<<"connect fail!";
    }
    ui->searchType->setCurrentIndex(0);
    cur = &myItems;

    //set stack
    ui->stackedWidget->setCurrentIndex(0);
    ui->curpage->setText("Manage Stock");
    connect(ui->managestock, &QPushButton::clicked, this, [=]() {
           //set page to 1
           ui->stackedWidget->setCurrentIndex(0);
       });
    connect(ui->manageorder, &QPushButton::clicked, this, [=]() {
           //set page to 2
           ui->stackedWidget->setCurrentIndex(1);
       });
    ui->manageorder->setAutoFillBackground(true);
    ui->managestock->setAutoFillBackground(true);
    QPalette p= ui->manageorder->palette();
    p.setColor(QPalette::Base, QColor(Qt::white));
    ui->manageorder->setPalette(p);
    ui->manageorder->update();
    ui->managestock->update();
    ui->managestock->setStyleSheet("background-color: rgb(38, 115, 154);\n"
                                   "border-radius: 13px;");
    ui->manageorder->setStyleSheet("background-color: rgb(255, 255, 255);\n"
                                   "border-radius: 13px;");
    ui->managestock->setFont(QFont("Consolas", 14));
    ui->manageorder->setFont(QFont("Consolas", 14));

    //set completed table
    ui->ctable->setColumnCount(4);
    ui->ctable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    headerList={"BUYER", "TOTAL", "ADDRESS", "STATE"};
    ui->ctable->setHorizontalHeaderLabels(headerList);
    ui->ctable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->ctable->verticalHeader()->setVisible(false);
    ui->ctable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    value = connect(ui->ctable, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(slotRowDoubleClicked_completed(const QModelIndex &)));
    if(!value){
        qDebug()<<"connect fail!";
    }
    //set to be completed table
    ui->tbctable->setColumnCount(5);
    ui->tbctable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    headerList={"BUYER", "TOTAL", "ADDRESS","", "STATE"};
    ui->tbctable->setHorizontalHeaderLabels(headerList);
    ui->tbctable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tbctable->verticalHeader()->setVisible(false);
    ui->tbctable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    value = connect(ui->tbctable, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(slotRowDoubleClicked_tobecompleted(const QModelIndex &)));
    if(!value){
        qDebug()<<"connect fail!";
    }
    ui->tabWidget->setCurrentIndex(0);
}

MyMarket::~MyMarket()
{
    delete ui;
}

void MyMarket::on_addProduct_clicked()
{
    newItem = new EditItem();
    newItem->setAddNew(1);
    newItem->setID(Commodity::total+1);
    newItem->passDB(db);
    newItem->passUser(user);
    Commodity *c = new Commodity();
    //myItems.push_back(c);
    newItem->passItem(c);
    newItem->passMS(this);
    newItem->show();
}

void MyMarket::initial()
{

    //store myitems
    myItems.clear();
    db->exec("use productsdb;");
    QString e = "select * from class where ownerID = '"+user->getID()+"'";
    db->exec(e);
    while(db->next()){
        Commodity *t = new Commodity;
        *t = db->getCurrentItem();
        //qDebug()<<t->getName();
        myItems.push_back(t);
    }


    //store orders
    myorders.clear();
    myorders_c.clear();
    myorders_tbc.clear();
    db->exec("use userdata;");
    db->exec("SELECT * FROM orders where sellerID = "+user->getID()+";");
    while(db->next()){
        vector<Order*>::iterator it;
        //判斷是否這個Order的buyer已經被存進myorders
        it = find_if(myorders.begin(), myorders.end(), [=](Order* a){
            return db->getValue(Order::s_orderID).toInt()==a->getOrderID();
        });
        //還沒存進來
        if(it==myorders.end()){
            Order* t = new Order;
            //qDebug()<<"new:"<<db->getValue(Order::s_itemID).toInt()<<" "<<db->getValue(Order::s_number).toInt();
            t->addOrderPD(db->getValue(Order::s_itemID).toInt(),
                          db->getValue(Order::s_number).toInt());
            t->setBuyerID(db->getValue(Order::s_buyerID).toString());
            t->setSellerID(db->getValue(Order::s_sellerID).toString());
            t->setBuyerName(db->getValue(Order::s_buyerName).toString());
            t->setSellerName(db->getValue(Order::s_sellerName).toString());
            //t->setItemName(db->getValue(Order::s_itemName).toString());
            //t->setPrice(db->getValue(Order::s_price).toInt());
            t->setShipping_fee(db->getValue(Order::s_SF).toInt());
            t->setTotal(db->getValue(Order::s_total).toInt());
            t->setPlaced(db->getValue(Order::s_placed).toBool());
            t->setState(db->getValue(Order::s_state).toInt());
            t->setAddress(db->getValue(Order::s_orderAddr).toString());
            Order::DateData datadata={
                db->getValue(Order::s_placedDate).toDateTime(),
                db->getValue(Order::s_shipDate).toDateTime(),
                db->getValue(Order::s_arrivedDate).toDateTime(),
                db->getValue(Order::s_receivedDate).toDateTime(),
                db->getValue(Order::s_completedDate).toDateTime(),
                db->getValue(Order::s_canceledDate).toDateTime()
            };
            t->setDateData(datadata);
            t->setOrderID(db->getValue(Order::s_orderID).toInt());
            myorders.push_back(t);
            if(t->getState()==Order::completed){
                myorders_c.push_back(t);
            }
            else
                myorders_tbc.push_back(t);
        }
        //有找到
        else {
            //qDebug()<<db->getValue(Order::s_itemID).toInt()<<
                    //db->getValue(Order::s_number).toInt();
            (*it)->addOrderPD(db->getValue(Order::s_itemID).toInt(),
                              db->getValue(Order::s_number).toInt());
            //qDebug()<<db->getValue(Order::s_total).toInt();
            (*it)->addTotal(db->getValue(Order::s_total).toInt());
            if(db->getValue(Order::s_SF).toInt()>(*it)->getShipping_fee()){
                (*it)->setShipping_fee(db->getValue(Order::s_SF).toInt());
            }
        }

    }
    cur = &myItems;
    update();
}

void MyMarket::update(){
    qDebug()<<"update";
    ui->tableWidget->setRowCount(0);
    ui->ctable->setRowCount(0);
    ui->tbctable->setRowCount(0);
    ui->tbctable->clearContents();
    enum{ID, name, stock};
    for(int i=0;i<(int)cur->size();i++){
        //qDebug()<<cur->at(i)->getName();
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        int curr = ui->tableWidget->rowCount()-1;
        ui->tableWidget->setItem(curr, ID, new QTableWidgetItem(QString::number(cur->at(i)->getItemID())));
        ui->tableWidget->setItem(curr, name, new QTableWidgetItem(cur->at(i)->getName()));
        ui->tableWidget->setItem(curr, stock, new QTableWidgetItem(QString::number(cur->at(i)->getStock())));
    }
    //to be completed table
     QComboBox *box;
    for(auto t:myorders_tbc){
        enum{ BUYER,TOTAL,ADDRESS,CHANGE,STATE};
        //qDebug()<<"buyerid:"<<t->getBuyerID();
        ui->tbctable->insertRow(ui->tbctable->rowCount());
        int curr = ui->tbctable->rowCount()-1;
        ui->tbctable->setItem(curr, BUYER, new QTableWidgetItem(t->getBuyerName()));
        ui->tbctable->setItem(curr, TOTAL, new QTableWidgetItem(QString::number(t->getTotal()+t->getShipping_fee())));
        ui->tbctable->setItem(curr, ADDRESS, new QTableWidgetItem(t->getAddress()));
        ui->tbctable->setItem(curr, STATE, new QTableWidgetItem(t->getStateName()));
        //ui->tbctable->setItem(curr, STATE, new QTableWidgetItem(t->getStateName()));
        box = new QComboBox;
        QStringList strList;
        strList<<"placed"<<"shipping";
        enum{placed,shipping};
        box->addItems(strList);

        if(t->getState()==Order::placed){
            box->setCurrentIndex(placed);
        }
        else if(t->getState()==Order::shipping){
            box->setCurrentIndex(shipping);
            box->setDisabled(1);
        }
        else{
            box->setDisabled(1);
            box->setCurrentIndex(-1);
        }
        connect(box, SIGNAL(currentIndexChanged(int)),SLOT(slotComboboxIndexChanged_tobecompleted(int)));
        ui->tbctable->setCellWidget(curr,CHANGE, box);
    }
    //completed table
    for(auto t:myorders_c){
        enum{ BUYER,TOTAL,ADDRESS,STATE};
        //qDebug()<<"buyerid:"<<t->getBuyerID();
        ui->ctable->insertRow(ui->ctable->rowCount());
        int curr = ui->ctable->rowCount()-1;
        ui->ctable->setItem(curr, BUYER, new QTableWidgetItem(t->getBuyerName()));
        ui->ctable->setItem(curr, TOTAL, new QTableWidgetItem(QString::number(t->getTotal()+t->getShipping_fee())));
        ui->ctable->setItem(curr, ADDRESS, new QTableWidgetItem(t->getAddress()));
        ui->ctable->setItem(curr, STATE, new QTableWidgetItem(t->getStateName()));
    }
}

void MyMarket::on_del_clicked()
{
    int row = ui->tableWidget->currentRow();
    int curID = ui->tableWidget->item(row, 0)->text().toInt();
    //vector<Commodity*>::iterator it=myItems.begin();
    //myItems.erase(it+row);
    db->del(curID);
    initial();
    //ui->tableWidget->removeRow(row);
}

void MyMarket::slotRowDoubleClicked(const QModelIndex &index)
{
    qDebug()<<"in";
    int row = index.row();
    //qDebug()<<"row:"<<row;
    edit_item = new EditItem();
    edit_item->passDB(db);
    edit_item->passUser(user);
    edit_item->passMS(this);
    edit_item->setAddNew(0);
    Commodity *c = cur->at(row);
    //qDebug()<<"name:"<<c->getName();
    edit_item->setInfo(c);
    edit_item->show();
}

void MyMarket::slotRowDoubleClicked_completed(const QModelIndex &index)
{
    int row = index.row();
    //qDebug()<<"row:"<<row;
    myorderdetail = new MyOrderDetail();
    myorderdetail->passOrder(myorders_c[row]);
    myorderdetail->passDB(db);
    myorderdetail->passQuery(query);
    myorderdetail->passUser(user);
    myorderdetail->update();
    myorderdetail->show();
}

void MyMarket::slotRowDoubleClicked_tobecompleted(const QModelIndex &index)
{
    int row = index.row();
    //qDebug()<<"row:"<<row;
    myorderdetail = new MyOrderDetail();
    myorderdetail->passOrder(myorders_tbc[row]);
    myorderdetail->passDB(db);
    myorderdetail->passQuery(query);
    myorderdetail->passUser(user);
    myorderdetail->update();
    myorderdetail->show();
}

void MyMarket::slotComboboxIndexChanged_tobecompleted(int index)
{
    //qDebug()<<"change state";
    int curr = ui->tbctable->currentRow();
    qobject_cast<QComboBox*>(ui->tbctable->cellWidget(curr, 3))->setCurrentIndex(index);
}
void MyMarket::passUser(User *u){
    user = u;
    if(user){
        qDebug()<<"pass user success!";
    }
    if(user==NULL){
        qDebug()<<"pass user error!";
    }
}


void MyMarket::on_back_clicked()
{
    prev = new UserInterface;

    db->exec("use userdata;");
    query->exec("use userdata;");
    prev->passDB(db);
    prev->passUser(user);
    prev->passQuery(query);
    prev->page_ordersSet();
    this->hide();
    prev->show();
}

void MyMarket::on_search1_clicked(){
    ui->tableWidget->setRowCount(0);
    if(ui->searchIDtext->text()!=QString()){
        search_id.clear();
        string text = ui->searchIDtext->text().toStdString();
        for(auto t:myItems){
            size_t found = QString::number(t->getItemID()).toStdString().find(text);
            if(found!=string::npos){
                search_id.push_back(t);
            }
            /*
            if(t->getItemID()==ui->searchIDtext->text().toInt()){

                search_id.push_back(t);
                cur=&search_id;
                update();
                return;
            }*/
        }
        cur = &search_id;
        update();
    }
}


void MyMarket::on_search2_clicked()
{
    ui->tableWidget->setRowCount(0);
    if(ui->searchNametext->text()!=QString()){
        search_name.clear();
        string text = ui->searchNametext->text().toStdString();
        for(size_t i=0;i<myItems.size();i++){
            size_t found = myItems[i]->getName().toStdString().find(text);
            if(found!=string::npos){
                //qDebug()<<"find:"<<myItems[i]->getName();
                search_name.push_back(myItems[i]);
            }
        }
        cur = &search_name;
        update();
    }
}


void MyMarket::on_searchType_activated(int index)
{
    ui->tableWidget->setRowCount(0);
    search_cat.clear();
    switch (index) {
    case 0:
        cur = &myItems;
        break;
    case 1:
        for(size_t i=0;i<myItems.size();i++){
            if(myItems[i]->getCate()==0){
                search_cat.push_back(myItems[i]);
            }
        }
        cur = &search_cat;
        break;
    case 2:
        for(size_t i=0;i<myItems.size();i++){
            if(myItems[i]->getCate()==1){
                search_cat.push_back(myItems[i]);
            }
        }
        cur = &search_cat;
        break;
    case 3:
        for(size_t i=0;i<myItems.size();i++){
            if(myItems[i]->getCate()==2){
                search_cat.push_back(myItems[i]);
            }
        }
        cur = &search_cat;
        break;
    case 4:
        for(size_t i=0;i<myItems.size();i++){
            if(myItems[i]->getCate()==3){
                search_cat.push_back(myItems[i]);
            }
        }
        cur = &search_cat;
        break;
    }
    update();
}


void MyMarket::on_managestock_clicked()
{
    ui->curpage->setText("Manage Stock");
    /*QPalette p1= ui->manageorder->palette();
    QPalette p2= ui->manageorder->palette();
    //p.setColor(QPalette::Window, QColor(Qt::white));
    ui->manageorder->setPalette(p1);
    ui->managestock->setPalette(p2);
    ui->manageorder->update();
    ui->managestock->update();*/
    ui->managestock->setStyleSheet("background-color: rgb(38, 115, 154);\n"
                                   "border-radius: 13px;");
    ui->manageorder->setStyleSheet("background-color: rgb(255, 255, 255);\n"
                                   "border-radius: 13px;");
}

void MyMarket::on_manageorder_clicked()
{
    ui->curpage->setText("Manage Order");
    /*
    QPalette p1= ui->manageorder->palette();
    QPalette p2= ui->manageorder->palette();
    //p.setColor(QPalette::Window, QColor(Qt::white));
    ui->manageorder->setPalette(p1);
    ui->managestock->setPalette(p2);
    ui->manageorder->update();
    ui->managestock->update();*/
    ui->manageorder->setStyleSheet("background-color: rgb(38, 115, 154);\n"
                                   "border-radius: 13px;");
    ui->managestock->setStyleSheet("background-color: rgb(255, 255, 255);\n"
                                   "border-radius: 13px;");


}


void MyMarket::on_save_clicked()
{
    //qDebug()<<"rowcount: "<<ui->tbctable->rowCount()<<" "<<ui->tbctable->columnCount();
    int tablerow = myorders_tbc.size();
    int idx=0;
    for(int curr=0; curr < tablerow;curr++){
        //qDebug()<<"change state";
        enum{placed,shipping};

        db->exec("use userdata;");
        QComboBox* box = (QComboBox*)(ui->tbctable->cellWidget(curr, 3));
        int index = ((QComboBox*)(ui->tbctable->cellWidget(curr, 3)))->currentIndex();
        Order *cur = myorders_tbc[idx];
        //set date
        switch (index) {
        case shipping:
            cur->setShipDate(QDateTime::currentDateTime());
            cur->setState(Order::shipping);
            ui->tbctable->item(curr,4)->setText(cur->getStateName());
            box->setDisabled(1);
            db->exec("UPDATE orders SET state = " + QString::number(Order::shipping) + " where orderID = "+ QString::number(cur->getOrderID()));
            qDebug()<<"UPDATE orders SET state = " + QString::number(Order::shipping) + " where orderID = "+ QString::number(cur->getOrderID());
            db->exec("UPDATE orders SET shipDate = NOW() where orderID = "+ QString::number(cur->getOrderID()));
            break;
        default:
            break;
        }
        idx++;
    }
    update();
}


void MyMarket::on_update_clicked()
{
    qDebug()<<"update clicked";
    initial();
}

