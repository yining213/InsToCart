#include "screens/loginwindow.h"
#include "screens/homewindow.h"
#include "storage/store.h"
#include <QApplication>
#include <QDebug>
#include <QDir>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QStandardPaths>
#include <QTimer>
#include <QUuid>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QApplication::setOrganizationName("InsToCart");
    QApplication::setApplicationName("InsToCart");
    const QStringList args = app.arguments();
    const bool smoke = args.contains("--smoke-test");
    QString backend = "sqlite";
    const int modeIndex = args.indexOf("--backend");
    if (modeIndex >= 0 && modeIndex + 1 < args.size()) backend = args[modeIndex + 1];
    const QString configuredDir = qEnvironmentVariable("INSTOCART_DATA_DIR");
    const QString dataDir = configuredDir.isEmpty()
        ? QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) : configuredDir;
    Store store;
    if (!store.open(backend, dataDir)) {
        qCritical().noquote() << store.error();
        if (!smoke) QMessageBox::critical(nullptr, "InsToCart cannot start", store.error());
        return 1;
    }
    LoginWindow login(store);
    HomeWindow home(store);
    login.loggedIn = [&](int id) { home.setAccount(id); home.show(); login.hide(); };
    home.logout = [&] { home.hide(); login.show(); };
    login.show();
    if (smoke) {
        QTimer::singleShot(300, &app, [&] {
            const QString loginShot = qEnvironmentVariable("INSTOCART_SCREENSHOT_LOGIN");
            if (!loginShot.isEmpty() && !login.grab().save(loginShot)) { app.exit(2); return; }
            const QString name = "smoke" + QString::number(QRandomGenerator::global()->generate());
            const QString password = QUuid::createUuid().toString();
            if (!store.createAccount(name + "@nycu.edu.tw", password)) { qCritical() << store.error(); app.exit(3); return; }
            login.setCredentialsForSmoke(name, password);
            login.submitForSmoke();
            if (!home.isVisible() || login.isVisible()) { app.exit(4); return; }
            const QString homeShot = qEnvironmentVariable("INSTOCART_SCREENSHOT_HOME");
            if (!homeShot.isEmpty() && !home.grab().save(homeShot)) { app.exit(5); return; }
            const int id = store.authenticate(name + "@nycu.edu.tw", password);
            const QVector<Product> products = store.products();
            if (id < 1 || products.size() != 8) { app.exit(6); return; }
            if (!store.addToCart(id, products[0].id, 2) || store.cart(id).size() != 1) {
                qCritical() << store.error(); app.exit(7); return;
            }
            if (store.placeOrder(id) < 1 || !store.cart(id).isEmpty()) {
                qCritical() << store.error(); app.exit(8); return;
            }
            qInfo().noquote() << "Smoke test passed: login UI, catalog UI, eight products, cart, order (" + backend + ").";
            app.quit();
        });
    }
    return app.exec();
}
