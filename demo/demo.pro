#-------------------------------------------------
#
# Project created by QtCreator 2018-01-31T11:07:59
#
#-------------------------------------------------
include(fvd.pri)
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = demo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp videosrc.cpp    videowidget.cpp tool1.cpp

HEADERS  += mainwindow.h   videosrc.h  videowidget.h tool1.h


FORMS    += mainwindow.ui
CONFIG +=c++11
unix:DEFINES+=IS_UNIX
