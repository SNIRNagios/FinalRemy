#ifndef XMLSITE_H
#define XMLSITE_H

#include <QMessageBox>
#include <QObject>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>
#include <QMap>
#include <QDebug>


class xmlSite : public QObject
{
    Q_OBJECT

public:
    explicit xmlSite(QObject *parent = 0);
    bool lecture();//méthode de test
    void ajouterSite(QString nom);//méthode
    void supprimerSite(QString nom);
signals:

public slots:

private:
    QString nom;
    QString nomSite;
    QString nomCollecteur;
    QString ipCollecteur;

    //QVector <QString> v_nomSite;
    QMap<QString,QStringList> m_collecteur;

    QFile * fichier; //Objet QFile pour intéragir avec le fichier XML
    QString nomFichier;// Nom du fichier XML traité


};

#endif // XMLSITE_H
