/*
fichier     fen_superviseur.cpp
résumé      Programme destiné à échanger des données avec un collecteur distant de type Raspberry Pi (nagios incl.).
            Ce programme est capable de traiter et d'analyser les données reçues sous forme de tableaux.
auteur      John BRUYERE
version     1.0
date        07/02/2016
*/

#include "fen_superviseur.h"
#include "ui_fen_superviseur.h"

/*
résumé      Constructeur par défaut ayant pour objectif de connecter des signaux aux slots et de pouvoir désactiver/cacher
            des éléments dés l'ouverture de la fenêtre.
*/
fen_superviseur::fen_superviseur(QWidget *parent) : QDialog(parent), ui(new Ui::fen_superviseur)
{
    ui->setupUi(this);

    //Allocation dynamique
    statusLabel = new QLabel(this);
    site = new Collecteur(this);

    //Création du timer
    timer = new QTimer();

    demande = 0;
    k = 0;
    portCollecteur = 6557;
    portCollecteurStr = QString::number(portCollecteur);//convertir le port en QString

    //Connexion SIGNAUX-SLOTS
    connect(timer, SIGNAL(timeout()), this, SLOT(interrogation()));//Le siganl timeout() et connecté au slot interrogation()
    connect(site, SIGNAL(vers_IHM_texte(QString)),this,SLOT(obtenirSocket(QString)));//Le signal vers_IHM_texte(QString) est connecté au slot ObtenirSocket(QString)
    connect(ui->TW_Hotes, SIGNAL(cellClicked(int,int)),this,SLOT(analyseProblemeHote(int, int)));//Le signal cellClicked(int,int)est connecté au slot analyseProblemeHote(int,int)

    //AUTRES
    ui->TW_Hotes->setEditTriggers(QAbstractItemView::EditTriggers(0));//On rend impossible l'édition des cellules de TW_Hotes

    //Appels de fonctions
    initialisationTableHote();//Appel de fonction pour initialiser TW_Hotes
    initialisationTableService();//Appel de fonction pour initialiser TW_Services

    //Désactivation provisoire
    ui->GB_Contenu->setEnabled(false);
    ui->BTN_Deconnexion->setEnabled(false);
    ui->BTN_StopTimer->setEnabled(false);

    //Element à cacher provisoirement
    ui->BTN_getHosts->hide();
    ui->BTN_getServices->hide();
}

/*
résumé      Destructeur.
*/
fen_superviseur::~fen_superviseur()
{
    delete ui;
    delete statusLabel;
    delete site;
    delete timer;
}

/*
résumé      Ce slot est activé lorsque qu'un utilisateur clique sur "Obtenir les Hôtes".
            Il se connecte à un collecteur pour pouvoir lui envoyer une requête LQL
param       Aucun
return      Aucun
*/
void fen_superviseur::on_BTN_getHosts_clicked()
{
    adresseCollecteur = ui->comboBox->currentText();
    site->connexionCollecteur(adresseCollecteur);
    site->obtenirHotes("GET hosts\nColumns: host_name state\n");
    demande = 1;
    ui->BTN_getHosts->setEnabled(false);
}

/*
résumé      Ce slot est activé lorsque qu'un utilisateur clique sur "Obtenir les Services".
            Il se connecte à un collecteur pour pouvoir lui envoyer une requête LQL
param       Aucun
return      Aucun
*/
void fen_superviseur::on_BTN_getServices_clicked()
{
    adresseCollecteur = ui->comboBox->currentText();
    site->connexionCollecteur(adresseCollecteur);
    site->obtenirHotes("GET services\nColumns: host_name service_description state\nFilter: state != 0\n");
    demande = 2;
    ui->BTN_getServices->setEnabled(false);
}

/*
résumé      Ce slot est activé lorsque le signal "vers_IHM_texte" de collecteur.cpp est émis.
            Ce slot place le contenu du socket obtenu dans un QString nommé "contenu" et fait appel aux fonctions
            "traitement()" et "insertion()" avant de retourner "contenu".
param       socketLivestatus [QString]
return      contenu [QString]
*/
QString fen_superviseur::obtenirSocket(QString socketLivestatus)
{
    contenu = socketLivestatus;
    traitement();
    insertion();
    return contenu;
}

