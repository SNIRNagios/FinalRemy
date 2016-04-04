#include "collecteurlog.h"

collecteurlog::collecteurlog(QObject *parent) : QObject(parent)
{
    ftp = new QFtp(this);
    connect(ftp, SIGNAL(commandStarted(int)),this,SLOT(InfoCommande(int)));
    connect(ftp, SIGNAL(listInfo(QUrlInfo)), this, SLOT(InfoList(QUrlInfo)));
    connect(ftp, SIGNAL(commandFinished(int,bool)), this, SLOT(Deconnexion(int,bool)));
    connect(ftp, SIGNAL(done(bool)), this, SLOT(TraitementCommande(bool)));
    connect(ftp,SIGNAL(dataTransferProgress(qint64,qint64)), this, SLOT(EnvoyerProgressionIHM(qint64, qint64)));
    connect(ftp, SIGNAL(stateChanged(int)),this,SLOT(EtatFTP(int)));

}

void collecteurlog::Connexion(QString adresseip, qint16 port, QString login, QString motdepasse)
{



    qDebug() << "Connexion à " << adresseip << ":" << port << "en cours...";
    ftp->connectToHost(adresseip,port);

    qDebug() << "Login : " << login << "\n" << "Mot de passe : " << motdepasse << "\n";
    ftp->login(login, motdepasse);
}

void collecteurlog::Recuperation(QString nomfichier)
{

    QString path = "C://ProgramData/superviseur/logs";
    QFile *fichier = new QFile(path + "/" + nomfichier);
    qDebug() <<"Création du fichier dans : " << path + "/" + nomfichier;


    if(!fichier->open(QIODevice::WriteOnly))
    {
        qDebug() << "Erreur lors de l'ouverture du fichier" << fichier->errorString();

        delete fichier;
    }
    else
    {
        ftp->get("/var/log/nagios3/nagios.log",fichier);
        qDebug() << "Ecriture réussie";
    }
}

void collecteurlog::Deconnexion(int commande , bool validation)
{
    qDebug() << "La commande : " << QString::number(commande) << validation;
    /*if(validation == false)
    {
        qDebug() << "Récupération terminée"<<"\n"<< "Déconnexion en cours";
        ftp->close();
    }
    else
    {
        qDebug() << "La récupération a échoué"<<"\n"<< "Déconnexion en cours";
    }

    /*qDebug() << "Info : " <<  validation << " -> récupération terminée.";*/
    //ftp->close();
}

void collecteurlog::InfoCommande(int id)
{
    qDebug() << "L'identifiant de la commande est : " << QString::number(id);
}

void collecteurlog::InfoList(QUrlInfo info)
{
    qDebug() << info.name();
}

void collecteurlog::EnvoyerProgressionIHM(qint64 currentValue, qint64 total)
{

    //qDebug() << currentValue*100/total;
    emit vers_IHM_ProgressionTransfert(currentValue*100/total);
}

void collecteurlog::EtatFTP(int stateChanged)
{
    switch(stateChanged)
    {
    case 0:
        qDebug() << "StateChanged(Unconnected)";
        break;
    case 1:
        qDebug() << "StateChanged(HostLookup)";
        break;
    case 2:
        qDebug() << "StateChanged(Connecting)";
        break;
    case 3:
        qDebug() << "StateChanged(Connected)";
        break;
    case 4:
        qDebug() << "StateChanged(Logged In)";
        break;
    case 5:
        qDebug() << "StateChanged(Closing)";
        break;
    default:
        qDebug() << "StateChanged(Erreur)";
        break;
    }
}

void collecteurlog::TraitementCommande(bool erreur)
{
    if(erreur == false)
    {
        qDebug() << "Aucune erreures détéctées";
        ftp->close();
        qDebug() << "Déconnexion";
    }
    else
    {
        qDebug() << "Une erreur est intervenue";
    }
}














