#ifndef COLLECTEURLOG_H
#define COLLECTEURLOG_H

#include <QObject>
#include "qftp.h"

class collecteurlog : public QObject
{
    Q_OBJECT
private:
    QFtp *ftp;
public:
    explicit collecteurlog(QObject *parent = 0);
    void Connexion(QString adresseip, qint16 port, QString login, QString motdepasse);
    void Recuperation(QString nomfichier);

signals:
    void vers_IHM_ProgressionTransfert(int);

public slots:

private slots:
    void InfoCommande(int);
    void InfoList(QUrlInfo);
    void Deconnexion(int, bool);
    void EnvoyerProgressionIHM(qint64, qint64);
    void EtatFTP(int);
    void TraitementCommande(bool);


};

#endif // COLLECTEURLOG_H