/*
résumé      Cette méthode publique traite la variable contenu par le biais d'un QRegExp (expression) qui coupe la chaîne de caractére
            dés que celle-ci rencontre les caractéres ";" et "\n".Une fois coupé, ces QString sont envoyées dans une QStringList nommé "liste"
param       Aucun
return      Aucun
*/
void fen_superviseur::traitement()
{
    //Création de l'expression ";" et "\n" afin de pouvoir splitter le contenu de la socket avec ces caractéres
    QRegExp caractere("[;/\n/]");

    //On split la liste en plusieurs items à chaque rencontre de l'expression ";" et "\n"
    liste = contenu.split(caractere);
}

/*
résumé      Cette méthode publique affiche les hôtes dans le QTextEdit sous forme de liste.
            Elle en profite également pour associer le nom d'hôte et son état fonctionnel dans une QMap nommé "equipements"
param       Aucun
return      Aucun
*/
void fen_superviseur::afficherHote()
{

    for (int i = 0; i < liste.size()-1; i++)//Inserer et associer le nom et l'etat de l'équipement dans le QMAP
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
        ui->TE_Hotes->append("Aucun équipements");
    }
}


/*
résumé      Cette méthode publique insert les QStrings de la QStringList dans une QTableWidget en fonction de la demande envoyée.
            - Si la demande est de 1, alors on insert les éléments concernant les hôtes dans TW_Hôtes
            - Si la demande est de 2, alors on insert les éléments concernant les services dans TW_Services
param       Aucun
return      Aucun
*/
void fen_superviseur::insertion()
{

    if (demande == 1)
    {
        int nom = 0;
        int state = 1;
        int compteurColonne = 0;

        QString etats[2];
        etats[0] = "ACTIF";
        etats[1] = "NON-ACTIF";


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

/*
résumé      Ce slot est activé lorsqu'un utilisateur clique sur le bouton "Connexion".
            Il désactive et active certains éléments et fait apparaître deux nouveaux boutons nommé "BTN_getHosts" et "BTN_getServices".
            Sa fonction principale est de se connecter à un collecteur par le biais d'une instance "site" (collecteur rapsberry pi)
param       Aucun
return      Aucun
*/
void fen_superviseur::on_BTN_Connexion_clicked()
{
    //Activation provisoire
    ui->BTN_Deconnexion->setEnabled(true);
    ui->GB_Contenu->setEnabled(true);  
    ui->BTN_getHosts->setEnabled(true);
    ui->BTN_getServices->setEnabled(true);

    //Désactivation provisoire
    ui->comboBox->setEnabled(false);
    ui->GB_Interrogation->setEnabled(false);
    ui->BTN_Connexion->setEnabled(false);

    //Rend visible
    ui->BTN_getHosts->show();
    ui->BTN_getServices->show();

    adresseCollecteur = ui->comboBox->currentText();
    ui->GB_Contenu->setTitle(adresseCollecteur + ":" + portCollecteurStr);
}

/*
résumé      Ce slot est activé lorsqu'un utilisateur clique sur le bouton "Déconnexion".
            Il désactive et active certains éléments et cache les deux boutons nommé "BTN_getHosts" et "BTN_getServices".
            Sa fonction principale est de se déconnecter d'un collecteur par le biais d'une instance "site" (collecteur rapsberry pi)
param       Aucun
return      Aucun
*/
void fen_superviseur::on_BTN_Deconnexion_clicked()
{
    SupressionHote();
    SupressionService();
    ui->GB_Contenu->setEnabled(false);
    ui->BTN_Deconnexion->setEnabled(false);
    ui->BTN_Connexion->setEnabled(true);
    ui->comboBox->setEnabled(true);
    ui->GB_Interrogation->setEnabled(true);

    ui->BTN_getHosts->hide();
    ui->BTN_getServices->hide();

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

    initialisationTableHote();//Appel de la fonction initialisationTableService
}

void fen_superviseur::SupressionService()
{
    ui->TW_Services->setColumnHidden(2, false);//On rend visible la troisiéme colonne de TW_Service afin de pouvoir supprimer sont contenu

    int nbColonneService = ui->TW_Services->columnCount();//nbColonneService prend le nombre total de colonne crée dans TW_Services
    int nbLigneService = ui->TW_Services->rowCount();


    ui->TW_Services->clearContents();//On néttoie le contenu de TW_Services

    for (int h = 0; h < nbColonneService; h++)//On parcours les colonnes de TW_Hotes
    {
        ui->TW_Services->removeColumn(h);//On supprime toutes les colonnes parcourues
        for (int j = 0; j < nbLigneService; j++)//On parcours les lignes de TW_Services
        {
            ui->TW_Services->removeRow(j);//On supprime toutes les lignes parcourues
        }
    }

    initialisationTableService();//Appel de la fonction initialisationTableService
}

void fen_superviseur::initialisationTableHote()
{
    ui->TW_Hotes->setColumnCount(3);//On ajoute 4 colonne à TW_Hotes

    ui->TW_Hotes->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);//On ajuste son entête 0
    ui->TW_Hotes->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);//On ajuste son entête 2

    QStringList enteteHote;//Créationd'une liste de string
    enteteHote << "Equipement" << "Etat" << "Statut";//On insére des QStrings dans la liste de QString
    ui->TW_Hotes->setHorizontalHeaderLabels(enteteHote);//On insére la liste dans l'entete de TW_Services
    ui->TW_Hotes->setColumnHidden(1, true);//On cache la seconde colonne pour une raison ergonomique
}

