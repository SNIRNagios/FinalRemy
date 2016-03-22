#include "collecteurlog.h"

collecteurlog::collecteurlog(QObject *parent) : QObject(parent)
{
    ftp = new QFtp();
    connect(ftp, SIGNAL(commandStarted(int)),this,SLOT(InfoCommande(int)));
}

void collecteurlog::Connexion(QString adresseip, qint16 port, QString login, QString motdepasse)
{
    qDebug() << "Login : " << login << "\n" << "Mot de passe : " << motdepasse << "\n";
    ftp->login(login, motdepasse);


    qDebug() << "Connexion à " << adresseip << ":" << port << "en cours...";
    ftp->connectToHost(adresseip,port);



}

void collecteurlog::Recuperation(QString nomfichier)
{

    QString path = "C://ProgramData/superviseur/logs";
    QFile *fichier = new QFile(path + "/" + nomfichier + ".log");
    qDebug() <<"Création du fichier dans : " << path + "/" + nomfichier + ".txt";

    if(!fichier->open(QIODevice::WriteOnly))
    {
        qDebug() << "Erreur lors de la creation du fichier";
        delete fichier;
    }
    else
    {
        ftp->get("/var/log/nagios3/nagios.log",fichier);
        qDebug() << "Ecriture réussie";
    }
}

void collecteurlog::InfoCommande(int id)
{
    qDebug() << "L'identifiant de la commande est : " << QString::number(id);
}








