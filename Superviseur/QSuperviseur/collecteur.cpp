#include "collecteur.h"

Collecteur::Collecteur(QObject *parent) : QObject(parent)
{
    portLivestatus = 6557;
    adresseCollecteur = new QHostAddress("172.17.50.202");
}

void Collecteur::connexionCollecteur(QHostAddress collecteur)
{
    socketLivestatus = new QTcpSocket(this);
    socketLivestatus->connectToHost(collecteur, portLivestatus);
}

void Collecteur::obtenirHotes(QString *contenuSocket)
{
    QTextStream contenu(socketLivestatus);
    QString requete = "GET hosts";
    contenu << requete << endl;
}

