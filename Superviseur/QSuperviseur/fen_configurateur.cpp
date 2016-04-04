/*#include "fen_configurateur.h"
#include "ui_fen_configurateur.h"

FEN_Configurateur::FEN_Configurateur(QWidget *parent) : QDialog(parent),ui(new Ui::FEN_Configurateur)
{

     ui->setupUi(this);//Mettre en place les widgets sur la fenêtre
     configurateur = new Configurateur(this);//allocation dynamique

}

FEN_Configurateur::~FEN_Configurateur()
{
    delete ui;
    delete configurateur;//On libère la case mémoire
}



void FEN_Configurateur::on_PB_ajouterSite_clicked()//Slot bouton ajouter un nouveau site
{
    //Traitement et affichage de la fenêtre FEN_AjouterSite.ui
    FEN_AjouterSite fenetre;
    fenetre.setModal(true);
    fenetre.exec();
}

void FEN_Configurateur::on_PB_ajouterCollecteur_clicked()
{
    //Traitement et affichage de la fenêtre FEN_AjouterSite.ui
   FEN_AjouterCollecteur fenetre;
   fenetre.setModal(true);
   fenetre.exec();
}
*/
