#include "homepage.h"
#include "ui_homepage.h"
#include <QMainWindow>
#include <QDialog>
#include <QPalette>
#include <QSqlResult>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QFrame>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include "user.h"
#include "signup.h"
#include "forgetpwd.h"
#include "userinterface.h"

class enter_PWD;
class signup;
class User;
class ForgetPWD;
class UserInterface;
HomePage::HomePage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);
    this->setWindowTitle("Home");
    QPixmap search("./img/search2.png");
    int w = ui->search->width();
    int h = ui->search->height();
    QIcon pushbottumicon(search.scaled(w,h,Qt::KeepAspectRatio,  Qt::SmoothTransformation));
    ui->search->setIcon(pushbottumicon);
    ui->search->setIconSize({w,h});
    QPixmap left_arrow("./img/left.png");
    w = ui->left_arrow->width();
    h = ui->left_arrow->height();
    QIcon lefticon(left_arrow);
    ui->left_arrow->setIcon(lefticon);
    ui->left_arrow->setIconSize({w,h});
    QPixmap right_arrow("./img/right.png");
    w = ui->right_arrow->width();
    h = ui->right_arrow->height();
    QIcon righticon(right_arrow);
    ui->right_arrow->setIcon(righticon);
    ui->right_arrow->setIconSize({w,h});
    QPixmap up("./img/up.png");
    w = ui->up->width();
    h = ui->up->height();
    QIcon upicon(up);
    ui->up->setIcon(up);
    ui->up->setIconSize({w,h});
    QPixmap down("./img/down.png");
    w = ui->down->width();
    h = ui->down->height();
    QIcon downicon(down);
    ui->down->setIcon(down);
    ui->down->setIconSize({w,h});
    name.push_back(ui->label_0_name);
    name.push_back(ui->label_1_name);
    name.push_back(ui->label_2_name);
    name.push_back(ui->label_3_name);
    name.push_back(ui->label_4_name);
    name.push_back(ui->label_5_name);
    name.push_back(ui->label_6_name);
    name.push_back(ui->label_7_name);
    price.push_back(ui->label_0_price);
    price.push_back(ui->label_1_price);
    price.push_back(ui->label_2_price);
    price.push_back(ui->label_3_price);
    price.push_back(ui->label_4_price);
    price.push_back(ui->label_5_price);
    price.push_back(ui->label_6_price);
    price.push_back(ui->label_7_price);
    img.push_back(ui->label_0_img);
    img.push_back(ui->label_1_img);
    img.push_back(ui->label_2_img);
    img.push_back(ui->label_3_img);
    img.push_back(ui->label_4_img);
    img.push_back(ui->label_5_img);
    img.push_back(ui->label_6_img);
    img.push_back(ui->label_7_img);
    num.push_back(ui->doubleSpinBox_0);
    num.push_back(ui->doubleSpinBox_1);
    num.push_back(ui->doubleSpinBox_2);
    num.push_back(ui->doubleSpinBox_3);
    num.push_back(ui->doubleSpinBox_4);
    num.push_back(ui->doubleSpinBox_5);
    num.push_back(ui->doubleSpinBox_6);
    num.push_back(ui->doubleSpinBox_7);
    plus.push_back(ui->plus_0);
    plus.push_back(ui->plus_1);
    plus.push_back(ui->plus_2);
    plus.push_back(ui->plus_3);
    plus.push_back(ui->plus_4);
    plus.push_back(ui->plus_5);
    plus.push_back(ui->plus_6);
    plus.push_back(ui->plus_7);
    frame.push_back(ui->frame_0);
    frame.push_back(ui->frame_1);
    frame.push_back(ui->frame_4);
    frame.push_back(ui->frame_5);
    frame.push_back(ui->frame_6);
    frame.push_back(ui->frame_7);
    frame.push_back(ui->frame_8);
    frame.push_back(ui->frame_9);

    curIndex=0;
    curPage=0;
    ui->search_comboBox->setCurrentIndex(0);
    curItems = &items;

    //set scroll area
    //ui->scrollArea->setWidget(widget);
    /*
    QScrollArea *sa = new QScrollArea(this);
    sa->setGeometry(0, 100, 1200, 720);
    sa->setStyleSheet( "width:8px;border-radius:2px;border-width:2px;border-color:black;min-height:1;");
    sa->setFrameShape(QFrame::NoFrame);
    sa->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    sa->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QWidget *w = new QWidget(sa);
    sa->setWidget(w);
    w->setGeometry(0, 0, 1200, 7000); //主要是设置长宽，xy意义不大
    QLabel *label_2=new QLabel(w);
    label_2->setText("222");
    label_2->move(400,300);
    */

}
void HomePage::initial(){
    items.clear();
    db->selectAllItems();
    //db->printerr();
    while(db->next()){
        Commodity *t = new Commodity;
        *t = db->getCurrentItem();
        //qDebug()<<t->getName();
        if(t->getStock()>0) items.push_back(t);
        else delete t;
    }
    maxpage = items.size()/8;
    setPage(1,&items);
}
void HomePage::setPage(int page, vector<Commodity*>*Items){
    qDebug()<<"page:"<<page;
    curPage=page;
    curIndex=(page-1)*8;
    maxpage = Items->size()/8+1;
    for(int i=0;i<8;i++){
        if(curIndex+i>=(int)Items->size()){
            plus[i]->setIcon(QIcon());
            img[i]->setPixmap(QPixmap());
            name[i]->setText(QString());
            price[i]->setText(QString());
            frame[i]->hide();

        }
        else{
            frame[i]->show();
            QPixmap pluspixmap("./img/plus.png");
            QPixmap itemImg(Items->at(curIndex+i)->getFilename());
            QIcon plusicon(pluspixmap);
            plus[i]->setIcon(plusicon);
            int w = ui->label_0_img->width();
            int h = ui->label_0_img->height();
            img[i]->setPixmap(itemImg.scaled(w,h,Qt::KeepAspectRatio,  Qt::SmoothTransformation));
            name[i]->setText(Items->at(curIndex+i)->getName());
            price[i]->setText(QString::number(Items->at(curIndex+i)->getPrice()));
            num[i]->setMaximum(Items->at(curIndex+i)->getStock());
            num[i]->setMinimum(1);
            //num[i]->setValue(0);
        }
    }

}

