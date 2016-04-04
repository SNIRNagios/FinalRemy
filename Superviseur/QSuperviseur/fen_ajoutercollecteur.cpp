#include "fen_ajoutercollecteur.h"
#include "ui_fen_ajoutercollecteur.h"

FEN_AjouterCollecteur::FEN_AjouterCollecteur(QWidget *parent) : QDialog(parent),ui(new Ui::FEN_AjouterCollecteur)
{
    ui->setupUi(this);
    //configurateur =new Configurateur(this);//allocation de la mémoire
}

FEN_AjouterCollecteur::~FEN_AjouterCollecteur()
{
    delete ui;
    delete configurateur;//Libération de la mémoire
}

void FEN_AjouterCollecteur::on_DBB_dialog_accepted()
{
    //Fonction vérifiant si l'adresse saisie est correcte
      if(IP.setAddress(ui->LE_ip->text()))
      {
         ipSaisie= ui->LE_ip->text();// Récupération et stockage de l'adresse ip saisie
         nomSaisie= ui->LE_nom->text();// Récupération et stockage du nom saisie



        // configurateur->Add(nomSaisie,ipSaisie);// On accède à la méthode Add de la classe Configurateur et spécifie ces paramètres


      }
      else
      {
          //Affichage d'un message d'alerte lorsque l'adresse ip n'est pas valide
          QMessageBox alerte;
          alerte.setWindowTitle("Attention");
          alerte.setText("L'adresse IP saisie est invalide!");
          alerte.setIcon(QMessageBox::Warning);
          alerte.exec();
      }

}
