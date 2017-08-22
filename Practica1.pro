#-------------------------------------------------
#
# Project created by QtCreator 2017-08-10T23:03:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Practica1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    listadoble.cpp \
    nodo.cpp \
    listasimple.cpp \
    listadenlazada.cpp \
    contacto.cpp \
    lugares.cpp \
    dias.cpp \
    eventos.cpp

HEADERS += \
        mainwindow.h \
    listadoble.h \
    nodo.h \
    listasimple.h \
    listadenlazada.h \
    contacto.h \
    lugares.h \
    dias.h \
    eventos.h

FORMS += \
        mainwindow.ui
