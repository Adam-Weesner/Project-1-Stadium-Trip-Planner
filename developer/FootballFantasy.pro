#-------------------------------------------------
#
# Project created by QtCreator 2016-11-20T20:09:48
#
#-------------------------------------------------

QT       += core gui
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FootballFantasy
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    secdialog.cpp \
    souvenirs.cpp \
    stadium.cpp

HEADERS  += mainwindow.h \
    secdialog.h \
    graph.h \
    souvenirs.h \
    stadium.h

FORMS    += mainwindow.ui \
    secdialog.ui
