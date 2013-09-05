#-------------------------------------------------
#
# Project created by QtCreator 2013-08-02T14:22:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += opengl
QT += network
QT += script

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp

HEADERS  += \
    progress.h \
    progress2.h \
    modelviewtest.h \
    filterproxymodeltest.h \
    palettetest.h \
    eventtest.h \
    opengltest.h \
    mainwidget.h \
    opengl3dtest.h \
    settingstest.h \
    menutest.h \
    threadtest.h \
    tcptest.h \
    scripttest.h

DESTDIR = ./
DEFINES += MY_DEFINE_qq

OTHER_FILES += \
    script.js

RESOURCES += \
    res.qrc
