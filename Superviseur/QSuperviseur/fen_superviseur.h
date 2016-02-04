#ifndef FEN_SUPERVISEUR_H
#define FEN_SUPERVISEUR_H
#include <QDialog>
#include <QWidget>
#include <QLabel>
#include <QString>
#include <QMap>
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

    ~fen_superviseur();
private slots:
    void on_BTN_getHosts_clicked();
    QString obtenirSocket(QString);

    void on_BTN_getServices_clicked();

    void on_BTN_Connexion_clicked();

    void on_BTN_Deconnexion_clicked();

private:
    Ui::fen_superviseur *ui;
    int demande;

    QWidget *rectangle;

    QLabel *statusLabel;
    QLabel *nomEquipement;

    Collecteur *site;

    QString contenu;//Variable qui prendra la valeur de la socket
    QStringList liste;//Liste des hôtes et de leurs etats

    QMap<QString, QString> equipements;//QMap associant le noms des hotes et leurs etats



};

#endif // FEN_SUPERVISEUR_H
