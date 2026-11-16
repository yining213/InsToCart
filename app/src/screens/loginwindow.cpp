#include "loginwindow.h"
#include "storage/store.h"
#include <QDialog>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>

LoginWindow::LoginWindow(Store &backend) : store(backend) {
    ui.setupUi(this);
    setWindowTitle("InsToCart — Login");
    ui.lineEdit_password->setEchoMode(QLineEdit::Password);
    connect(ui.pushButton, &QPushButton::clicked, this, [this] { enter(); });
    connect(ui.lineEdit_password, &QLineEdit::returnPressed, this, [this] { enter(); });
    connect(ui.pushButton_signup, &QPushButton::clicked, this, [this] { signUp(); });
    connect(ui.pushButton_forgetPWD, &QPushButton::clicked, this, [this] {
        QMessageBox::information(this, "Password recovery", "Password recovery is not available in this demo. Create a new account.");
    });
    connect(ui.dist, &QPushButton::clicked, this, [this] {
        QMessageBox::information(this, "Distribution center", "Distribution center is not included in this desktop demo.");
    });
}

void LoginWindow::enter() {
    const QString account = ui.lineEdit_account->text().trimmed() + ui.comboBox->currentText();
    const int id = store.authenticate(account, ui.lineEdit_password->text());
    if (id < 0) { ui.label_prompt->setText("INCORRECT ACCOUNT OR PASSWORD"); return; }
    ui.label_prompt->setText("WELCOME");
    ui.lineEdit_password->clear();
    if (loggedIn) loggedIn(id);
}

void LoginWindow::signUp() {
    QDialog dialog(this);
    dialog.setWindowTitle("Create account");
    QFormLayout form(&dialog);
    QLineEdit name, password, confirm;
    password.setEchoMode(QLineEdit::Password);
    confirm.setEchoMode(QLineEdit::Password);
    form.addRow("Account name", &name);
    form.addRow("Password (8+ characters)", &password);
    form.addRow("Confirm password", &confirm);
    auto *buttons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    form.addRow(buttons);
    connect(buttons, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(buttons, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);
    if (dialog.exec() != QDialog::Accepted) return;
    if (password.text() != confirm.text()) {
        QMessageBox::warning(this, "Sign up", "Passwords do not match."); return;
    }
    if (!store.createAccount(name.text() + ui.comboBox->currentText(), password.text())) {
        QMessageBox::warning(this, "Sign up", store.error()); return;
    }
    ui.lineEdit_account->setText(name.text());
    ui.label_prompt->setText("ACCOUNT CREATED — PLEASE LOG IN");
}

void LoginWindow::setCredentialsForSmoke(const QString &name, const QString &password) {
    ui.lineEdit_account->setText(name);
    ui.lineEdit_password->setText(password);
}
void LoginWindow::submitForSmoke() { enter(); }
