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
    int nom = 0;
    int state = 1;
    int compteurColonne = 0;

    QString etats[2];
    etats[0] = "fonctionnel";
    etats[1] = "plus de détails";

    QTableWidgetItem *item;
    QString value;

    int role =0;

    //item = ui->tableWidget->item()

    //Boucle for pour l'insertion de ligne dans le tableau en fonction du nombre d'équipements
    for (int compteurLigne = 0; compteurLigne < (liste.size()-1)/2 ; compteurLigne++)
    {
        ui->tableWidget->insertRow(compteurLigne);//Insertion de ligne dans la tableWidget
        //
        ui->tableWidget->setItem(compteurLigne,compteurColonne, new QTableWidgetItem(liste[nom]));//remplissage de la colonne nom
        nom = nom +2;
        //
        ui->tableWidget->setItem(compteurLigne,compteurColonne+1, new QTableWidgetItem(liste[state],role));//remplissage de la colonne Etat
        state = state + 2;
        role++;
        //
        if(ui->tableWidget->item(compteurLigne,compteurColonne+1)->data(0).toString() == "0")//Si la valeur de la cellule est 0
        {
            //ESSAI 1
            //QBrush vert;
            //vert.setColor(Qt::green);
            //ui->tableWidget->item(compteurLigne,compteurColonne+2)->setBackground(vert);

            //ESSAI 2
            ui->tableWidget->setItem(compteurLigne,compteurColonne+2, new QTableWidgetItem(etats[0]));
            QColor couleurVerte(51,255,102);
            ui->tableWidget->item(compteurLigne,compteurColonne+2)->setBackgroundColor(couleurVerte);

            //ESSAI 3
            //rectangle = new QWidget(this);
            //rectangle->setStyleSheet("background-color: red");
            //ui->tableWidget->setItem(compteurLigne,compteurColonne+2, new QTableWidgetItem(rectangle));

            //AUTRES ESSAIS
            //ui->tableWidget->item(compteurLigne,compteurColonne+2)->setBackground(Qt::green);
            //ui->tableWidget->item(compteurLigne,compteurColonne+2)->setData(QVariant(QBrush(Qt::green)),Qt::BackgroundRole);
            //ui->tableWidget->item(compteurLigne,compteurColonne+2)->setData(Qt::BackgroundRole, QVariant(QBrush(Qt::red)));
        }
        else
        {
            ui->tableWidget->setItem(compteurLigne,compteurColonne+2, new QTableWidgetItem(etats[1]));
            QColor couleurRouge(204,0,51);
            ui->tableWidget->item(compteurLigne,compteurColonne+2)->setBackgroundColor(couleurRouge);
        }






        /*
         * for (int compteurColonne = 0; compteurColonne < 2; compteurColonne++)//remplissage de la colonne
        {

            ui->tableWidget->setItem(compteurLigne,compteurColonne, new QTableWidgetItem(liste[indextab++]));//remplissage de la colonne nom
            indextab++;
        }
        */
    }
}


