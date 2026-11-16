# MySQL mode

MySQL is optional. The SQLite mode works without it. MySQL mode requires a running local MySQL server **and** a Qt 5 installation that provides the `QMYSQL` SQL driver. The Homebrew Qt 5 package on some Macs includes only `QSQLITE`; if `QMYSQL` is absent, the app reports that clearly at startup.

1. Install and start MySQL, for example with `brew install mysql@8.4` and `brew services start mysql@8.4`.
2. In a local MySQL administrator session, create a database and a dedicated user:

```sql
CREATE DATABASE instocart CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
CREATE USER 'instocart'@'127.0.0.1' IDENTIFIED BY 'choose-a-local-password';
GRANT ALL PRIVILEGES ON instocart.* TO 'instocart'@'127.0.0.1';
```

3. Install/build Qt's MySQL SQL driver for the **same Qt version and architecture** used to build the app. Verify that `QMYSQL` appears in `QSqlDatabase::drivers()`; the app reports a missing driver if it is unavailable. A SQLite driver cannot speak to MySQL.
4. Run the app with local connection settings:

```sh
export INSTOCART_MYSQL_HOST=127.0.0.1
export INSTOCART_MYSQL_PORT=3306
export INSTOCART_MYSQL_DATABASE=instocart
export INSTOCART_MYSQL_USER=instocart
export INSTOCART_MYSQL_PASSWORD='your-local-password'
./build/InsToCart.app/Contents/MacOS/InsToCart --backend mysql
```

The app applies `database/mysql/schema.sql` and inserts sample products only when the products table is empty. Never commit passwords, `.env`, or local database files. For a shared or production database, use a separate least-privilege account and manage migrations deliberately; this repository is a desktop portfolio prototype.
