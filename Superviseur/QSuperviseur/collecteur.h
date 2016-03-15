#ifndef COLLECTEUR_H
#define COLLECTEUR_H

#include <QObject>
#include <QTcpSocket>
#include <QString>
#include <QHostAddress>
#include <QLabel>
#include <QDebug>


class Collecteur : public QObject
{
    Q_OBJECT  
private:
    QTcpSocket *socketLivestatus;
    QString adresseCollecteur;
    quint16 portLivestatus;
    QString cheminSocket;
    QString requete;
    QString texte;
    int etat;
public:
    explicit Collecteur(QObject *parent = 0);
    void deconnexionCollecteur();
    QString recevoirContenu();
signals:
    void vers_IHM_connexionEtat();
    void vers_IHM_deconnexionEtat();
    void vers_IHM_texte(QString);
private slots:
    void connexionEtat();
    void deconnexionEtat();
    void lectureCollecteur();
public slots: 
    void connexionCollecteur(QString collecteur);
    void obtenirHotes(QString query);
};

#endif // COLLECTEUR_H