void fen_superviseur::initialisationTableService()
{
    ui->TW_Services->setColumnCount(4);//On ajoute 4 colonne à TW_Services

    ui->TW_Services->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);//On ajuste son entête 0
    ui->TW_Services->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);//On ajuste son entête 1
    ui->TW_Services->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);//On ajuste son entête 3

    QStringList enteteService;//Créationd'une liste de string
    enteteService << "Equipement" << "Service "<< "Etat" << "Statut";//On insére des QStrings dans la liste de QString
    ui->TW_Services->setHorizontalHeaderLabels(enteteService);//On insére la liste dans l'entete de TW_Services
    ui->TW_Services->setColumnHidden(2, true);//On cache la troisiéme colonne pour une raison ergonomique

}

void fen_superviseur::chargerThemeSombre()
{
    QString fenetre = "QDialog#fen_superviseur{background: rgb(58, 58, 58);}";
    QString btn_connexion = "QPushButton#BTN_Connexion{background:rgb(94, 94, 94);}QPushButton#BTN_Connexion:hover{background:rgb(114, 140, 255);}QPushButton#BTN_Connexion:pressed{}";
    QString btn_deconnexion = "QPushButton#BTN_Deconnexion{background:rgb(114, 140, 255);}QPushButton#BTN_Deconnexion:hover{background:rgb(94, 94, 94);}QPushButton#BTN_Deconnexion:pressed{}";
    QString gb_contenu = "QGroupBox#GB_Contenu{color:rgb(114, 140, 255);}";
    QString gb_connexion = "QGroupBox#GB_Connexion{color:rgb(114,140,255);}";
    //QString tab_hote = "QTableWidget#TW_Hotes::section{background-color:rgb(58, 58, 58);";
    //QString tab_service = "QTableWidget#TW_Services{background-color:rgb(58, 58, 58);";

    fen_superviseur::setStyleSheet(fenetre);
    ui->BTN_Connexion->setStyleSheet(btn_connexion);
    ui->BTN_Deconnexion->setStyleSheet(btn_deconnexion);
    ui->GB_Contenu->setStyleSheet(gb_contenu);
    ui->GB_Connexion->setStyleSheet(gb_connexion);

}

void fen_superviseur::on_toolButton_clicked()
{
    chargerThemeSombre();
}

