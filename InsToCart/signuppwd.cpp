#include "signuppwd.h"
#include "ui_signuppwd.h"

signupPWD::signupPWD(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signupPWD)
{
    user = new Users;
    ui->setupUi(this);

    scene = new QGraphicsScene(0, 0, 598, 358);
    pixmap = new QPixmap(598, 358);
    pixmap->fill(QColor(31, 78, 121, 255));

    painter = new QPainter(pixmap);
    item = new QGraphicsPixmapItem(*pixmap);

    scene->addItem(item);
    ui->foreground->setScene(scene);

}

signupPWD::~signupPWD()
{
    delete ui;
}
void signupPWD::setInterface(){
    ui->pushButton->setStyleSheet("QPushButton { color : black; }");
    ui->label_acount->setText(user->getAccount());
    ui->label_acount->setStyleSheet("QLabel { color : white; }");

    qDebug()<<"label account = "<<user->getAccount();
    ui->label_signup->setStyleSheet("QLabel { color : white; }");
}
void signupPWD::on_pushButton_clicked()
{
    QString rep = ui->lineEdit_PWD->QLineEdit::text();
    QString take = "update users set password = '" + rep +"' where account = '" + user->getAccount();
    qDebug()<<take;
    query->exec(take);

    ps = new personal_setting;
    ps->passUser(user);
    ps->passQuery(query);
    this->hide();
    ps->setInterface();
    ps->show();
}
void signupPWD::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Return){
        QString rep = ui->lineEdit_PWD->QLineEdit::text();
        QString take = "update users set password = '" + rep +"' where account = '" + user->getAccount();
        qDebug()<<take;
        query->exec(take);

        ps = new personal_setting;
        ps->passUser(user);
        ps->passQuery(query);
        this->hide();
        ps->show();
    }
}

