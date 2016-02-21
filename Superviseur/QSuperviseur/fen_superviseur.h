#ifndef FEN_SUPERVISEUR_H
#define FEN_SUPERVISEUR_H
#include <QDialog>
#include <QWidget>
#include <QLabel>
#include <QString>
#include <QMap>
#include <QFile>
#include <QMessageBox>
#include <QTimer>
#include <QtXml>
#include "collecteur.h"

namespace Ui
{
    class fen_superviseur;
}
class fen_superviseur : public QDialog
{
    Q_OBJECT
public:
    explicit fen_superviseur(QWidget *parent = 0);
    void traitement();
    void insertion();
    void SupressionHote();
    void SupressionService();
    void initialisationTableHote();
    void initialisationTableService();
    void afficherHote();
    void hotes();
    void services();
    void deconnexion();
    void chargerThemeSombre();
    void Filtre(QString choix);
    int LectureFichierConfiguration();
    void lister(QDomElement root, QString tagname, QString attribute);
    ~fen_superviseur();
private slots:
    QString obtenirSocket(QString);

    void on_BTN_getHosts_clicked();
    void on_BTN_getServices_clicked();
    void on_BTN_Connexion_clicked();
    void on_BTN_Deconnexion_clicked();
    void on_toolButton_clicked();
    void interrogation();
    void analyseProblemeHote(int ligne, int colonne);
    void analyseProblemeService(int ligne, int colonne);
    void on_BTN_Timer_clicked();
    void on_BTN_StopTimer_clicked();
private:
    Ui::fen_superviseur *ui;
    QWidget *rectangle;
    QTimer *timer;
    QLabel *statusLabel;
    QLabel *nomEquipement;
    Collecteur *site;


    int demande;
    int frequence;
    int nombreBoucle;
    int count;
    int indexCollecteur;
    int k;

    quint16 portCollecteur;

    QString adresseCollecteur;
    QString portCollecteurStr;
    QString chemin;
    QString filtre;
    QString contenu;//Variable qui prendra la valeur de la socket

    QStringList liste;//Liste des hôtes et de leurs etats
    QMap<QString, QString> equipements;//QMap associant le noms des hotes et leurs etats
    QFile fichierConfiguration;

};
#endif // FEN_SUPERVISEUR_H
