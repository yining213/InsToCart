include(../app/app-components.pri)
QT += testlib
CONFIG += testcase console
CONFIG -= app_bundle
TARGET = InsToCartTests
SOURCES += catalogtests.cpp
