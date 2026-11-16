# Architecture

The current runnable flow is **login → catalog → cart → order**. Qt Designer forms in `app/forms/mainwindow.ui` and `app/forms/homepage.ui` define the appearance. Classes in `app/src/screens/` attach behavior without copying the form layout into C++.

`Store` in `app/src/storage/` owns account, catalog, cart, and order operations. It opens either the SQLite or MySQL connection and uses the corresponding SQL schema and seed resources in `database/`. Both modes use the same screen code and table names. Passwords are stored as PBKDF2-SHA256 hashes with individual salts. Checkout runs in a database transaction and checks stock before committing.

## Product catalog

The catalog loads in-stock rows from `Store` into `ProductCatalogModel`. A sort and filter proxy handles name, category, and numeric price. The page proxy exposes a slice of eight rows to the `QListView`.

The view opens persistent editors for the current page. The delegate binds each editor to a product ID and sends that ID back for cart and detail actions. The window closes the editors before changing criteria or switching pages so card controls always reflect the current indexes. All query and checkout logic stays in `Store`.

The `.ui` files in `app/forms/reference/` are preserved from the original project but are not wired into the runnable flow. Password recovery, messaging, and distribution center actions are explicitly marked unavailable in the current desktop demo.
