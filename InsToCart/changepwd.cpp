#include "changepwd.h"
#include "ui_changepwd.h"

ChangePWD::ChangePWD(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChangePWD)
{
    ui->setupUi(this);
    this->setWindowTitle("Change Password");

    new_user = 0;
}

ChangePWD::~ChangePWD()
{
    delete ui;
}

void ChangePWD::on_pushButton_next_clicked()
{
    ui->textBrowser_alert->clear();
    QString pwd1 = ui->lineEdit_password1->text();
    QString pwd2 = ui->lineEdit_password2->text();

    if(pwd1 != pwd2){
        ui->lineEdit_password2->setStyleSheet("QLineEdit{ background-color: red; border-radius: 10px; }");
        //ui->lineEdit_password2->setStyleSheet("QLineEdit{ background-color: red; border: 2px solid red; border-radius: 10px; }");
        ui->textBrowser_alert->setText("INCORRECT");
    }
    else if(checkPWDformat(pwd1)) printAlert(checkPWDformat(pwd1));
    else{
        //update database password
        //update gold_data set go_abroad = true where exchange_rate<32;
        QString take = "update users set password = '" + pwd1 +"' where account = '" + user->getAccount() +"'";
        query->exec(take);
        delete user;
        if(!new_nextWD){
            nextWD = new MainWindow();
            new_nextWD = 1;
        }
        nextWD->passQuery(query);
        nextWD->passDB(db);
        this->hide();
        nextWD->show();
    }
}
void ChangePWD::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Return){
        ui->textBrowser_alert->clear();
        QString pwd1 = ui->lineEdit_password1->text();
        QString pwd2 = ui->lineEdit_password2->text();

        if(pwd1 != pwd2){
            ui->lineEdit_password2->setStyleSheet("QLineEdit{ background-color: red; border-radius: 10px; }");
            ui->textBrowser_alert->setText("INCORRECT");
        }
        else if(checkPWDformat(pwd1)) printAlert(checkPWDformat(pwd1));
        else{
            //update database password
            //update gold_data set go_abroad = true where exchange_rate<32;
            QString take = "update users set password = '" + pwd1 +"' where account = '" + user->getAccount() +"'";
            query->exec(take);
            delete user;
            if(!new_nextWD){
                nextWD = new MainWindow();
                new_nextWD = 1;
            }
            nextWD->passQuery(query);
            nextWD->passDB(db);
            this->hide();
            nextWD->show();
        }
    }

}
void ChangePWD::printAlert(int num){
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
