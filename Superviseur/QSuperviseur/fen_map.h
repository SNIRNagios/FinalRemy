#ifndef FEN_MAP_H
#define FEN_MAP_H

#include <QDialog>
#include <QWidget>
#include <QLabel>
#include <QString>
#include <QMap>
#include <QFile>
#include <QMessageBox>
#include <QTimer>
#include <QHBoxLayout>
#include <QtXml>
#include <QPushButton>
#include "collecteur.h"

namespace Ui {
class fen_map;
}

class fen_map : public QDialog
{
    Q_OBJECT

signals:
    void siteTraiteValider();
    void siteTraiteErreur();
public:
    explicit fen_map(QWidget *parent = 0);
    int LectureFichierConfiguration();
    void Lister(QDomElement root, QString tagname, QString attribute);



    ~fen_map();

private:
    Ui::fen_map *ui;
    Collecteur *site;
    QFile fichierConfiguration;
    QStringList listeAdresse;
    QStringList listeNom;
    QString chemin;
    QString demande;
    int nombreCollecteur;
    int k;
    bool connexionEtat;

    QList<QPushButton*> rectangle;
    QStringList contenu;//Variable qui prendra la valeur de la socket

    QTimer *timer;

private slots:
    void alerte();
    void obtenirSocket(QString);
    void Validation();
    void Erreur();
    void Interrogation();
    void on_pushButton_clicked();
    void EtatConnexion();
    void EtatDeconnexion();
};

#endif // FEN_MAP_H
