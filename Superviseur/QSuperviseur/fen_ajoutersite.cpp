#include "fen_ajoutersite.h"
#include "ui_fen_ajoutersite.h"

FEN_AjouterSite::FEN_AjouterSite(QWidget *parent) :QDialog(parent),ui(new Ui::FEN_AjouterSite)
{
    xmlsite = new xmlSite(this);//aloue de la mémoire

    if(xmlsite->lecture() == true)
    {
        //L'ajout d'un nouveau site est possible


    }
    else
    {
        this->hide();//On cache la fenêtre
        //Ajouter un message d'alerte
    }

    ui->setupUi(this);



}

FEN_AjouterSite::~FEN_AjouterSite()
{
    delete ui;
    delete xmlsite;//delete libère la mémoire
}

void FEN_AjouterSite::on_DBB_dialog_accepted()
{
 nomSaisie= ui->LE_nom->text();// Récupération et stockage du nom saisie
 //xmlsite->ajouterSite(nomSaisie);//On accède à la méthode ajouterSite et on spécifie le nom en paramètres

}

