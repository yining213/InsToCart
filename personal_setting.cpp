#include "personal_setting.h"
#include "ui_personal_setting.h"
#include "user.h"
personal_setting::personal_setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::personal_setting)
{
    ui->setupUi(this);
    new_nextWD = 0;
}

personal_setting::~personal_setting()
{
    delete ui;
}

void personal_setting::on_pushButton_finish_clicked()
{
    ui->textBrowser_alert->clear();
    QString take;
    //get key-in personal data
    rep.name = ui->lineEdit_name->text();
    rep.phone = ui->lineEdit_phone->text();
    //check whether there is a duplicate name
    int num = checkPersonalDataformat(rep);
    if(num) printAlert(num);
    else{
        rep.birthday = ui->dateEdit_birthday->date();
        rep.gender = ui->comboBox_gender->currentIndex();

        user->setPersonalData(rep);
        //store into database
        take = "insert into users (ID, name, gender, account, password, phone, birthday) values("+user->getID()+", "+"'"+user->getName()+"'"+","+QString::number(user->getGender())+",'"+user->getAccount()+"','"+user->getPWD()+"','"+user->getPhone()+"','"+ user->getBirthday().toString("yyyy.MM.dd")+"')";
        //qDebug()<<"inser new data: "<<take;
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
void personal_setting::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Return){
        ui->textBrowser_alert->clear();
        QString take;
        //get key-in personal data
        rep.name = ui->lineEdit_name->text();
        rep.phone = ui->lineEdit_phone->text();
        //check whether there is a duplicate name
        int num = checkPersonalDataformat(rep);
        if(num) printAlert(num);
        else{
            rep.birthday = ui->dateEdit_birthday->date();
            rep.gender = ui->comboBox_gender->currentIndex();

            user->setPersonalData(rep);
            //store into database
            //insert into users (ID, account) values(15, '123@gmail.com');
            //qDebug()<<"personal data birthday: "<<rep.birthday.toString("yyyy.MM.dd");
            take = "insert into users (ID, name, gender, account, password, phone, birthday) values("+user->getID()+", "+"'"+user->getName()+"'"+","+QString::number(user->getGender())+",'"+user->getAccount()+"','"+user->getPWD()+"','"+user->getPhone()+"','"+ user->getBirthday().toString("yyyy.MM.dd")+"')";
            //qDebug()<<"inser new data: "<<take;
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
void personal_setting::printAlert(int num){
    if(num & 0x01){
        ui->textBrowser_alert->setText("Repeated Name\n");
    }
    if(num & 0x02){
        if(ui->textBrowser_alert->toPlainText() == ""){
            ui->textBrowser_alert->setText("Unvalid Phone Number\n");
        }
        else ui->textBrowser_alert->setText(ui->textBrowser_alert->toPlainText() + "Unvalid Phone Number\n");
    }
}
void personal_setting::on_pushButton_back_clicked()
{
    delete user;
    lastWD = new signup();
    lastWD->passQuery(query);
    this->hide();
    lastWD->show();
}
int personal_setting::checkPersonalDataformat(PersonalData input){
     //1: name conflict
     //2: phone number
    int alert = 0;
    QString take = "select * from users where name = '" + input.name +"'";
    qDebug()<<"checkPersonalData take = "<<take;
    query->exec(take);
    if(query->next()) alert|=0x01;
    if(input.phone.length()!=10) alert|=0x02;
    else{
        if(input.phone[0]!='0' && input.phone[1]!='9') alert|=0x02;
        else{
            for(int i=2;i<input.phone.length();i++){
                if(!isDigit(input.phone[i])){
                    alert|=0x02;
                    break;
                }
            }
        }
    }
    return alert;
}


