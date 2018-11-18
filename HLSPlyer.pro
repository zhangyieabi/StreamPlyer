#-------------------------------------------------
#
# Project created by QtCreator 2018-11-07T22:39:05
#
#-------------------------------------------------

QT       += core gui network multimediawidgets widgets xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HLSPlyer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += /usr/local/include/vlc

SOURCES += \
        main.cpp \
        playermainwin.cpp

HEADERS += \
        playermainwin.h

FORMS += \
        playermainwin.ui

LIBS += /usr/local/lib/libvlc.so  \
        /usr/local/lib/libvlccore.so

DISTFILES += \
    config

