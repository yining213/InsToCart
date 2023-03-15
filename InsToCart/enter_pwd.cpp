#include "enter_pwd.h"
#include "ui_enter_pwd.h"

enter_PWD::enter_PWD(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::enter_PWD)
{
    user = new Users;
    ui->setupUi(this);

    QPixmap photo(":/personal_photo.png");
    ui->label_photo->setPixmap(photo);

    scene = new QGraphicsScene(0, 0, 598, 358);
    pixmap = new QPixmap(598, 358);
    pixmap->fill(QColor(31, 78, 121, 255));

    painter = new QPainter(pixmap);
    item = new QGraphicsPixmapItem(*pixmap);

    scene->addItem(item);
    ui->foreground->setScene(scene);

    addstar=0;
    mask=1;
}
void enter_PWD::setInterface(){
    ui->pushButton_enter->setStyleSheet("QPushButton { background-color : white; color : white; }");
    ui->label_account->setText(user->getAccount());
    qDebug()<<"label account = "<<user->getAccount();
    ui->label_account->setStyleSheet("QLabel { color : white; }");
}
void enter_PWD::passUser(Users *u){
    user = u;
    qDebug()<<"enter_PWD finish passUser: user.account = "<<user->getAccount();
}

enter_PWD::~enter_PWD()
{
    delete ui;
}
void enter_PWD::on_pushButton_enter_clicked()
{
    mask=0;
    qDebug()<<pwd<<"\n";

    QString take = "select * from users where password = '" + pwd +"' and account = '" + user->getAccount() + "'";
    qDebug()<<take;
    query->exec(take);

    if(query->next()){
        qDebug()<<"exist"<<query->value(2).toString()<<"\n";
        next = new MainWindow(query, this);
        user->setPWD(pwd);
        this->hide();
        next->show();
        //go to manage stock
    }
    else{
        qDebug()<<"not exists\n";
        ui->lineEdit_PWD->setPlaceholderText("WRONG PASSWORD");
        ui->lineEdit_PWD->setText("WRONG PASSWORD");
    }
    mask=1;
}
void enter_PWD::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Return){
        mask=0;
        qDebug()<<pwd<<"\n";

        QString take = "select * from users where password = '" + pwd +"' and account = '" + user->getAccount() + "'";
        qDebug()<<take;
        query->exec(take);

        if(query->next()){
            qDebug()<<"exist"<<query->value(2).toString()<<"\n";
            next = new MainWindow(query, this);

            user->setPWD(pwd);
            this->hide();
            next->show();
            //go to manage stock
        }
        else{
            qDebug()<<"not exists\n";
            ui->lineEdit_PWD->setPlaceholderText("WRONG PASSWORD");
            ui->lineEdit_PWD->setText("WRONG PASSWORD");
        }
        mask=1;
    }
}


void enter_PWD::on_lineEdit_PWD_textChanged(const QString &arg1)
{
    int dif = addstar-arg1.size();
    for(int i=0;i<dif;i++){
        pwd.remove(pwd.size()-1, 1);
        addstar-=1;
    }
    if(addstar<arg1.size()){ //input
        pwd += arg1[arg1.size()-1];
        addstar = arg1.size();
    }
    /*
    else if(addstar>arg1.size()){ //delete
        pwd.remove(pwd.size()-1, 1);
        addstar = arg1.size();
    }
    */
    qDebug()<<"current pwd = "<<pwd;
    qDebug()<<ui->lineEdit_PWD->text();
    if(mask){
        int count = arg1.size();
        QString hide;
        for(int i=0;i<count;i++){
            hide += '*';
        }
        ui->lineEdit_PWD->setText(hide);
    }

}

