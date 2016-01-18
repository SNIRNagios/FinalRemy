#ifndef COLLECTEUR_H
#define COLLECTEUR_H

#include <QObject>
#include <QTcpSocket>
#include <QString>
#include <QHostAddress>
#include <QLabel>

class Collecteur : public QObject
{
    Q_OBJECT
private:
    QHostAddress *adresseCollecteur;
    QTcpSocket *socketLivestatus;
    quint16 portLivestatus;
public:
    explicit Collecteur(QObject *parent = 0);
    bool connexionCollecteur(QHostAddress collecteur);

signals:

public slots:
};

#endif // COLLECTEUR_H