void HomePage::on_search_comboBox_activated(int index)
{
    search_cat.clear();
    switch (index) {
    case 0:
        curItems = &items;
        break;
    case 1:
        //food
        /*
        generate(items.begin(), items.end(), [&](Commodity* x){
            if(x->getCate()==0){
                search.push_back(x);
            }
        });*/
        for(size_t i=0;i<items.size();i++){
            if(items[i]->getCate()==0){
                search_cat.push_back(items[i]);
            }
        }
        curItems = &search_cat;
        break;
    case 2:
        //clothes
        for(size_t i=0;i<items.size();i++){
            if(items[i]->getCate()==1){
                search_cat.push_back(items[i]);
            }
        }
        curItems = &search_cat;
        break;
    case 3:
        //home living
        for(size_t i=0;i<items.size();i++){
            if(items[i]->getCate()==2){
                search_cat.push_back(items[i]);
            }
        }
        curItems = &search_cat;
        break;
    case 4:
        //electric device
        for(size_t i=0;i<items.size();i++){
            if(items[i]->getCate()==3){
                search_cat.push_back(items[i]);
            }
        }
        curItems = &search_cat;
        break;
    }
    setPage(1,curItems);
}

void HomePage::on_search_clicked()
{
    if(ui->search_lineEdit->text().isEmpty()){
        qDebug()<<"empty";
        return;
    }
    else {
        search_name.clear();
        string nametxt = ui->search_lineEdit->text().toStdString();
        for(size_t i=0;i<items.size();i++){
            size_t found = items[i]->getName().toStdString().find(nametxt);
            if(found!=string::npos){
                qDebug()<<"find:"<<items[i]->getName();
                search_name.push_back(items[i]);
            }
        }
        curItems = &search_name;
        setPage(1, curItems);
    }
}

HomePage::~HomePage()
{
    delete ui;
}

void HomePage::on_settings_clicked()
{
    settings = new UserInterface;
    query->exec("use userdata;");
    settings->passQuery(query);
    settings->passUser(user);
    settings->passDB(db);
    settings->page_ordersSet();

    this->hide();
    settings->show();
}

void HomePage::on_left_arrow_clicked()
{
    if(curPage-1<1)
        return ;
    curPage--;
    setPage(curPage, curItems);
}


void HomePage::on_right_arrow_clicked()
{
    if(curPage+1>maxpage)
        return ;
    curPage++;
    setPage(curPage, curItems);
}
void HomePage::PassSth(Commodity* pd){
    pdSub = new ProductSubPage;
    pdSub->passQuery(query);
    pdSub->passUser(user);
    pdSub->passCom(pd);
    pd->setBuyerID(user->getID());
    pdSub->pageSetting();
    pdSub->show();
}

