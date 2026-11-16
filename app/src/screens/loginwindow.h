#pragma once
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <functional>
class Store;

class LoginWindow : public QMainWindow {
public:
    explicit LoginWindow(Store &store);
    std::function<void(int)> loggedIn;
    void setCredentialsForSmoke(const QString &name, const QString &password);
    void submitForSmoke();

private:
    Ui::MainWindow ui;
    Store &store;
    void enter();
    void signUp();
};
