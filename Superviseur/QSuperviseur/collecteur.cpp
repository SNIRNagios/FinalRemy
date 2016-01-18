#include "collecteur.h"

Collecteur::Collecteur(QObject *parent) : QObject(parent)
{
    //PARTIE RESEAUX
    portLivestatus = 6557;
    adresseCollecteur = new QHostAddress("172.17.50.202");

}

bool Collecteur::connexionCollecteur(QHostAddress collecteur)
{
    socketLivestatus = new QTcpSocket(this);
    socketLivestatus->connectToHost(collecteur, portLivestatus);



    return true;
}

