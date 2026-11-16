QT += core gui widgets sql network
CONFIG += c++17

INCLUDEPATH += $$PWD/src
SOURCES += \
    $$PWD/src/catalog/catalogmodel.cpp \
    $$PWD/src/catalog/productcarddelegate.cpp \
    $$PWD/src/screens/loginwindow.cpp \
    $$PWD/src/screens/homewindow.cpp \
    $$PWD/src/screens/cartdialog.cpp \
    $$PWD/src/storage/store.cpp \
    $$PWD/src/storage/sqlite/sqlitebackend.cpp \
    $$PWD/src/storage/mysql/mysqlbackend.cpp

HEADERS += \
    $$PWD/src/catalog/catalogmodel.h \
    $$PWD/src/catalog/productcarddelegate.h \
    $$PWD/src/domain/product.h \
    $$PWD/src/domain/cartline.h \
    $$PWD/src/screens/loginwindow.h \
    $$PWD/src/screens/homewindow.h \
    $$PWD/src/screens/cartdialog.h \
    $$PWD/src/storage/store.h \
    $$PWD/src/storage/sqlite/sqlitebackend.h \
    $$PWD/src/storage/mysql/mysqlbackend.h

FORMS += $$PWD/forms/mainwindow.ui $$PWD/forms/homepage.ui
RESOURCES += $$PWD/resources.qrc
macx:QMAKE_MACOSX_DEPLOYMENT_TARGET = 13.0
macx:QMAKE_LIBS_OPENGL = -framework OpenGL
