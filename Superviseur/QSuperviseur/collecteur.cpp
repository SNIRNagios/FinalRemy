#include "collecteur.h"

Collecteur::Collecteur(QObject *parent) : QObject(parent)
{
    portLivestatus = 6557;
    socketLivestatus = new QTcpSocket(this);
    connect(socketLivestatus, SIGNAL(connected()), this, SLOT(connexionEtat()));
    connect(socketLivestatus, SIGNAL(readyRead()), this, SLOT(lectureCollecteur()));
}

void Collecteur::connexionCollecteur(QString collecteur)
{ 
    adresseCollecteur = collecteur;
    socketLivestatus->connectToHost(adresseCollecteur, portLivestatus);
    /*if(socketLivestatus->waitForConnected(2000) == false)
    {
        qDebug() << "Impossible d'établir une connexion.";
    }
    else
    {
        qDebug() << "La connexion est un succés.";
    }*/
}

void Collecteur::obtenirHotes(QString query)
{
    QTextStream contenu(socketLivestatus);
    requete = query;
    contenu << requete << endl;
}

void Collecteur::deconnexionCollecteur()
{
    socketLivestatus->close();
}

void Collecteur::connexionEtat()
{
    emit vers_IHM_connexionEtat();
}

void Collecteur::lectureCollecteur()
{
    while(socketLivestatus->canReadLine())
    {
        texte = socketLivestatus->readAll();
        emit vers_IHM_texte(texte);
    }
}

QString Collecteur::recevoirContenu()
{
    return texte;
}






