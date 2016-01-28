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
    ui->BTN_getHosts->setEnabled(false);
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

    QMapIterator<QString, QString> it(equipements);//Iterateur de la QMap pour la parcourir

    while(it.hasNext())//Tant que l'iterateur posséde des items
    {
        it.next();//L'iterateur passe à l'item suivant
        ui->textEdit->append(it.key());//On affiche la key de l'item dans le textEdit (avec un saut de ligne)
    }

    insertion();
}

void fen_superviseur::insertion()
{
    //Boucle for pour l'insertion de ligne dans le tableau en fonction du nombre d'équipements
    for (int compteur = 0; compteur < (liste.size()-1)/2 ; compteur++)
    {
        ui->tableWidget->insertRow(compteur);//Insertion de ligne dans la tableWidget

        for (int j = 0; j < liste.size()-1; j++)//remplissage de la colonne
        {
            int i = 0;
            ui->tableWidget->setItem(compteur,i, new QTableWidgetItem(liste[i]));
            i++;
        }
    }
}


