#include "fen_superviseur.h"
#include "ui_fen_superviseur.h"

fen_superviseur::fen_superviseur(QWidget *parent) : QDialog(parent), ui(new Ui::fen_superviseur)
{
    ui->setupUi(this);
    statusLabel = new QLabel(this);
    site = new Collecteur(this);
    demande = 0;
    portCollecteur = 6557;
    portCollecteurStr = QString::number(portCollecteur);

    connect(site, SIGNAL(vers_IHM_texte(QString)),this,SLOT(obtenirSocket(QString)));
    ui->GB_Contenu->setEnabled(false);

    initialisationTableHote();
    initialisationTableService();

    ui->GB_Contenu->setEnabled(false);
    ui->BTN_Deconnexion->setEnabled(false);
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
    demande = 1;
    ui->BTN_getHosts->setEnabled(false);
}

void fen_superviseur::on_BTN_getServices_clicked()
{
    site->connexionCollecteur("172.17.50.202");
    site->obtenirHotes("GET services\nColumns: host_name service_description state\nFilter: state != 0\n");
    demande = 2;
    ui->BTN_getServices->setEnabled(false);
}



QString fen_superviseur::obtenirSocket(QString socketLivestatus)
{
    contenu = socketLivestatus;
    traitement();
    insertion();
    return contenu;
}

void fen_superviseur::traitement()
{
    //Création de l'expression ";" et "\n" afin de pouvoir splitter le contenu de la socket avec ces caractéres
    QRegExp caractere("[;/\n/]");

    //On split la liste en plusieurs items à chaque rencontre de l'expression ";" et "\n"
    liste = contenu.split(caractere);
}

void fen_superviseur::afficherHote()
{
    //Inserer et associer le nom et l'etat de l'équipement dans le QMAP
    for (int i = 0; i < liste.size()-1; i++)
    {
       equipements[liste[i]] = liste[i+1];
       i++;
    }

    if (demande == 1)
    {
        QMapIterator<QString, QString> it(equipements);//Iterateur de la QMap pour la parcourir

        while(it.hasNext())//Tant que l'iterateur posséde des items
        {
            it.next();//L'iterateur passe à l'item suivant
            ui->TE_Hotes->append(it.key());//On affiche la key de l'item dans le textEdit (avec un saut de ligne)
        }
    }
    else
    {
        ui->TE_Hotes->append("No devices");
    }
}

void fen_superviseur::insertion()
{

    if (demande == 1)
    {
        int nom = 0;
        int state = 1;
        int compteurColonne = 0;

        QString etats[2];
        etats[0] = "UP";
        etats[1] = "DOWN";


        int role =0;


        //Boucle for pour l'insertion de ligne dans le tableau en fonction du nombre d'équipements
        for (int compteurLigne = 0; compteurLigne < (liste.size()-1)/2 ; compteurLigne++)
        {
            ui->TW_Hotes->insertRow(compteurLigne);//Insertion de ligne dans la tableWidget
            //
            ui->TW_Hotes->setItem(compteurLigne,compteurColonne, new QTableWidgetItem(liste[nom]));//remplissage de la colonne nom
            nom = nom +2;
            //
            ui->TW_Hotes->setItem(compteurLigne,compteurColonne+1, new QTableWidgetItem(liste[state],role));//remplissage de la colonne Etat
            state = state + 2;
            role++;
            //
            if(ui->TW_Hotes->item(compteurLigne,compteurColonne+1)->data(0).toString() == "0")//Si la valeur de la cellule est 0
            {

                ui->TW_Hotes->setItem(compteurLigne,compteurColonne+2, new QTableWidgetItem(etats[0]));
                QColor couleurVerte(51,255,102);
                ui->TW_Hotes->item(compteurLigne,compteurColonne+2)->setBackgroundColor(couleurVerte);

            }
            else
            {
                ui->TW_Hotes->setItem(compteurLigne,compteurColonne+2, new QTableWidgetItem(etats[1]));
                QColor couleurRouge(204,0,51);
                ui->TW_Hotes->item(compteurLigne,compteurColonne+2)->setBackgroundColor(couleurRouge);
            }
        }

        afficherHote();

    }
    else if (demande == 2)
    {
        int nom = 0;
        int service = 1;
        int state = 2;
        int compteurColonne = 0;

        QString etats[5];
        etats[0] = "UP";
        etats[1] = "PENDING";
        etats[2] = "WARNING";
        etats[3] = "CRITICAL";
        etats[4] = "UNKNOWN";


        int role =0;

        //Boucle for pour l'insertion de ligne dans le tableau en fonction du nombre d'équipements
        for (int compteurLigne = 0; compteurLigne < (liste.size()-1)/3 ; compteurLigne++)
        {
            ui->TW_Services->insertRow(compteurLigne);//Insertion de ligne dans la tableWidget
            //
            ui->TW_Services->setItem(compteurLigne,compteurColonne, new QTableWidgetItem(liste[nom]));//remplissage de la colonne nom
            nom = nom +3;
            //
            ui->TW_Services->setItem(compteurLigne,compteurColonne+1, new QTableWidgetItem(liste[service]));
            service = service + 3;

            ui->TW_Services->setItem(compteurLigne,compteurColonne+2, new QTableWidgetItem(liste[state],role));//remplissage de la colonne Etat
            state = state + 3;
            role++;
            //
            if(ui->TW_Services->item(compteurLigne,compteurColonne+2)->data(0).toString() == "0")//Si la valeur de la cellule est 0
            {

                ui->TW_Services->setItem(compteurLigne,compteurColonne+3, new QTableWidgetItem(etats[0]));
                QColor couleurVerte(51,255,102);
                ui->TW_Services->item(compteurLigne,compteurColonne+3)->setBackgroundColor(couleurVerte);

            }
            else if (ui->TW_Services->item(compteurLigne,compteurColonne+2)->data(0).toString() == "1")
            {
                ui->TW_Services->setItem(compteurLigne,compteurColonne+3, new QTableWidgetItem(etats[2]));
                QColor couleurJaune(255,255,51);
                ui->TW_Services->item(compteurLigne,compteurColonne+3)->setBackgroundColor(couleurJaune);
            }
            else if (ui->TW_Services->item(compteurLigne,compteurColonne+2)->data(0).toString() == "2")
            {
                ui->TW_Services->setItem(compteurLigne,compteurColonne+3, new QTableWidgetItem(etats[3]));
                QColor couleurRouge(204,0,51);
                ui->TW_Services->item(compteurLigne,compteurColonne+3)->setBackgroundColor(couleurRouge);
            }
            else if (ui->TW_Services->item(compteurLigne,compteurColonne+2)->data(0).toString() == "3")
            {
                ui->TW_Services->setItem(compteurLigne,compteurColonne+3, new QTableWidgetItem(etats[4]));
                QColor couleurOrange(255,153,51);
                ui->TW_Services->item(compteurLigne,compteurColonne+3)->setBackgroundColor(couleurOrange);
            }
            else if (ui->TW_Services->item(compteurLigne,compteurColonne+2)->data(0).toString() == "4")
            {
                ui->TW_Services->setItem(compteurLigne,compteurColonne+3, new QTableWidgetItem(etats[5]));
                QColor couleurRouge(204,0,51);
                ui->TW_Services->item(compteurLigne,compteurColonne+3)->setBackgroundColor(couleurRouge);
            }

        }

    }
}


