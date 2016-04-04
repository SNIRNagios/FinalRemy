#ifndef FEN_AJOUTERSITE_H
#define FEN_AJOUTERSITE_H

#include <QDialog>
#include "xmlsite.h"
#include <QComboBox>

namespace Ui {
class FEN_AjouterSite;
}

class FEN_AjouterSite : public QDialog
{
    Q_OBJECT

public:
    explicit FEN_AjouterSite(QWidget *parent = 0);
    ~FEN_AjouterSite();

private slots:
    void on_DBB_dialog_accepted();//Bouton dialog

private:
    Ui::FEN_AjouterSite *ui;//fenêtre
    QString nomSaisie;//Stocke le nom
    xmlSite * xmlsite; //Pointeur * configurateur vers la classe Configurateur pour accèder aux attributs et méthodes de celle-ci



};

#endif // FEN_AJOUTERSITE_H
