#-------------------------------------------------
#
# Project created by QtCreator 2016-01-10T16:56:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QSuperviseur
TEMPLATE = app


SOURCES += main.cpp\
        fen_accueil.cpp \
    fen_administration.cpp \
    fen_superviseur.cpp

HEADERS  += fen_accueil.h \
    fen_administration.h \
    fen_superviseur.h

FORMS    += fen_accueil.ui \
    fen_administration.ui \
    fen_superviseur.ui

RESOURCES += \
    ressources.qrc