void HomePage::on_pushButton_back_0_clicked()
{
    Commodity *item = curItems->at(curIndex);
    qDebug()<<item->getItemID();
    PassSth(item);
}

void HomePage::on_pushButton_back_1_clicked()
{
    Commodity *item = curItems->at(curIndex+1);
    qDebug()<<item->getItemID();
    PassSth(item);
}


void HomePage::on_pushButton_2_back_clicked()
{
    Commodity *item = curItems->at(curIndex+2);
    qDebug()<<item->getItemID();
    PassSth(item);
}


void HomePage::on_pushButton_3_back_clicked()
{
    Commodity *item = curItems->at(curIndex+3);
    qDebug()<<item->getItemID();
    PassSth(item);
}

void HomePage::on_pushButton_4_back_clicked()
{
    Commodity *item = curItems->at(curIndex+4);
    qDebug()<<item->getItemID();
    PassSth(item);
}

void HomePage::on_pushButton_5_back_clicked()
{
    Commodity *item = curItems->at(curIndex+5);
    qDebug()<<item->getItemID();
    PassSth(item);
}

void HomePage::on_pushButton_6_back_clicked()
{
    Commodity *item = curItems->at(curIndex+6);
    qDebug()<<item->getItemID();
    PassSth(item);
}

void HomePage::on_pushButton_7_back_clicked()
{
    Commodity *item = curItems->at(curIndex+7);
    qDebug()<<item->getItemID();
    PassSth(item);
}

void HomePage::on_up_clicked()
{
    sort(curItems->begin(), curItems->end(), [](Commodity *a,Commodity *b){
        return a->getPrice()<b->getPrice();
    });
    setPage(1, curItems);
}


void HomePage::on_down_clicked()
{
    sort(curItems->begin(), curItems->end(), [](Commodity *a,Commodity *b){
        return a->getPrice()>b->getPrice();
    });
    setPage(1,curItems);
}

void HomePage::on_plus_0_clicked()
{
    qDebug()<<"in on plus 0";
    query->exec("use userdata;");
    Commodity *item = curItems->at(curIndex);
    item->setBuyerID(user->getID());

    if(ui->doubleSpinBox_0->value() >0){
        //int num = 0, total = 0;
        user->addItemToCart(item, ui->doubleSpinBox_0->value());
        /*
        QString take = "select * from orders where placed = 0 and buyerID = '" + item->getBuyerID() + "' and sellerID = '" + item->getOwnerID() + "' and itemID = " + QString::number(item->getItemID());
        query->exec(take);
        if(query->next()){
            qDebug()<<"spin = "<<ui->doubleSpinBox_0->value();
            num = query->value(Order::sqlOrders::s_number).toInt();
            total = query->value(Order::sqlOrders::s_total).toInt() + item->getPrice()*ui->doubleSpinBox_0->value();
            qDebug()<<"total = "<<total;
            take = "update orders set number = " + QString::number(num+ui->doubleSpinBox_0->value()) + ", total = " + QString::number(total) + " where placed = 0 and buyerID = '" + item->getBuyerID() + "' and sellerID = '" + item->getOwnerID() + "' and itemID = " + QString::number(item->getItemID());
            qDebug()<<"in on plus_0_clicked: take = "<<take;
            query->exec(take);
        }
        else{
            QString num = QString::number(ui->doubleSpinBox_0->value());
            QString total = QString::number(item->getPrice()*ui->doubleSpinBox_0->value());
            take = "insert into orders (buyerID, buyerName, sellerID, itemID, number, total, placed) values('" + item->getBuyerID() + "', '" + user->getName() + "', '" + item->getOwnerID() + "', "+ QString::number(item->getItemID()) + ", " + num + "," + total + ", 0)";
            query->exec(take);
            qDebug()<<"insert into orders: "<<take;
        }
        */
        /*
        item->setStock(item->getStock()-ui->doubleSpinBox_0->value());
        take = "update class SET stock = " + QString::number(item->getStock()-ui->doubleSpinBox_0->value()) + " where itemID = " + QString::number(item->getItemID());
        db->exec("use productsdb");
        db->exec(take);
        */
    }

}


