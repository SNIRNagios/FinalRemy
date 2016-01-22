#include "collecteur.h"

Collecteur::Collecteur(QObject *parent) : QObject(parent)
{
    portLivestatus = 6557;
    socketLivestatus = new QTcpSocket();


    connect(socketLivestatus, SIGNAL(connected()), this, SLOT(connexionEtat()));
    connect(socketLivestatus, SIGNAL(readyRead()), this, SLOT(lectureCollecteur()));
}

void Collecteur::connexionCollecteur(QString collecteur)
{ 
    adresseCollecteur = collecteur;
    socketLivestatus->connectToHost(adresseCollecteur, portLivestatus);
}

void Collecteur::obtenirHotes(QString query)
{
    QTextStream contenu(socketLivestatus);
    requete = query;
    contenu << requete << endl;
    //contenu.setDevice(socketLivestatus);

    lectureCollecteur();
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
    QString texte;
    while(socketLivestatus->canReadLine())
    {
        texte = socketLivestatus->readLine();
    }
    emit vers_IHM_texte(texte);
}





