# Quick start

1. Install Qt 5 and the Xcode command line tools. With Homebrew: `brew install qt@5` and `xcode-select --install` if needed.
2. From the repository root, run `./scripts/build-macos.sh`.
3. Launch `./build/InsToCart.app/Contents/MacOS/InsToCart` or open the app bundle in Finder.
4. Click **SIGN UP**, create an account, then log in. SQLite is selected automatically.

For a clean test without changing your normal app data, run `./scripts/smoke-test.sh`. To select MySQL, see [mysql-setup.md](mysql-setup.md).

To work in Qt Creator, open `app/InsToCart.pro` and select a Qt 5 desktop kit. Build artifacts are kept outside the source tree by the command line script.
