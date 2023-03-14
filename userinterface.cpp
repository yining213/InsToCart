#include "userinterface.h"
#include "ui_userinterface.h"
#include<QPushButton>

UserInterface::UserInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserInterface)
{

    ui->setupUi(this);
    this->setWindowTitle("User Interface");

    newInfo = 0;
    edit_account = edit_username = edit_PWD = edit_phone = 0;
    save = 1;
    ui->stackedWidget->setCurrentIndex(1); //set order page to default
    ui->tabWidget->setStyleSheet("QTabBar::tab:selected { background-color: rgb(38, 115, 154); }");
    tableInitial(ui->tableWidget_1,0);
    tableInitial(ui->tableWidget_2,1);
    tableInitial(ui->tableWidget_3,2);
    tableInitial(ui->tableWidget_4,3);
    tableInitial(ui->tableWidget_5,4);
    tableInitial(ui->tableWidget_6,5);
}

UserInterface::~UserInterface()
{
    delete ui;
}
void UserInterface::page_accountSet(){
    ui->label_pwdAlert->clear();
    ui->label_accountAlert->clear();
    ui->label_phoneAlert->clear();
    ui->label_usernameAlert->clear();

    ui->username->setText(user->getName());
    //qDebug()<<"user.getname = "<<user->getName();
    ui->lineEdit_username->setEnabled(0);
    ui->lineEdit_username->setText(user->getName());
    ui->lineEdit_account->setEnabled(0);
    ui->comboBox->setEnabled(0);
    QString acc,suffix;
    bool change=0;
    for(int i=0;i<user->getAccount().length();i++){
        if(user->getAccount()[i]=='@'){
            change = 1;
            continue;
        }
        if(!change) acc+=user->getAccount()[i];
        else suffix+=user->getAccount()[i];
    }
    ui->lineEdit_account->setText(acc);
    if(suffix[0]=='n') ui->comboBox->setCurrentIndex(0);
    else ui->comboBox->setCurrentIndex(1);
    ui->lineEdit_phone->setEnabled(0);
    ui->lineEdit_phone->setText(user->getPhone());
    ui->lineEdit_editPWD->setEnabled(0);
    ui->lineEdit_editPWD->setText(user->getPWD());
    ui->comboBox_gender->setCurrentIndex(user->getGender());
    ui->label_birthday->setText(user->getBirthday().toString("yyyy.MM.dd"));
}
void UserInterface::tableInitial(QTableWidget *table, int index){

    QStringList q;
    q.push_back("ORDER ID");
    q.push_back("SELLER");
    q.push_back("TOTAL");
    q.push_back("Time");
    if(index<3){
        if(index<2) q.push_back("CANCEL");
        else q.push_back("");
        table->setColumnCount(5);
    }
    else if(index==3){
        q.push_back("Order\nRating");
        q.push_back("Points");
        q.push_back("Comment");
        table->setColumnCount(7);
    }
    else table->setColumnCount(4);

    table->setStyleSheet("QHeaderView::section { color:black; background-color:#BF9133 }"
                         "font: 12pt \"Consolas\""
                         "color: rgb(0, 0, 0)"
                         "border-radius: 0pt"
                         "selection-background-color: rgb(191, 145, 51)"
                         "selection-color: rgb(0, 0, 0)"
                         "background-color: rgb(255, 255, 255)"
                         );
    table->horizontalHeader()->setDisabled(1);
    table->setHorizontalHeaderLabels(q);

    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    if(index==3){
        //table->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
        //table->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
        //table->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    }
    table->horizontalHeader()->setStretchLastSection(true);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->verticalHeader()->setVisible(false);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionMode(QAbstractItemView::NoSelection);
    table->horizontalHeader()->setFixedHeight(60);

    //connect(table, SIGNAL(doubleClicked(const QModelIndex &)),this, SLOT(tableDoubleClicked(const QModelIndex &)));

}
void UserInterface::page_ordersSet(){
   //qDebug()<<"page_orderSet";
   page_accountSet();
   ui->tabWidget->setCurrentIndex(0);
   displayTable(0);
}
void UserInterface::displayTable(int index){
    query->exec("use userdata");
    user->loadOrders(index);
    orderMap cur = user->getorderMap(index);
    //qDebug()<<cur.size();
    QTableWidget* table;
    switch(index){
    case 0:
        //user->setTable(index, ui->tableWidget_1); break;
        table = ui->tableWidget_1; break;
    case 1:
        //user->setTable(index, ui->tableWidget_2); break;
        table = ui->tableWidget_2; break;
    case 2:
        //user->setTable(index, ui->tableWidget_3); break;
        table = ui->tableWidget_3; break;
    case 3:
       // user->setTable(index, ui->tableWidget_4); break;
        table = ui->tableWidget_4; break;
    case 4:
        //user->setTable(index, ui->tableWidget_5); break;
        table = ui->tableWidget_5; break;
    case 5:
        //user->setTable(index, ui->tableWidget_6); break;
        table = ui->tableWidget_6; break;
    }
    table->clearContents();
    enum{EorderID, Eseller, Etotal, Edate, Ecancel, Epoint, Ecomment};
    int i = 0;

    QString take;
    int subtotal,sf,total;
    table->setRowCount(0);
    QTableWidgetItem *a;
    for(orderMap::iterator itm = cur.begin(); itm!=cur.end(); itm++){
        table->insertRow(i);
        a = new QTableWidgetItem((*itm.value().begin())->getSellerName(), Qt::AlignCenter);
        a->setTextAlignment(Qt::AlignCenter);
        table->setItem(i, Eseller, a);
        a = new QTableWidgetItem(QString::number(itm.key()), Qt::AlignCenter);
        a->setTextAlignment(Qt::AlignCenter);
        table->setItem(i, EorderID, a);
        take = "SELECT sum(total) FROM orders WHERE orderID = " + QString::number(itm.key());
        query->exec(take);
        if(query->next()) subtotal = query->value(0).toInt(); //qDebug()<<"subtotal = "<<subtotal;
        take = "SELECT max(shipping_fee) FROM orders WHERE orderID = " + QString::number(itm.key());
        query->exec(take);
        if(query->next()) sf = query->value(0).toInt(); //qDebug()<<"sf = "<<sf;
        total = subtotal+sf; //qDebug()<<"total = "<<total;
        a = new QTableWidgetItem(QString::number(total));
        a->setTextAlignment(Qt::AlignCenter);
        table->setItem(i, Etotal, a);

        QPushButton *push;
        QSlider *slider;
        if(index<2){
            push = new QPushButton("CANCEL");
            connect(push, SIGNAL(clicked()), this, SLOT(pressCancel()));
        }
        else if(index == 2){
            push = new QPushButton("RECEIVED");
            connect(push, SIGNAL(clicked()), this, SLOT(pressReceived()));
        }
        else if(index == 3){
            slider = new QSlider(Qt::Horizontal);
            QObject::connect(slider, SIGNAL(valueChanged(int)), SLOT(setPoint(int)));
            slider->setMaximum(5);
            slider->setMinimum(0);
            slider->setPageStep(1);
            slider->setSingleStep(1);
            push = new QPushButton("Comment");
            connect(push, SIGNAL(clicked()), this, SLOT(pressComment()));
        }
        switch(index){
        case 0:
            table->setCellWidget(i, Ecancel, push);
            a = new QTableWidgetItem((*itm.value().begin())->getDate().placed.toString("yyyy.MM.dd hh:mm"));
            a->setTextAlignment(Qt::AlignCenter);
            table->setItem(i, Edate, a); break;
        case 1:
            table->setCellWidget(i, Ecancel, push);
            a = new QTableWidgetItem((*itm.value().begin())->getDate().ship.toString("yyyy.MM.dd hh:mm"));
            a->setTextAlignment(Qt::AlignCenter);
            table->setItem(i, Edate, a); break;
        case 2:
            table->setCellWidget(i, Ecancel, push);
            a = new QTableWidgetItem((*itm.value().begin())->getDate().arrived.toString("yyyy.MM.dd hh:mm"));
            a->setTextAlignment(Qt::AlignCenter);
            table->setItem(i, Edate, a); break;
        case 3:
            a = new QTableWidgetItem("0");
            a->setTextAlignment(Qt::AlignCenter);
            table->setItem(i, Epoint, a);
            table->setCellWidget(i, Ecancel, slider);
            table->setCellWidget(i, Ecomment, push);
            a = new QTableWidgetItem((*itm.value().begin())->getDate().received.toString("yyyy.MM.dd hh:mm"));
            a->setTextAlignment(Qt::AlignCenter);
            table->setItem(i, Edate, a); break;
        case 4:
            a = new QTableWidgetItem((*itm.value().begin())->getDate().completed.toString("yyyy.MM.dd hh:mm"));
            a->setTextAlignment(Qt::AlignCenter);
            table->setItem(i, Edate, a); break;
        case 5:
            a = new QTableWidgetItem((*itm.value().begin())->getDate().canceled.toString("yyyy.MM.dd hh:mm"));
            a->setTextAlignment(Qt::AlignCenter);
            table->setItem(i, Edate, a); break;
        }
        i++;
    }
}
void ::UserInterface::pressCancel(void){
    //qDebug()<<"in press cancel";
    //qDebug()<<(dynamic_cast<QTableWidget>(QTableWidget*)(ui->tabWidget->))->currentIndex().row();
    //qDebug()<<"row count "<<qobject_cast<QTableWidget*>(ui->tabWidget->widget(0))->rowCount();
    int tab = ui->tabWidget->currentIndex();
    int index, orderID;
    switch (tab) {
        case 0:
            index = ui->tableWidget_1->currentRow();
            orderID = ui->tableWidget_1->item(index,0)->text().toInt();
            break;
        case 1:
            index = ui->tableWidget_2->currentRow();
            orderID = ui->tableWidget_2->item(index,0)->text().toInt();
            break;
        case 2:
            index = ui->tableWidget_3->currentRow();
            orderID = ui->tableWidget_3->item(index,0)->text().toInt();
            break;
        case 3:
            index = ui->tableWidget_4->currentRow();
            orderID = ui->tableWidget_4->item(index,0)->text().toInt();
            break;
    }
    //qDebug()<<"index = "<<index;
    //int orderID = qobject_cast<QTableWidget*>(ui->tabWidget->widget(tab))->item(index,0)->text().toInt();
    //qDebug()<<"orderID = "<<qobject_cast<QTableWidget*>(ui->tabWidget->widget(tab))->item(index,0)->text();

    query->exec("use userdata");
    query->exec("update orders set state = 5 , canceledDate = NOW() where orderID = "+QString::number(orderID));
    displayTable(tab);
}
void ::UserInterface::pressReceived(void){
    //qDebug()<<"in press received";
    //qDebug()<<(dynamic_cast<QTableWidget>(QTableWidget*)(ui->tabWidget->))->currentIndex().row();
    //qDebug()<<"row count "<<qobject_cast<QTableWidget*>(ui->tabWidget->widget(0))->rowCount();
    int index = index = ui->tableWidget_3->currentRow();
    int orderID = ui->tableWidget_3->item(index,0)->text().toInt();
    query->exec("use userdata");
    query->exec("update orders set state = 3 , receivedDate = NOW() where orderID = "+QString::number(orderID));
    qDebug()<<"update orders set state = 3 , receivedDate = NOW() where orderID = "+QString::number(orderID);
    displayTable(2);
}
void ::UserInterface::pressComment(void){
    comWD = new Comment;
    comWD->passQuery(query);
    comWD->setPage(ui->tableWidget_4->item(ui->tableWidget_4->currentRow(),0)->text().toInt());
    comWD->passUserInterface(this);
    comWD->show();
}
void UserInterface::on_mymarket_clicked()
{
    /*
        user_interface->clear();
        ui->graphicsView->viewport()->update();
        manage_stock_interface = new QGraphicsScene(0, 0, 998, 698);
        ui->graphicsView->setScene(manage_stock_interface);
        ui->graphicsView->setBackgroundBrush(QBrush(QColor{30, 78, 121}, Qt::SolidPattern));
        */
        //db = new DatabaseConnection("productsdb");
        db->exec("use productsdb;");
        Commodity::total = db->getMaxID();
        manage_stock = new MyMarket();
        manage_stock->passDB(db);
        manage_stock->passUser(user);
        manage_stock->passQuery(query);
        manage_stock->initial();
        manage_stock->show();
        this->hide();
}


void UserInterface::on_pushButton_myaccount_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    page_accountSet();
}


