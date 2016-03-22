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
#include <QTreeWidget>
#include <QTime>
#include <string>
#include "qftp.h"
#include "collecteur.h"
#include "collecteurlog.h"
using namespace std;

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

    void ajouterRacine(QString nom, QString statut);
    void ajouterEnfant(QTreeWidgetItem *parent, QString nom, QString adresse);
    void recuperationLogs(QString adresse, QString nom);
    void Remplissage(QString demande);
    void Supression(QString element);

    ~fen_map();

private:
    Ui::fen_map *ui;
    Collecteur *site;
    //QFtp *ftp;
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
    QStringList listeSite;
    QStringList listeHoteEtat;//Liste des hôtes et de leurs etats
    QStringList listeServiceEtat;

    QString contenusocket;//Variable qui prendra la valeur de la socket
    QString requete;

    QTimer *timer;
    QTimer *timerlog;
    QTime heurePC;
    collecteurlog *ftp;


private slots:
    void alerte();
    void obtenirSocket(QString);
    void Validation();
    void Erreur();
    void Interrogation();
    void on_pushButton_clicked();
    void EtatConnexion();
    void EtatDeconnexion();
    void on_PB_Logs_clicked();
    void AffichageHotes(QTreeWidgetItem*, int);
    void AffichageServices(int, int);
};

#endif // FEN_MAP_H
