#include "signup.h"
#include "ui_signup.h"

signup::signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    new_user = 0;
    new_nextWD = 0;
}

signup::~signup()
{
    delete ui;
}
void signup::on_pushButton_next_clicked()
{
    ui->textBrowser_alert->clear();
    //get key-in account
    QString acc = ui->lineEdit_account->text(); acc = acc.toLower();
    QString pwd = ui->lineEdit_password->text();
    QString suffix = ui->comboBox->currentText(); //email type
    //check account format
    if(!checkAccountformat(acc)){
        ui->textBrowser_alert->setText("NOT VALID ACCOUNT");
    }
    else{
        //set sql command
        //1. check whether the account is available
        QString take = "select * from users where account = '" + acc + suffix + "'";
        qDebug()<<"sign up account = "<<take;
        query->exec(take);

        if(query->next()){
            ui->textBrowser_alert->setText("ACCOUNT EXISTS");
        }
        else{
            if(checkPWDformat(pwd)) printAlert(checkPWDformat(pwd));
            else{ //correct format -> store data
                if(!new_user){
                    user = new User;
                    new_user = 1;
                }

                //getID
                take = "select count(*) from users";
                query->exec(take);
                query->next();
                user->setID(query->value(0).toInt() + 1);
                qDebug()<<"number = "<<user->getID();
                user->setAccount(acc+suffix);
                user->setPWD(pwd);

                //haven't store into sql, will do after setting personal data
                //go to personal data setting page
                if(!new_nextWD){
                    nextWD = new personal_setting();
                    new_nextWD = 1;
                }
                nextWD->passQuery(query);
                nextWD->passUser(user);
                nextWD->passDB(db);
                this->hide();
                nextWD->show();
            }
            /*
            take = "insert into users (ID, account) values(" + nums + ", '" + acc + "')";
            qDebug()<<take;
            query->exec(take);
            */
        }
    }
}
void signup::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Return){
        ui->textBrowser_alert->clear();
        //get key-in account
        QString acc = ui->lineEdit_account->text(); acc = acc.toLower();
        QString pwd = ui->lineEdit_password->text();
        QString suffix = ui->comboBox->currentText(); //email type
        //check account format
        if(!checkAccountformat(acc)){
            ui->textBrowser_alert->setText("NOT VALID ACCOUNT");
        }
        else{
            //set sql command
            //1. check whether the account is available
            QString take = "select * from users where account = '" + acc + suffix + "'";
            //qDebug()<<"sign up account = "<<take;
            query->exec(take);

            if(query->next()){
                ui->textBrowser_alert->setText("ACCOUNT EXISTS");
            }
            else{
                if(checkPWDformat(pwd)) printAlert(checkPWDformat(pwd));
                else{ //correct format -> store data
                    if(!new_user){
                        user = new User;
                        new_user = 1;
                    }

                    //getID
                    take = "select count(*) from users";
                    query->exec(take);
                    query->next();
                    user->setID(query->value(0).toInt() + 1);
                    //qDebug()<<"number = "<<user->getID();
                    user->setAccount(acc+suffix);
                    user->setPWD(pwd);

                    //haven't store into sql, will do after setting personal data
                    //go to personal data setting page
                    if(!new_nextWD){
                        nextWD = new personal_setting();
                        new_nextWD = 1;
                    }
                    nextWD->passQuery(query);
                    nextWD->passUser(user);
                    nextWD->passDB(db);
                    this->hide();
                    nextWD->show();
                }
                /*
                take = "insert into users (ID, account) values(" + nums + ", '" + acc + "')";
                qDebug()<<take;
                query->exec(take);
                */
            }
        }
    }
}
void signup::on_pushButton_back_clicked()
{
    lastWD = new MainWindow();
    if(new_user){ //delete data
        delete [] user;
        new_user = 0;
    }
    lastWD->passQuery(query);
    this->hide();
    lastWD->show();
}
void signup::printAlert(int num){
    if(num & 0x01){ //not enough length
        ui->textBrowser_alert->setText("Password length should be 8~15 characters\n");
    }
    if(num & 0x02){
        if(ui->textBrowser_alert->toPlainText() == "")
            ui->textBrowser_alert->setText("No English character\n");
        else ui->textBrowser_alert->setText(ui->textBrowser_alert->toPlainText() + "No English character\n");
    }
    if(num & 0x04){
        if(ui->textBrowser_alert->toPlainText() == "")
            ui->textBrowser_alert->setText("No digit");
        else ui->textBrowser_alert->setText(ui->textBrowser_alert->toPlainText() + "No digit");
    }
}