void UserInterface::on_pushButton_myorders_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
    ui->stackedWidget->setCurrentIndex(1);
    page_ordersSet();
}

bool UserInterface::checkUsername(QString input){
    QString take = "select * from users where name = '" + input +"'";
    query->exec(take);
    return (query->next());
}
bool UserInterface::checkName(){
    ui->label_usernameAlert->clear();
    QString username = ui->lineEdit_username->text();
    if(username!= user->getName() && checkUsername(username)){
        ui->label_usernameAlert->setText("Unvalid username");
        //ui->lineEdit_username->setStyleSheet("border: 2px solid red");
        return 0;
    }
    else{
        return 1;
    }
}
bool UserInterface::checkAccount(){
    ui->label_accountAlert->clear();
    QString acc = ui->lineEdit_account->text();
    if(!checkAccountformat(acc)){
        ui->label_accountAlert->setText("Unvalid account");
        return 0;
    }
    else{
        if(acc+ui->comboBox->currentText()!= user->getAccount()){
            //check whether the account is repeated
            QString take = "select * from users where account = '" + acc+ui->comboBox->currentText() +"'";
            query->exec(take);
            if(query->next()){
                ui->label_accountAlert->setText("Unvalid account");
                return 0;
            }
            else{

                return 1;
            }
        }
        else{
            return 1;
        }
    }
}


