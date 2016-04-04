#ifndef CONFIGURATEUR_H
#define CONFIGURATEUR_H


#include <QObject>
#include <QVector>
#include <QString>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>

class Configurateur : public QObject
{
    Q_OBJECT

private:
    QFile * fichier; //Objet QFile pour intéragir avec le fichier XML
    QString nomFichier;// Nom du fichier XML traité

    QVector <QString> vector_ipCollecteur;// Tableau dynamique qui stockera temporairement les adresses IP
    QVector <QString> vector_nomCollecteur;// Tableau dynamique qui stockera temporairement le nom des sites distants
    QVector <QString> vector_nomSite;


    QString nomSite;//contient le nom du site récupéré
    QString nomCollecteur;//contient le nom du collecteur récupéré dans le formulaire IHM
    QString ipCollecteur;//contient l'ip récupérée dans le formulaire IHM
    int k;



public:
    explicit Configurateur(QObject *parent = 0);
    void Add(QString nom, QString ip);// Méthode pour ajouter une nouvelle configuration
    void Edit();


signals:

public slots:

};

#endif // CONFIGURATEUR_H
