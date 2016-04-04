#include "fen_administration.h"
#include "ui_fen_administration.h"

fen_administration::fen_administration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fen_administration)
{
    ui->setupUi(this);
}

fen_administration::~fen_administration()
{
    delete ui;
}

void fen_administration::on_PB_ajouterSite_clicked()//Slot bouton ajouter un nouveau site
{
    xmlSite site;
    site.lecture();//Traite la méthode lecture(); après que l'utilisateur ai cliqué sur le bouton ajouter site

    //Traitement et affichage de la fenêtre FEN_AjouterSite.ui
    FEN_AjouterSite fenetre;
    fenetre.setModal(true);
    fenetre.exec();
}

void fen_administration::on_PB_ajouterCollecteur_clicked()
{
    //Traitement et affichage de la fenêtre FEN_AjouterSite.ui
   FEN_AjouterCollecteur fenetre;
   fenetre.setModal(true);
   fenetre.exec();
}