void UserInterface::on_pushButton_save_clicked()
{
    checkAccount();checkName();checkPwd();checkPhone();
    if(checkAccount()&&checkName()&&checkPwd()&&checkPhone()){
        ui->comboBox->setDisabled(1);
        ui->comboBox_gender->setDisabled(1);
        ui->lineEdit_account->setDisabled(1);
        ui->lineEdit_account->setStyleSheet("QLineEdit{border: 0px solid black;border-radius:6px; color: black;font: 14pt \"Consolas\";}");
        ui->lineEdit_editPWD->setDisabled(1);
        ui->lineEdit_editPWD->setStyleSheet("QLineEdit{border: 0px solid black;border-radius:6px; color: black;font: 14pt \"Consolas\";}");
        ui->lineEdit_phone->setDisabled(1);
        ui->lineEdit_phone->setStyleSheet("QLineEdit{border: 0px solid black;border-radius:6px; color: black;font: 14pt \"Consolas\";}");
        ui->lineEdit_username->setDisabled(1);
        ui->lineEdit_username->setStyleSheet("QLineEdit{border: 0px solid black;border-radius:6px; color: black;font: 14pt \"Consolas\";}");
        QString take = "update users set name = '"+ui->lineEdit_username->text()+"', gender = "+QString::number(ui->comboBox_gender->currentIndex())+", account = '"+ui->lineEdit_account->text()+ui->comboBox->currentText() +"', password = '"+ui->lineEdit_editPWD->text()+"', phone = '"+ui->lineEdit_phone->text()+"', birthday = '"+ ui->label_birthday->text() + "' where ID = " + user->getID();
        query->exec(take);
        PersonalData pd;
        pd.name = ui->lineEdit_username->text();
        pd.gender = ui->comboBox_gender->currentIndex();
        pd.phone = ui->lineEdit_phone->text();
        user->setPersonalData(pd);
        user->setAccount(ui->lineEdit_account->text() + ui->comboBox->currentText());
        user->setPWD(ui->lineEdit_editPWD->text());

        ui->username->setText(user->getName());
    }

}


