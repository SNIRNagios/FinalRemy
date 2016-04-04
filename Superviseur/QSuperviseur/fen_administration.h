#ifndef FEN_ADMINISTRATION_H
#define FEN_ADMINISTRATION_H

#include <QDialog>
#include "fen_ajoutercollecteur.h"
#include "fen_ajoutersite.h"

namespace Ui {
class fen_administration;
}

class fen_administration : public QDialog
{
    Q_OBJECT

public:
    explicit fen_administration(QWidget *parent = 0);
    ~fen_administration();

private:
    Ui::fen_administration *ui;
    Configurateur *configurateur;//Pointeur * configurateur vers la classe Configurateur pour accèder aux attributs et méthodes de celle-ci

private slots:
    void on_PB_ajouterSite_clicked();//Slot su bouton ajouter un site
    void on_PB_ajouterCollecteur_clicked();

};

#endif // FEN_ADMINISTRATION_H
