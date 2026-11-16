# InsToCart

InsToCart is a Qt desktop storefront prototype. It preserves the project's original login and product catalog forms while organizing the application around screens, domain models, and interchangeable SQL storage. Visitors can run it with SQLite; contributors can connect the same UI to a local MySQL database.

## What you can try

- Create an account and log in through the original Qt Designer login screen.
- Search, filter, and sort the eight sample products.
- Add products to a cart and place an order. Stock and order records persist in the selected database.

The source includes additional original `.ui` forms in `app/forms/reference/`. They are retained as design references; the runnable flow currently uses `mainwindow.ui` and `homepage.ui`.

## Quick start on macOS

Requires Qt 5 (`qmake`), Xcode command line tools, and the Qt SQLite driver.

```sh
./scripts/build-macos.sh
./build/InsToCart.app/Contents/MacOS/InsToCart
```

SQLite is the default. It stores data under the macOS application data directory. To use a custom location, set `INSTOCART_DATA_DIR` before launching. For MySQL setup and its Qt driver, read [docs/mysql-setup.md](docs/mysql-setup.md).

## Structure

```text
InsToCart/
├── app/
│   ├── assets/              # images and icons
│   ├── forms/               # original Qt Designer forms
│   │   └── reference/       # preserved forms outside the current flow
│   ├── src/
│   │   ├── screens/         # login, catalog, cart
│   │   ├── domain/          # product and cart data types
│   │   └── storage/
│   │       ├── sqlite/      # SQLite connection
│   │       └── mysql/       # MySQL connection
│   ├── InsToCart.pro
│   └── resources.qrc
├── database/
│   ├── sqlite/              # schema and sample data
│   └── mysql/               # schema and sample data
├── docs/
├── scripts/
└── README.md
```

See [docs/architecture.md](docs/architecture.md) for the data flow and current scope. No database credentials or generated database files belong in this repository.