bool UserInterface::checkPwd(){
    ui->label_pwdAlert->clear();
    QString pwd = ui->lineEdit_editPWD->text();
    if(checkPWDformat(pwd)!=0){
        ui->label_pwdAlert->setText("Unvalid Password");
        return 0;
    }
    else{
        return 1;
    }
}

bool UserInterface::checkPhone(){
    ui->label_phoneAlert->clear();
    QString phone = ui->lineEdit_phone->text();
    if(!checkPhoneformat(phone)){
        ui->label_phoneAlert->setText("Unvalid Phone");
        return 0;
    }
    else{
        return 1;
    }
}

void UserInterface::on_tabWidget_tabBarClicked(int index)
{
    ui->tabWidget->setStyleSheet("QTabBar::tab:selected { background-color: rgb(38, 115, 154); }");
}


void UserInterface::on_back_clicked()
{
    login = new MainWindow;
    db->exec("use userdata;");
    login->passQuery(query);
    login->passDB(db);
    this->hide();
    login->show();
}


void UserInterface::on_home_clicked()
{
    home = new HomePage;
    home->passQuery(query);
    home->passUser(user);
    db->exec("use productsdb;");
    home->passDB(db);
    home->initial();
    home->show();
    this->hide();
}

void UserInterface::on_tabWidget_currentChanged(int index)
{
    //qDebug()<<"currentchanged, index = "<<index;
    displayTable(index);
}


