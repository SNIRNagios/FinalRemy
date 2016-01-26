#include "fen_superviseur.h"
#include "ui_fen_superviseur.h"

fen_superviseur::fen_superviseur(QWidget *parent) : QDialog(parent), ui(new Ui::fen_superviseur)
{
    ui->setupUi(this);
    statusLabel = new QLabel(this);
    site = new Collecteur(this);
    connect(site, SIGNAL(vers_IHM_texte(QString)),this,SLOT(obtenirSocket(QString)));
}

fen_superviseur::~fen_superviseur()
{
    delete ui;
    delete statusLabel;
}

void fen_superviseur::on_BTN_getHosts_clicked()
{
    site->connexionCollecteur("172.17.50.202");
    site->obtenirHotes("GET hosts\nColumns: host_name state\n");
}

QString fen_superviseur::obtenirSocket(QString socketLivestatus)
{
    contenu = socketLivestatus;
    traitement();
    return contenu;
}

void fen_superviseur::traitement()
{
    //Création de l'expression ";" et "\n" afin de pouvoir splitter le contenu de la socket avec ces caractéres
    QRegExp caractere("[;/\n/]");

    //On split la liste en plusieurs items à chaque rencontre de l'expression ";" et "\n"
    liste = contenu.split(caractere);

    //Inserer et associer le nom et l'etat de l'équipement dans le QMAP
    for (int i = 0; i < liste.size()-1; i++)
    {
       equipements[liste[i]] = liste[i+1];
       i++;
    }
}

