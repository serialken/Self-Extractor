#-------------------------------------------------
#
# Project created by QtCreator 2011-05-25T16:17:50
#
#-------------------------------------------------

QT       += core gui

TARGET = untitled
TEMPLAT = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qextserialbase.cpp \
    qextserialport.cpp \
    win_qextserialport.cpp

HEADERS  += mainwindow.h \
    qextserialbase.h \
    qextserialport.h \
    win_qextserialport.h

FORMS    += mainwindow.ui

RESOURCES += \
    imgs.qrc
