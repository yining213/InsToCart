#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "enter_pwd.h"
bool MainWindow::sqlInitial = 0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Login");
    //user = new Users;
    new_user = 0;
    new_nextWD = 0;
    if(!sqlInitial){
        sqlConnection();
        sqlInitial = 1;
    }
    //myFrame->setStyleSheet(".QFrame{background-color: red; border: 1px solid black; border-radius: 10px;}");
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::sqlConnection(){
    db = new DatabaseConnection("userdata");
    /*
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("140.113.141.194");
    //database.setHostName("localhost");
    database.setDatabaseName("userdata");
    database.setUserName("wangmimi");
    //database.setUserName("username");
    database.setPassword("tsaimailoveyou");
    database.setPort(3306);
    bool ok = database.open();
    if(ok) qDebug()<<"Successful\nConnection";
    else qDebug()<<"Error:\nCannot connect!!!";
    query = new QSqlQuery(database);
    */
    query = db->getQuery();

}
void MainWindow::keyPressEvent(QKeyEvent *event){

    if(event->key() == Qt::Key_Return){
        //get key-in account and pwd
        QString acc = ui->lineEdit_account->text();
        QString pwd = ui->lineEdit_password->text();
        QString suffix = ui->comboBox->currentText();
        //set sql operation text
        query->exec("use userdata;");
        QString take = "select * from users where account = '" + acc+suffix +"' and password = '" + pwd + "'";
        //qDebug()<<take;
        query->exec(take);

        if(query->next()){
            qDebug()<<"account exist";

            if(!new_user){
                user = new User;
                user->setQuery(query);
                new_user = 1;
            }
            user->setAccount(acc+suffix);
            user->setPWD(pwd);
            userSetting();

            user->setID(query->value(0).toInt());

            //set next window
            if(!new_nextWD){
                nextWD = new HomePage;
                new_nextWD = 1;
            }
            nextWD->passQuery(query);
            nextWD->passUser(user);
            db->exec("use productsdb;");
            nextWD->passDB(db);
            nextWD->passQuery(db->getQuery());
            nextWD->initial();
            this->hide();
            nextWD->show();
        }
        else{
            take = "select * from users where account = '" + acc+suffix +"'";
            query->exec(take);
            if(query->next()) ui->label_prompt->setText("INCORRECT PASSWORD");
            else ui->label_prompt->setText("THIS ACCOUNT DOES NOT EXIST");

            qDebug()<<"not exists\n";
        }
    }
}
void MainWindow::on_pushButton_clicked() //click enter
{

    //for convenient
    QString take = "select * from users where account = 'xwpi22@nycu.edu.tw'";
    qDebug()<<take;
    query->exec(take);
    if(!new_user){
        user = new User;
        user->setQuery(query);
        new_user = 1;
    }
    user->setAccount("xwpi22@nycu.edu.tw");
    user->setPWD("iloveyou89");
    userSetting();

    //set next window
    if(!new_nextWD){
        nextWD = new HomePage;
        new_nextWD = 1;
    }
    //because go back to Mainwindow so delete user
    nextWD->passQuery(query);
    nextWD->passUser(user);
    db->exec("use productsdb;");
    nextWD->passDB(db);
    nextWD->passQuery(db->getQuery());
    nextWD->initial();
    this->hide();
    nextWD->show();
    /*

    //get key-in account and pwd
    QString acc = ui->lineEdit_account->text();
    QString pwd = ui->lineEdit_password->text();
    QString suffix = ui->comboBox->currentText();
    //set sql operation text
    query->exec("use userdata;");
    QString take = "select * from users where account = '" + acc+suffix +"' and password = '" + pwd + "'";
    //qDebug()<<take;
    query->exec(take);

    if(query->next()){
        qDebug()<<"account exist";
        if(!new_user){
            user = new User;
            new_user = 1;
        }
        user->setAccount(acc+suffix);
        user->setPWD(pwd);
        userSetting();
        user->setID(query->value(0).toInt());

        //set next window
        if(!new_nextWD){
            nextWD = new HomePage(this);
            new_nextWD = 1;
        }
        nextWD->passQuery(query);
        nextWD->passUser(user);
        db->exec("use productsdb;");
        nextWD->passDB(db);
        nextWD->passQuery(db->getQuery());
        nextWD->initial();
        this->hide();
        nextWD->show();
    }
    else{
        take = "select * from users where account = '" + acc+suffix +"'";
        query->exec(take);
        if(query->next()) ui->label_prompt->setText("INCORRECT PASSWORD");
        else ui->label_prompt->setText("THIS ACCOUNT DOES NOT EXIST");

        qDebug()<<"not exists\n";
    }
    */
}
void MainWindow::on_pushButton_signup_clicked()
{
    signupPage = new signup();
    signupPage->passQuery(query);
    signupPage->passDB(db);
    this->hide();
    signupPage->show();
}


void MainWindow::on_pushButton_forgetPWD_clicked()
{
    forgetPWDPage = new ForgetPWD();
    forgetPWDPage->passQuery(query);
    forgetPWDPage->passDB(db);
    this->hide();
    forgetPWDPage->show();
}
void MainWindow::userSetting(){
    QString take = "select * from users where account = '" + user->getAccount() + "'";
    //qDebug()<<"userSetting: take = "<<take;
    query->exec(take);
    if(query->next()){
        user->setID(query->value(0).toInt());
        user->setAuthority(0);
        PersonalData pd;
        pd.birthday = query->value(User::sBirthday).toDate();
        pd.name = query->value(User::sName).toString();
        //qDebug()<<"get name: "<<pd.name;
        pd.phone = query->value(User::sPhone).toString();
        pd.gender = query->value(User::sGender).toInt();
        user->setPersonalData(pd);
    }
}

void MainWindow::on_dist_clicked()
{
    check = new checkDist;
    check->passQuery(query);
    check->show();
}

