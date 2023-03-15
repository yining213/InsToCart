QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cart.cpp \
    cartitem.cpp \
    cartwd.cpp \
    changepwd.cpp \
    checkdist.cpp \
    comment.cpp \
    commodity.cpp \
    databaseconnection.cpp \
    edititem.cpp \
    forgetpwd.cpp \
    homepage.cpp \
    main.cpp \
    mainwindow.cpp \
    mymarket.cpp \
    myorderdetail.cpp \
    order.cpp \
    orderdetail.cpp \
    orderinfo.cpp \
    ordersuccess.cpp \
    personal_setting.cpp \
    productsubpage.cpp \
    shippingwd.cpp \
    signup.cpp \
    user.cpp \
    userinterface.cpp

HEADERS += \
    cart.h \
    cartitem.h \
    cartwd.h \
    changepwd.h \
    checkdist.h \
    comment.h \
    commodity.h \
    databaseconnection.h \
    edititem.h \
    forgetpwd.h \
    homepage.h \
    mainwindow.h \
    mymarket.h \
    myorderdetail.h \
    order.h \
    orderdetail.h \
    orderinfo.h \
    ordersuccess.h \
    personal_setting.h \
    productsubpage.h \
    shippingwd.h \
    signup.h \
    user.h \
    userinterface.h

FORMS += \
    cartwd.ui \
    changepwd.ui \
    checkdist.ui \
    comment.ui \
    edititem.ui \
    forgetpwd.ui \
    homepage.ui \
    mainwindow.ui \
    mymarket.ui \
    myorderdetail.ui \
    orderINFO.ui \
    orderdetail.ui \
    ordersuccess.ui \
    personal_setting.ui \
    productsubpage.ui \
    shippingwd.ui \
    signup.ui \
    userinterface.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    back arrow.png \
    back arrow.png
