#-------------------------------------------------
#
# Project created by QtCreator 2016-07-24T10:19:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test_opencv
TEMPLATE = app

INCLUDEPATH +=/usr/include/opencv
LIBS += -L/usr/lib/x86_64-linux-gnu/ -lopencv_core  -lopencv_highgui

SOURCES += main.cpp\
        mainwindow.cpp \
    thread.cpp

HEADERS  += mainwindow.h \
    thread.h

FORMS    += mainwindow.ui
