#include "forgetpwd.h"
#include "ui_forgetpwd.h"

ForgetPWD::ForgetPWD(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ForgetPWD)
{
    ui->setupUi(this);
    new_user = 0;
}

ForgetPWD::~ForgetPWD()
{
    delete ui;
}

void ForgetPWD::on_pushButton_next_clicked()
{
    ui->textBrowser_alert->clear();
    PersonalData rep;
    rep.name = ui->lineEdit_name->text();
    rep.phone = ui->lineEdit_phone->text();
    QString acc = ui->lineEdit_account->text();
    QString suffix = ui->comboBox->currentText();
    QString take = "select * from users where account = '" + acc+suffix +"'";
    qDebug()<<"in forgetPWD: "<<take;
    query->exec(take);
    if(query->next()){
        if(query->value(User::sName).toString() == rep.name && query->value(User::sPhone).toString() == rep.phone){
            //go to next window
            nextWD = new ChangePWD;
            if(!new_user){
                user = new User;
                new_user = 1;
            }
            user->setID(query->value(User::sID).toInt());
            user->setAccount(query->value(User::sAccount).toString());
            user->setPersonalData(rep);
            nextWD->passQuery(query);
            nextWD->passUser(user);
            nextWD->passDB(db);

            this->hide();
            nextWD->show();
        }
        else{
            ui->textBrowser_alert->setText("Wrong Personal Data");
        }
    }
    else{
        ui->textBrowser_alert->setText("Account does not exist");
    }
}
void ForgetPWD::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Return){
        ui->textBrowser_alert->clear();
        PersonalData rep;
        rep.name = ui->lineEdit_name->text();
        rep.phone = ui->lineEdit_phone->text();
        QString acc = ui->lineEdit_account->text();
        QString suffix = ui->comboBox->currentText();
        QString take = "select * from users where account = '" + acc+suffix +"'";
        qDebug()<<"in forgetPWD: "<<take;
        query->exec(take);
        if(query->next()){
            if(query->value(User::sName).toString() == rep.name && query->value(User::sPhone).toString() == rep.phone){
                //go to next window
                nextWD = new ChangePWD;
                if(!new_user){
                    user = new User;
                    new_user = 1;
                }
                user->setID(query->value(User::sID).toInt());
                user->setAccount(query->value(User::sAccount).toString());
                user->setPersonalData(rep);
                nextWD->passQuery(query);
                nextWD->passUser(user);
                nextWD->passDB(db);

                this->hide();
                nextWD->show();
            }
            else{
                ui->textBrowser_alert->setText("Wrong Personal Data");
            }
        }
        else{
            ui->textBrowser_alert->setText("Account does not exist");
        }
    }
}

void ForgetPWD::on_pushButton_back_clicked()
{
    if(new_user) delete [] user;
    lastWD = new MainWindow();
    lastWD->passQuery(query);
    this->hide();
    lastWD->show();
}

