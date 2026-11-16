QT += core gui widgets sql network
CONFIG += c++17 app_bundle
TARGET = InsToCart
INCLUDEPATH += src src/domain src/screens src/storage src/storage/sqlite src/storage/mysql

SOURCES += \
    src/main.cpp \
    src/screens/loginwindow.cpp \
    src/screens/homewindow.cpp \
    src/screens/cartdialog.cpp \
    src/storage/store.cpp \
    src/storage/sqlite/sqlitebackend.cpp \
    src/storage/mysql/mysqlbackend.cpp

HEADERS += \
    src/domain/product.h \
    src/domain/cartline.h \
    src/screens/loginwindow.h \
    src/screens/homewindow.h \
    src/screens/cartdialog.h \
    src/storage/store.h \
    src/storage/sqlite/sqlitebackend.h \
    src/storage/mysql/mysqlbackend.h

FORMS += forms/mainwindow.ui forms/homepage.ui
RESOURCES += resources.qrc
macx:QMAKE_MACOSX_DEPLOYMENT_TARGET = 13.0
macx:QMAKE_LIBS_OPENGL = -framework OpenGL
