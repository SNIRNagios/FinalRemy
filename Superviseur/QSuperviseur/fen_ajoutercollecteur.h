#ifndef FEN_AJOUTERCOLLECTEUR_H
#define FEN_AJOUTERCOLLECTEUR_H

#include <QDialog>
#include <QHostAddress>
#include "configurateur.h"

namespace Ui {
class FEN_AjouterCollecteur;
}

class FEN_AjouterCollecteur : public QDialog
{
    Q_OBJECT

public:
    explicit FEN_AjouterCollecteur(QWidget *parent = 0);
    ~FEN_AjouterCollecteur();

private slots:
    void on_DBB_dialog_accepted();

private:
    Ui::FEN_AjouterCollecteur *ui;
    QString nomSaisie;//Stocke le nom
    QString ipSaisie;//stocke l'ip
    Configurateur *configurateur;//Pointeur * configurateur vers la classe Configurateur pour accèder aux attributs et méthodes de celle-ci
    QHostAddress IP;//représente le format d'une adresse IPV4
};

#endif // FEN_AJOUTERCOLLECTEUR_H
