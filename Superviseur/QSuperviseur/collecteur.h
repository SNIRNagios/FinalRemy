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
    QString adresseCollecteur;
    QTcpSocket *socketLivestatus;
    quint16 portLivestatus;
    QString cheminSocket;
    QString requete;


public:
    explicit Collecteur(QObject *parent = 0);
    void deconnexionCollecteur();

signals:
    void vers_IHM_connexionEtat();
    void vers_IHM_texte(QString);

private slots:
    void connexionEtat();
    void lectureCollecteur();

public slots: 
    void connexionCollecteur(QString collecteur);
    void obtenirHotes(QString query);
};

#endif // COLLECTEUR_H
