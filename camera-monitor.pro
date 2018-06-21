#-------------------------------------------------
#
# Project created by QtCreator 2018-06-14T14:24:37
#
#-------------------------------------------------

QT += core gui widgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = camera-monitor
TEMPLATE = app

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    camera_ihm.cpp

HEADERS += \
        mainwindow.h \
    camera_ihm.h

FORMS += \
        mainwindow.ui
