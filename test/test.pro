TARGET = test
TEMPLATE = app
CONFIG  += console debug c++11
CONFIG -= app_bundle

QT += testlib
QT -= gui

INCLUDEPATH += .


# Input
SOURCES += testqstring.cpp
