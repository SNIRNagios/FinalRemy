#-------------------------------------------------
#
# Project created by QtCreator 2016-01-10T16:56:33
#
#-------------------------------------------------

QT       += core gui network xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QSuperviseur
TEMPLATE = app


SOURCES += main.cpp\
        fen_accueil.cpp \
    fen_administration.cpp \
    fen_superviseur.cpp \
    collecteur.cpp \
    fen_map.cpp \
    qftp.cpp \
    qurlinfo.cpp \
    collecteurlog.cpp \
    fen_ajoutercollecteur.cpp \
    fen_ajoutersite.cpp \
    xmlcollecteur.cpp \
    xmlsite.cpp

HEADERS  += fen_accueil.h \
    fen_administration.h \
    fen_superviseur.h \
    collecteur.h \
    fen_map.h \
    qftp.h \
    qurlinfo.h \
    collecteurlog.h \
    fen_ajoutercollecteur.h \
    fen_ajoutersite.h \
    xmlcollecteur.h \
    xmlsite.h

FORMS    += fen_accueil.ui \
    fen_administration.ui \
    fen_superviseur.ui \
    fen_map.ui \
    fen_ajoutercollecteur.ui \
    fen_ajoutersite.ui

RESOURCES += \
    ressources.qrc