void HomePage::on_plus_1_clicked()
{
    query->exec("use userdata;");
    Commodity *item = curItems->at(curIndex+1);
    item->setBuyerID(user->getID());
    if(ui->doubleSpinBox_1->value() >0){
        //int num = 0, total = 0;
        user->addItemToCart(item, ui->doubleSpinBox_1->value());
        /*
        QString take = "select * from orders where placed = 0 and buyerID = '" + item->getBuyerID() + "' and sellerID = '" + item->getOwnerID() + "' and itemID = " + QString::number(item->getItemID());
        query->exec(take);
        if(query->next()){
            num = query->value(Order::sqlOrders::s_number).toInt();
            total = query->value(Order::sqlOrders::s_total).toInt() + item->getPrice()*ui->doubleSpinBox_1->value();
            take = "update orders set number = " + QString::number(num+ui->doubleSpinBox_1->value()) + ", total = " + QString::number(total) + " where placed = 0 and buyerID = '" + item->getBuyerID() + "' and sellerID = '" + item->getOwnerID() + "' and itemID = " + QString::number(item->getItemID());
            query->exec(take);
        }
        else{
            QString num = QString::number(ui->doubleSpinBox_1->value());
            QString total = QString::number(item->getPrice()*ui->doubleSpinBox_1->value());
            take = "insert into orders (buyerID, sellerID, itemID, number, total, placed) values('" + item->getBuyerID() + "', '" + item->getOwnerID() + "', " + QString::number(item->getItemID()) + ", " + num + "," + total + ", 0)";
            query->exec(take);
            qDebug()<<"insert into orders: "<<take;
        }
        */
    }
}


void HomePage::on_plus_3_clicked()
{
    query->exec("use userdata;");
    Commodity *item = curItems->at(curIndex+3);
    item->setBuyerID(user->getID());
    if(ui->doubleSpinBox_3->value() >0){
        //int num = 0, total = 0;
        user->addItemToCart(item, ui->doubleSpinBox_3->value());
        /*
        QString take = "select * from orders where placed = 0 and buyerID = '" + item->getBuyerID() + "' and sellerID = '" + item->getOwnerID() + "' and itemID = " + QString::number(item->getItemID());
        query->exec(take);
        if(query->next()){
            num = query->value(Order::sqlOrders::s_number).toInt();
            total = query->value(Order::sqlOrders::s_total).toInt() + item->getPrice()*ui->doubleSpinBox_3->value();
            take = "update orders set number = " + QString::number(num+ui->doubleSpinBox_3->value()) + ", total = " + QString::number(total) + " where placed = 0 and buyerID = '" + item->getBuyerID() + "' and sellerID = '" + item->getOwnerID() + "' and itemID = " + QString::number(item->getItemID());
            query->exec(take);
        }
        else{
            QString num = QString::number(ui->doubleSpinBox_3->value());
            QString total = QString::number(item->getPrice()*ui->doubleSpinBox_1->value());
            take = "insert into orders (buyerID, sellerID, itemID, number, total, placed) values('" + item->getBuyerID() + "', '" + item->getOwnerID() + "', " + QString::number(item->getItemID()) + ", " + num + "," + total + ", 0)";
            query->exec(take);
            qDebug()<<"insert into orders: "<<take;
        }
        */
    }
}


void HomePage::on_plus_2_clicked()
{
    query->exec("use userdata;");
    Commodity *item = curItems->at(curIndex+2);
    item->setBuyerID(user->getID());
    if(ui->doubleSpinBox_2->value() >0){
        //int num = 0, total = 0;
        user->addItemToCart(item, ui->doubleSpinBox_2->value());
        /*
        QString take = "select * from orders where placed = 0 and buyerID = '" + item->getBuyerID() + "' and sellerID = '" + item->getOwnerID() + "' and itemID = " + QString::number(item->getItemID());
        query->exec(take);
        if(query->next()){
            num = query->value(Order::sqlOrders::s_number).toInt();
            total = query->value(Order::sqlOrders::s_total).toInt() + item->getPrice()*ui->doubleSpinBox_3->value();
            take = "update orders set number = " + QString::number(num+ui->doubleSpinBox_2->value()) + ", total = " + QString::number(total) + " where placed = 0 and buyerID = '" + item->getBuyerID() + "' and sellerID = '" + item->getOwnerID() + "' and itemID = " + QString::number(item->getItemID());
            query->exec(take);
        }
        else{
            QString num = QString::number(ui->doubleSpinBox_2->value());
            QString total = QString::number(item->getPrice()*ui->doubleSpinBox_2->value());
            take = "insert into orders (buyerID, sellerID, itemID, number, total, placed) values('" + item->getBuyerID() + "', '" + item->getOwnerID() + "', " + QString::number(item->getItemID()) + ", " + num + "," + total + ", 0)";
            query->exec(take);
            qDebug()<<"insert into orders: "<<take;
        }
        */
    }
}