void fen_superviseur::analyseProblemeHote(int ligne, int colonne)
{
    QMessageBox alerte;//Création d'une QMessageBox nommé alerte
    alerte.setWindowTitle("Information");//On attribut un titre au QMessageBox

    if (ui->TW_Hotes->item(ligne,colonne)->data(0).toString() == "NON-ACTIF")//Si, lors du clique, le contenu de l'item vaut "NON-ACTIF" alors
    {
        alerte.setText("L'envoi de ping sur " + ui->TW_Hotes->item(ligne,colonne-2)->data(0).toString() + " a échoué.\n\n"
                       "• Vérifier que l'équipement est bien connecté.\n"
                       "• Vérifier que l'équipement est bien en état de marche.\n"
                       "• Vérifier les services ci-dessous.");//On place un message d'aide dans la QMessageBox alerte
        alerte.exec();//On excute la QMessageBox

    }


}

void fen_superviseur::interrogation()
{
    if (ui->comboBox->currentText().isEmpty())//Si l'item du combobox est une chaine de caractére vide
    {
        indexCollecteur = 0;
        ui->comboBox->setCurrentIndex(indexCollecteur);//On dirige l'index du combobox à 0
        nombreBoucle++;//Incrémentation de la variable nombreBoucle
        ui->LA_Boucle->setText("Boucle : " + QString::number(nombreBoucle));//On affiche le nombre de boucles exécutées
    }
    else
    {
        if(k==0)
        {
            ui->LCDN_Chrono->display(k);//on affiche la variable k sur le chronomètre
            adresseCollecteur = ui->comboBox->currentText();//On récupére le texte de l'item courant de la combobox
            ui->LA_Status->setText("Connexion à " + adresseCollecteur);//Le label de statut affiche un message
            k++;//Incrémentation de la variable k
            indexCollecteur++;//Incrémentation de l'indexCollecteur


        }
        else if (k==frequence)
        {
            ui->LCDN_Chrono->display(k);//on affiche la variable k sur le chronomètre
            ui->LA_Status->setText("Déconnexion de " + adresseCollecteur);//Le label de statut affiche un message
            ui->comboBox->setCurrentIndex(indexCollecteur);


            k = 0;//La variable k vaut zéro
        }
        else
        {
            ui->LCDN_Chrono->display(k);//on affiche la variable k sur le chronomètre
            ui->LA_Status->setText("Connexion établie avec succés sur " + adresseCollecteur);//Le label de statut affiche un message
            k++;//Incrémentation de la variable k
        }
    }
}

void fen_superviseur::on_BTN_Timer_clicked()
{
    frequence = ui->SB_Frequence->value();//La variable frequence récupére la valeur du spinbox
    timer->start(1000);//On active le timer qui s'executera toutes les 1000 msec (donc 1 seconde)
    adresseCollecteur = ui->comboBox->currentText();//On récupére le texte de l'item courant de la combobox
    indexCollecteur = ui->comboBox->currentIndex();
    nombreBoucle = 0;
    ui->LA_Boucle->setText("Boucle : " + QString::number(nombreBoucle));


    //Activation provisoire
    ui->BTN_StopTimer->setEnabled(true);

    //Désactivation provisoire
    ui->BTN_Timer->setEnabled(false);
    ui->GB_Connexion->setEnabled(false);
    ui->SB_Frequence->setEnabled(false);
}

void fen_superviseur::on_BTN_StopTimer_clicked()
{
    timer->stop();//On arrête le timer en cours de fonctionnement
    ui->LCDN_Chrono->display(0);//On initialise le timer avec la valeur zéro
    ui->LA_Status->setText("");//Le label de statut n'affiche rien
    k = 0;//On remet la variable k à 0 pour pouvoir re-activer le timer sans aucun probléme.
    ui->comboBox->setCurrentIndex(0);

    //Désactivation provisoire
    ui->SB_Frequence->setEnabled(true);
    ui->BTN_StopTimer->setEnabled(false);

    //Activation provisoire
    ui->GB_Connexion->setEnabled(true);
    ui->BTN_Timer->setEnabled(true);
}
