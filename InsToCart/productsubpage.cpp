#include "productsubpage.h"
#include "ui_productsubpage.h"

ProductSubPage::ProductSubPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProductSubPage)
{
    ui->setupUi(this);
    ui->table->setColumnCount(4);
    QStringList q;
    q.push_back("Time");
    q.push_back("Buyer");
    q.push_back("Points");
    q.push_back("Comment");

    ui->table->horizontalHeader()->setDisabled(1);
    ui->table->setHorizontalHeaderLabels(q);
    ui->table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->table->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);
    ui->table->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->table->verticalHeader()->setVisible(false);
    ui->table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->table->setSelectionMode(QAbstractItemView::NoSelection);
}

ProductSubPage::~ProductSubPage()
{
    delete ui;
}
void ProductSubPage::pageSetting(void){
    //qDebug()<<"in settings\nowner ID = "<<pd->getOwnerID();
    ui->label_pdName->setText(pd->getName());
    //qDebug()<<pd->getName();
    ui->label_category_2->setText(pd->getTypeName(pd->getCate()));
    //qDebug()<<pd->getTypeName(pd->getCate());
    ui->label_seller_2->setText(getPDowner());
    ui->label_price->setText(QString::number(ui->doubleSpinBox->value()*pd->getPrice()));
    //qDebug()<<getPDowner();
    ui->label_SF_2->setText(QString::number(pd->getSF()));
    ui->label_stock_2->setText(QString::number(pd->getStock()));
    ui->textBrowser->setText(pd->getDescript());
    QPixmap p(pd->getFilename());
    int w = ui->label->width();
    int h = ui->label->height();
    ui->label->setPixmap(p.scaled(w,h,Qt::KeepAspectRatio,  Qt::SmoothTransformation));
    ui->doubleSpinBox->setMaximum(pd->getStock());
    query->exec("select avg(avg) from rate where itemID= "+QString::number(pd->getItemID()));
    qDebug()<<"select avg(avg) from rate where itemID= "+QString::number(pd->getItemID());
    if(query->next()) ui->label_rating_2->setText(query->value(0).toString());

    //table
    ui->table->clearContents();
    ui->table->setRowCount(0);
    int row = 0;
    query->exec("use userdata;");
    query->exec("select completedDate, buyerName, point, comment from rate where itemID = " +QString::number(pd->getItemID()));
    qDebug()<<"select completedDate, buyerName, point, comment from rate where itemID = " +QString::number(pd->getItemID());
    QTableWidgetItem *a;
    while (query->next()) {
        ui->table->insertRow(row);
        a = new QTableWidgetItem(query->value(0).toDateTime().toString("yyyy.MM.dd hh:mm"),Qt::AlignHCenter);
        a->setTextAlignment(Qt::AlignCenter);
        ui->table->setItem(row,0, a);
        a = new QTableWidgetItem(query->value(1).toString(),Qt::AlignHCenter);
        a->setTextAlignment(Qt::AlignCenter);
        ui->table->setItem(row,1,a);
        a = new QTableWidgetItem(query->value(2).toString());
        a->setTextAlignment(Qt::AlignCenter);
        ui->table->setItem(row,2,a);
        a = new QTableWidgetItem(query->value(3).toString(),Qt::AlignHCenter);
        a->setTextAlignment(Qt::AlignCenter);
        ui->table->setItem(row,3,a);
        row++;
    }
}
QString ProductSubPage::getPDowner(){
    QString take  = "use userdata;";
    query->exec(take);
    take = "select * from users where ID = " + pd->getOwnerID();
    qDebug()<<take;
    query->exec(take);
    if(query->next()){
        qDebug()<<query->value(User::sqlTable::sName).toString();
        return query->value(User::sqlTable::sName).toString();
    }
    else{
        qDebug()<<"no seller";
    }
    return "";
}

void ProductSubPage::on_pushButton_addToCart_clicked()
{
    query->exec("use userdata;");
    if(ui->doubleSpinBox->value()>0){
        //int num = 0, total = 0;
        user->addItemToCart(pd, ui->doubleSpinBox->value());
        /*
        QString take = "select * from orders where placed = 0 and buyerID = '" + pd->getBuyerID() + "' and sellerID = '" + pd->getOwnerID() + "' and itemID = " + QString::number(pd->getItemID());
        query->exec(take);
        if(query->next()){
            num = query->value(Order::sqlOrders::s_number).toInt();
            total = query->value(Order::sqlOrders::s_total).toInt() + pd->getPrice()*ui->doubleSpinBox->value();
            take = "update orders set number = " + QString::number(num+ui->doubleSpinBox->value()) + ", total = " + QString::number(total) + " where placed = 0 and buyerID = '" + pd->getBuyerID() + "' and sellerID = '" + pd->getOwnerID() + "' and itemID = " + QString::number(pd->getItemID());
            qDebug()<<take;
            query->exec(take);
        }
        else{
            QString num = QString::number(ui->doubleSpinBox->value());
            QString total = QString::number(pd->getPrice()*ui->doubleSpinBox->value());
            qDebug()<<"total = "<<total;
            take = "insert into orders (buyerID, sellerID, itemID, number, total, placed) values('" + pd->getBuyerID() + "', '" + pd->getOwnerID() + "', " + QString::number(pd->getItemID()) + ", " + num + "," + total + ", 0)";
            query->exec(take);
            qDebug()<<"insert into orders: "<<take;
        }
        */
    }
}


void ProductSubPage::on_doubleSpinBox_valueChanged(double arg1)
{
    ui->label_price->setText(QString::number((int)arg1*(pd->getPrice())));
}