void HomePage::on_plus_4_clicked()
{
    query->exec("use userdata;");
    Commodity *item = curItems->at(curIndex+4);
    item->setBuyerID(user->getID());
    if(ui->doubleSpinBox_4->value() >0){
        //int num = 0, total = 0;
        user->addItemToCart(item, ui->doubleSpinBox_4->value());
        /*
        QString take = "select * from orders where placed = 0 and buyerID = '" + item->getBuyerID() + "' and sellerID = '" + item->getOwnerID() + "' and itemID = " + QString::number(item->getItemID());
        query->exec(take);
        if(query->next()){
            num = query->value(Order::sqlOrders::s_number).toInt();
            total = query->value(Order::sqlOrders::s_total).toInt() + item->getPrice()*ui->doubleSpinBox_4->value();
            take = "update orders set number = " + QString::number(num+ui->doubleSpinBox_4->value()) + ", total = " + QString::number(total) + " where placed = 0 and buyerID = '" + item->getBuyerID() + "' and sellerID = '" + item->getOwnerID() + "' and itemID = " + QString::number(item->getItemID());
            query->exec(take);
        }
        else{
            QString num = QString::number(ui->doubleSpinBox_4->value());
            QString total = QString::number(item->getPrice()*ui->doubleSpinBox_4->value());
            take = "insert into orders (buyerID, sellerID, itemID, number, total, placed) values('" + item->getBuyerID() + "', '" + item->getOwnerID() + "', " + QString::number(item->getItemID()) + ", " + num + "," + total + ", 0)";
            query->exec(take);
            qDebug()<<"insert into orders: "<<take;
        }
        */
    }
}


void HomePage::on_plus_5_clicked()
{
    query->exec("use userdata;");
    Commodity *item = curItems->at(curIndex+5);
    item->setBuyerID(user->getID());
    if(ui->doubleSpinBox_5->value() >0){
        //int num = 0, total = 0;
        user->addItemToCart(item, ui->doubleSpinBox_5->value());
        /*
        QString take = "select * from orders where placed = 0 and buyerID = '" + item->getBuyerID() + "' and sellerID = '" + item->getOwnerID() + "' and itemID = " + QString::number(item->getItemID());
        query->exec(take);
        if(query->next()){
            num = query->value(Order::sqlOrders::s_number).toInt();
            total = query->value(Order::sqlOrders::s_total).toInt() + item->getPrice()*ui->doubleSpinBox_5->value();
            take = "update orders set number = " + QString::number(num+ui->doubleSpinBox_5->value()) + ", total = " + QString::number(total) + " where placed = 0 and buyerID = '" + item->getBuyerID() + "' and sellerID = '" + item->getOwnerID() + "' and itemID = " + QString::number(item->getItemID());
            query->exec(take);
        }
        else{
            QString num = QString::number(ui->doubleSpinBox_5->value());
            QString total = QString::number(item->getPrice()*ui->doubleSpinBox_2->value());
            take = "insert into orders (buyerID, sellerID, itemID, number, total, placed) values('" + item->getBuyerID() + "', '" + item->getOwnerID() + "', " + QString::number(item->getItemID()) + ", " + num + "," + total + ", 0)";
            query->exec(take);
            qDebug()<<"insert into orders: "<<take;
        }
        */
    }
}


