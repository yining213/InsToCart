#include <QFont>
#include "managestock.h"
#include "ui_managestock.h"
#include "edititem.h"
#include"commodity.h"
#include<vector>

ManageStock::ManageStock(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageStock)
{
    ui->setupUi(this);
    QPalette palette = ui->label->palette();

    QPixmap *add = new QPixmap("./add.png");

    int w = ui->label_4->width();
    int h = ui->label_4->height();

    // set a scaled pixmap to a w x h window keeping its aspect ratio
    ui->label_4->setPixmap(add->scaled(w,h,Qt::KeepAspectRatio,  Qt::SmoothTransformation));
    ui->addProduct->setPalette(palette);

    //                "font: 17pt "Consolas";"

    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QStringList headerList={"ID", "NAME", "STOCK"};
    ui->tableWidget->setHorizontalHeaderLabels(headerList);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->verticalHeader()->setVisible(false);
    bool value = connect(ui->tableWidget, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(slotRowDoubleClicked(const QModelIndex &)));
    if(!value){
        qDebug()<<"connect fail!";
    }
    ui->searchType->setCurrentIndex(0);
    cur = &myItems;
}

ManageStock::~ManageStock()
{
    delete ui;
}

void ManageStock::on_addProduct_clicked()
{
    newItem = new EditItem(this);
    newItem->setAddNew(1);
    newItem->setID(Commodity::total+1);
    newItem->passDB(db);
    newItem->passUser(user);
    Commodity *c = new Commodity();
    myItems.push_back(c);
    newItem->passItem(c);
    newItem->passMS(this);
    newItem->show();
}

void ManageStock::initial()
{
    QString e = "select * from class where ownerID = '"+user->getID()+"'";
    qDebug()<<e;
    db->exec(e);
    db->printerr();
    while(db->next()){
        Commodity *t = new Commodity;
        *t = db->getCurrentItem();
        qDebug()<<t->getName();
        myItems.push_back(t);
    }
    update();
}

void ManageStock::update(){
    ui->tableWidget->setRowCount(0);
    enum{ID, name, stock};
    for(int i=0;i<cur->size();i++){
        qDebug()<<cur->at(i)->getName();
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        int curr = ui->tableWidget->rowCount()-1;
        ui->tableWidget->setItem(curr, ID, new QTableWidgetItem(QString::number(cur->at(i)->getItemID())));
        ui->tableWidget->setItem(curr, name, new QTableWidgetItem(cur->at(i)->getName()));
        ui->tableWidget->setItem(curr, stock, new QTableWidgetItem(QString::number(cur->at(i)->getStock())));
    }
    //ui->listWidget->clear();
    /*
    QString e = "select * from class where ownerID = '"+user->getID()+"'";
    qDebug()<<e;
    db->exec(e);
    db->printerr();
    while(db->next()){
        QString name = db->getValue(1).toString();
        QString itemID = db->getValue(0).toString();
        ui->listWidget->addItem(QString("     ").replace(0,itemID.length(), itemID)+name);
    }*/
}
void ManageStock::on_update_clicked()
{
   update();
}


void ManageStock::on_listWidget_currentRowChanged(int currentRow)
{
    mnSelected = currentRow;
}


void ManageStock::on_del_clicked()
{
    int row = ui->tableWidget->currentRow();
    int curID = ui->tableWidget->item(row, 0)->text().toInt();
    vector<Commodity*>::iterator it=myItems.begin();
    myItems.erase(it+row);
    db->del(curID);
    ui->tableWidget->removeRow(row);
    /*
    int row = ui->listWidget->currentRow();
    QListWidgetItem *it = ui->listWidget->currentItem();
    if(it == NULL)
        return ;
    int curID = it->text().left(5).toInt();
    db->del(curID);
    ui->listWidget->takeItem(row);
    delete it;
    */

}

void ManageStock::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
     edit_item = new EditItem(this);
     edit_item->passDB(db);
     edit_item->passUser(user);
     edit_item->passMS(this);
     edit_item->setAddNew(0);
     int curID = item->text().left(5).toInt();
     //qDebug()<<"id: "<<curID;
     Commodity c = db->search(curID);
     edit_item->setInfo(&c);
     edit_item->show();
}

void ManageStock::slotRowDoubleClicked(const QModelIndex &index)
{
    qDebug()<<"in";
    int row = ui->tableWidget->currentIndex().row();
    qDebug()<<"row:"<<row;
    edit_item = new EditItem(this);
    edit_item->passDB(db);
    edit_item->passUser(user);
    edit_item->passMS(this);
    edit_item->setAddNew(0);
    Commodity *c = cur->at(row);
    qDebug()<<"name:"<<c->getName();
    edit_item->setInfo(c);
    edit_item->show();
}
void ManageStock::passUser(User *u){
    user = u;
    if(user){
        qDebug()<<"pass user success!";
    }
    if(user==NULL){
        qDebug()<<"pass user error!";
    }
}


void ManageStock::on_back_clicked()
{
    prev = new UserInterface(this);

    db->exec("use userdata;");
    prev->passDB(db);
    prev->passUser(user);
    prev->passQuery(query);
    this->hide();
    prev->show();
}

void ManageStock::on_search1_clicked(){
    ui->tableWidget->setRowCount(0);
    if(ui->searchIDtext->text()!=QString()){
        search_id.clear();
        for(auto t:myItems){
            if(t->getItemID()==ui->searchIDtext->text().toInt()){

                search_id.push_back(t);
                cur=&search_id;
                update();
                /*
                ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                int curr = ui->tableWidget->rowCount()-1;
                ui->tableWidget->setItem(curr, 0, new QTableWidgetItem(QString::number(t->getItemID())));
                ui->tableWidget->setItem(curr, 1, new QTableWidgetItem(t->getName()));
                ui->tableWidget->setItem(curr, 2, new QTableWidgetItem(QString::number(t->getStock())));
                */
                return;
            }
        }
    }
}


void ManageStock::on_search2_clicked()
{
    ui->tableWidget->setRowCount(0);
    if(ui->searchNametext->text()!=QString()){
        search_name.clear();
        string text = ui->searchNametext->text().toStdString();
        for(size_t i=0;i<myItems.size();i++){
            size_t found = myItems[i]->getName().toStdString().find(text);
            if(found!=string::npos){
                qDebug()<<"find:"<<myItems[i]->getName();
                search_name.push_back(myItems[i]);
            }
        }
        cur = &search_name;
        update();
    }
}


void ManageStock::on_searchType_activated(int index)
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