void UserInterface::on_tableWidget_1_doubleClicked(const QModelIndex &index)
{

    infoWD = new orderINFO;
    int orderID = ui->tableWidget_1->item(index.row(), 0)->data(0).toInt();
    //qDebug()<<"current orderID = "<<orderID;

    infoWD->pageSetting(user->getItemList(0, orderID));
    infoWD->show();
}
void UserInterface::on_tableWidget_2_doubleClicked(const QModelIndex &index)
{
    infoWD = new orderINFO;
    int orderID = ui->tableWidget_2->item(index.row(), 0)->data(0).toInt();
    qDebug()<<"current orderID = "<<orderID;
    infoWD->pageSetting(user->getItemList(1, orderID));
    infoWD->show();
}
void UserInterface::on_tableWidget_3_doubleClicked(const QModelIndex &index)
{
    infoWD = new orderINFO;
    int orderID = ui->tableWidget_3->item(index.row(), 0)->data(0).toInt();
    qDebug()<<"current orderID = "<<orderID;
    infoWD->pageSetting(user->getItemList(2, orderID));
    infoWD->show();
}
void UserInterface::on_tableWidget_4_doubleClicked(const QModelIndex &index)
{
    infoWD = new orderINFO;
    int orderID = ui->tableWidget_4->item(index.row(), 0)->data(0).toInt();
    qDebug()<<"current orderID = "<<orderID;
    infoWD->pageSetting(user->getItemList(3, orderID));
    infoWD->show();
}
void UserInterface::on_tableWidget_5_doubleClicked(const QModelIndex &index)
{
    infoWD = new orderINFO;
    int orderID = ui->tableWidget_5->item(index.row(), 0)->data(0).toInt();
    qDebug()<<"current orderID = "<<orderID;
    infoWD->pageSetting(user->getItemList(4, orderID));
    infoWD->show();
}
void UserInterface::on_tableWidget_6_doubleClicked(const QModelIndex &index)
{
    infoWD = new orderINFO;
    int orderID = ui->tableWidget_6->item(index.row(), 0)->data(0).toInt();
    qDebug()<<"current orderID = "<<orderID;
    infoWD->pageSetting(user->getItemList(5, orderID));
    infoWD->show();
}

void UserInterface::setPoint(int point)
{
    int curr = ui->tableWidget_4->currentRow();
    ui->tableWidget_4->item(curr, 5)->setText(QString::number(point));
}



void UserInterface::on_pushButton_edit_clicked()
{
    ui->comboBox->setEnabled(1);
    ui->comboBox_gender->setEnabled(1);
    ui->lineEdit_account->setEnabled(1);
    ui->lineEdit_account->setStyleSheet("QLineEdit{border: 2px solid black;border-radius:6px; color: black;font: 14pt \"Consolas\";}");
    ui->lineEdit_editPWD->setEnabled(1);
    ui->lineEdit_editPWD->setStyleSheet("QLineEdit{border: 2px solid black;border-radius:6px; color: black;font: 14pt \"Consolas\";}");
    ui->lineEdit_phone->setEnabled(1);
    ui->lineEdit_phone->setStyleSheet("QLineEdit{border: 2px solid black;border-radius:6px; color: black;font: 14pt \"Consolas\";}");
    ui->lineEdit_username->setEnabled(1);
    ui->lineEdit_username->setStyleSheet("QLineEdit{border: 2px solid black;border-radius:6px; color: black;font: 14pt \"Consolas\";}");
}