void HomePage::on_plus_6_clicked()
{
    query->exec("use userdata;");
    Commodity *item = curItems->at(curIndex+6);
    item->setBuyerID(user->getID());
    if(ui->doubleSpinBox_6->value() >0){
        //int num = 0, total = 0;
        user->addItemToCart(item, ui->doubleSpinBox_6->value());
        /*
        QString take = "select * from orders where placed = 0 and buyerID = '" + item->getBuyerID() + "' and sellerID = '" + item->getOwnerID() + "' and itemID = " + QString::number(item->getItemID());
        query->exec(take);
        if(query->next()){
            num = query->value(Order::sqlOrders::s_number).toInt();
            total = query->value(Order::sqlOrders::s_total).toInt() + item->getPrice()*ui->doubleSpinBox_6->value();
            take = "update orders set number = " + QString::number(num+ui->doubleSpinBox_6->value()) + ", total = " + QString::number(total) + " where placed = 0 and buyerID = '" + item->getBuyerID() + "' and sellerID = '" + item->getOwnerID() + "' and itemID = " + QString::number(item->getItemID());
        }
        else{
            QString num = QString::number(ui->doubleSpinBox_6->value());
            QString total = QString::number(item->getPrice()*ui->doubleSpinBox_6->value());
            take = "insert into orders (buyerID, sellerID, itemID, number, total, placed) values('" + item->getBuyerID() + "', '" + item->getOwnerID() + "', " + QString::number(item->getItemID()) + ", " + num + "," + total + ", 0)";
            query->exec(take);
            qDebug()<<"insert into orders: "<<take;
        }
        */
    }
}


void HomePage::on_plus_7_clicked()
{
    query->exec("use userdata;");
    Commodity *item = curItems->at(curIndex+7);
    item->setBuyerID(user->getID());
    if(ui->doubleSpinBox_7->value() >0){
        //int num = 0, total = 0;
        user->addItemToCart(item, ui->doubleSpinBox_7->value());
        /*
        QString take = "select * from orders where placed = 0 and buyerID = '" + item->getBuyerID() + "' and sellerID = '" + item->getOwnerID() + "' and itemID = " + QString::number(item->getItemID());
        query->exec(take);
        if(query->next()){
            num = query->value(Order::sqlOrders::s_number).toInt();
            total = query->value(Order::sqlOrders::s_total).toInt() + item->getPrice()*ui->doubleSpinBox_7->value();
            take = "update orders set number = " + QString::number(num+ui->doubleSpinBox_7->value()) + ", total = " + QString::number(total) + " where placed = 0 and buyerID = '" + item->getBuyerID() + "' and sellerID = '" + item->getOwnerID() + "' and itemID = " + QString::number(item->getItemID());
            query->exec(take);
        }
        else{
            QString num = QString::number(ui->doubleSpinBox_7->value());
            QString total = QString::number(item->getPrice()*ui->doubleSpinBox_7->value());
            take = "insert into orders (buyerID, sellerID, itemID, number, total, placed) values('" + item->getBuyerID() + "', '" + item->getOwnerID() + "', " + QString::number(item->getItemID()) + ", " + num + "," + total + ", 0)";
            query->exec(take);
            qDebug()<<"insert into orders: "<<take;
        }
        */
    }
}


void HomePage::on_cart_clicked()
{
    cartWD = new CartWD;
    cartWD->passHome(this);
    cartWD->passDB(db);
    cartWD->passQuery(query);
    cartWD->passUser(user);
    cartWD->pageSettings();
    cartWD->show();
}


void HomePage::on_doubleSpinBox_0_valueChanged(double arg1)
{
    ui->label_0_price->setText(QString::number((int)arg1*curItems->at(curIndex)->getPrice()));
}


void HomePage::on_doubleSpinBox_1_valueChanged(double arg1)
{
    ui->label_1_price->setText(QString::number((int)arg1*curItems->at(curIndex+1)->getPrice()));
}


void HomePage::on_doubleSpinBox_2_valueChanged(double arg1)
{
    ui->label_2_price->setText(QString::number((int)arg1*curItems->at(curIndex+2)->getPrice()));
}


void HomePage::on_doubleSpinBox_3_valueChanged(double arg1)
{
    ui->label_3_price->setText(QString::number((int)arg1*curItems->at(curIndex+3)->getPrice()));
}


void HomePage::on_doubleSpinBox_4_valueChanged(double arg1)
{
    ui->label_4_price->setText(QString::number((int)arg1*curItems->at(curIndex+4)->getPrice()));
}


void HomePage::on_doubleSpinBox_5_valueChanged(double arg1)
{
    ui->label_5_price->setText(QString::number((int)arg1*curItems->at(curIndex+5)->getPrice()));
}


void HomePage::on_doubleSpinBox_6_valueChanged(double arg1)
{
    ui->label_6_price->setText(QString::number((int)arg1*curItems->at(curIndex+6)->getPrice()));
}


void HomePage::on_doubleSpinBox_7_valueChanged(double arg1)
{
    ui->label_7_price->setText(QString::number((int)arg1*curItems->at(curIndex+7)->getPrice()));
}

