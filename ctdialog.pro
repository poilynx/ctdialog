#-------------------------------------------------
#
# Project created by QtCreator 2016-03-08T12:14:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ctdialog
TEMPLATE = app


SOURCES += main.cpp \
    titlebar.cpp \
    ctdialog.cpp \
    testdialog.cpp \
    innerdialog.cpp

HEADERS  += \
    ctdialog.h \
    titlebar.h \
    testdialog.h \
    innerdialog.h

FORMS    += \
    titlebar.ui \
    testdialog.ui

RESOURCES += \
    rc.qrc
