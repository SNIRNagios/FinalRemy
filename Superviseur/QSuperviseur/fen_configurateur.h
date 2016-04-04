#ifndef FEN_CONFIGURATEUR_H
#define FEN_CONFIGURATEUR_H

#include <QDialog>
#include "configurateur.h"
#include "fen_ajoutercollecteur.h"
#include "fen_ajoutersite.h"


namespace Ui {
class FEN_Configurateur;
}

class FEN_Configurateur : public QDialog
{
    Q_OBJECT

public:
    explicit FEN_Configurateur(QWidget *parent = 0);
    ~FEN_Configurateur();

private slots:
    void on_PB_ajouterSite_clicked();//Slot su bouton ajouter un site
    void on_PB_ajouterCollecteur_clicked();

private:
    Ui::FEN_Configurateur *ui;
    Configurateur *configurateur;//Pointeur * configurateur vers la classe Configurateur pour accèder aux attributs et méthodes de celle-ci


};

#endif // FEN_CONFIGURATEUR_H
