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

public slots:

private slots:
    void InfoCommande(int);
};

#endif // COLLECTEURLOG_H