void fen_superviseur::on_BTN_Connexion_clicked()
{
    ui->BTN_Deconnexion->setEnabled(true);
    ui->GB_Contenu->setEnabled(true);
    ui->BTN_Connexion->setEnabled(false);
    ui->BTN_getHosts->setEnabled(true);
    ui->BTN_getServices->setEnabled(true);

    adresseCollecteur = ui->comboBox->currentText();
    ui->GB_Contenu->setTitle(adresseCollecteur + ":" + portCollecteurStr);
}

void fen_superviseur::on_BTN_Deconnexion_clicked()
{
    SupressionHote();
    SupressionService();
    ui->GB_Contenu->setEnabled(false);
    ui->BTN_Deconnexion->setEnabled(false);
    ui->BTN_Connexion->setEnabled(true);

    ui->GB_Contenu->setTitle("Veuillez-vous connecter en cliquant sur le bouton \"Connexion\".");
}

void fen_superviseur::SupressionHote()
{
    ui->TW_Hotes->setColumnHidden(1, false);

    int nbColonneHote = ui->TW_Hotes->columnCount();
    int nbLigneHote = ui->TW_Hotes->rowCount();


    ui->TW_Hotes->clearContents();

    for (int i = 0; i < nbColonneHote; i++)
    {
        ui->TW_Hotes->removeColumn(i);
        for (int j = 0; j < nbLigneHote; j++)
        {
            ui->TW_Hotes->removeRow(j);
        }
    }

    ui->TE_Hotes->clear();

    initialisationTableHote();
}

void fen_superviseur::SupressionService()
{
    ui->TW_Services->setColumnHidden(2, false);

    int nbColonneService = ui->TW_Services->columnCount();
    int nbLigneService = ui->TW_Services->rowCount();


    ui->TW_Services->clearContents();

    for (int h = 0; h < nbColonneService; h++)
    {
        ui->TW_Services->removeColumn(h);
        for (int j = 0; j < nbLigneService; j++)
        {
            ui->TW_Services->removeRow(j);
        }
    }

    initialisationTableService();
}



void fen_superviseur::initialisationTableHote()
{
    //TABLE WIDGET HOTES/////////////////////////////////////////////////////////////
    ui->TW_Hotes->setColumnCount(3);
    ui->TW_Hotes->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->TW_Hotes->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    QStringList enteteHote;
    enteteHote << "Equipement" << "Etat" << "Statut";
    ui->TW_Hotes->setHorizontalHeaderLabels(enteteHote);
    ui->TW_Hotes->setColumnHidden(1, true);
    //FIN DE LA TABLE HOTES//////////////////////////////////////////////////////////
}

void fen_superviseur::initialisationTableService()
{
    //TABLE WIDGET SERVICE/////////////////////////////////////////////////////////////
    ui->TW_Services->setColumnCount(4);//AJOUT DE 4 COLONNES///////////////////////////
    ui->TW_Services->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->TW_Services->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->TW_Services->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
    QStringList enteteService;
    enteteService << "Equipement" << "Service "<< "Etat" << "Statut";
    ui->TW_Services->setHorizontalHeaderLabels(enteteService);
    ui->TW_Services->setColumnHidden(2, true);
    //FIN DE LA TABLE WIDGET SERVICES//////////////////////////////////////////////////
}
