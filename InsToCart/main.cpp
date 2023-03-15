#include "mainwindow.h"
#include "databaseconnection.h"
#include "commodity.h"
#include "userinterface.h"
#include "homepage.h"
#include "user.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

/*
    DatabaseConnection *db = new DatabaseConnection("productsdb");
    Commodity::total = db->getMaxID();
    User *user = new User;
    user->setAccount("ynh@nycu.edu.tw");
    user->setPWD("christine213");
    user->setID(16);
    HomePage *home;
    home = new HomePage();
    home->passDB(db);
    home->passQuery(db->getQuery());
    home->passUser(user);
    home->initial();
    home->show();
*/
     /*
    DatabaseConnection *db = new DatabaseConnection;
    db->exec("select * from class");
    Commodity::total = db->getSize();
    UserInterface user;
    user.passDB(db);
    user.show();
*/
    return a.exec();
}
