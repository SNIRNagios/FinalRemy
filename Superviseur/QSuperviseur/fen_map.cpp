#include "fen_map.h"
#include "ui_fen_map.h"

fen_map::fen_map(QWidget *parent) : QDialog(parent),ui(new Ui::fen_map)
{
    ui->setupUi(this);
    connexionEtat = false;



    //allocation dynamique
    site = new Collecteur(this);
    timer = new QTimer();
    timerlog = new QTimer();
    timerHeure = new QTimer();
    qDebug() << heurePC.currentTime();
    ui->LE_Temps->setText("Heure : " + heurePC.currentTime().toString("hh:mm:ss"));
    //ftp = new QFtp();
    ftp = new collecteurlog(this);


    //Signaux et slots
    connect(site, SIGNAL(vers_IHM_texte(QString)),this,SLOT(obtenirSocket(QString)));//Le signal vers_IHM_texte(QString) est connecté au slot ObtenirSocket(QString)
    connect(site, SIGNAL(vers_IHM_connexionEtat()),this,SLOT(EtatConnexion()));
    connect(site, SIGNAL(vers_IHM_deconnexionEtat()),this,SLOT(EtatDeconnexion()));
    connect(timer, SIGNAL(timeout()), this, SLOT(Interrogation()));//Le signal timeout() et connecté au slot interrogation()
    connect(ui->treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)),this, SLOT(AffichageHotes(QTreeWidgetItem*,int)));
    connect(ui->TW_Hotes, SIGNAL(cellClicked(int,int)),this,SLOT(AffichageServices(int, int)));//Le signal cellClicked(int,int)est connecté au slot analyseProblemeHote(int,int)
    connect(ui->progressBar, SIGNAL(valueChanged(int)),  this, SLOT(Logloop(int)));
    connect(ftp, SIGNAL(vers_IHM_ProgressionTransfert(int)), ui->progressBar, SLOT(setValue(int)));
    connect(timerHeure, SIGNAL(timeout()), this, SLOT(RecuperationAutomatiqueLog()));
    connect(this, SIGNAL(siteTraiteValider()),this,SLOT(Validation()));
    connect(this, SIGNAL(siteTraiteErreur()),this,SLOT(Erreur()));

    ui->groupBox->setTitle("Sélectionnez un collecteur en cliquant sur son adresse IPv4");

    //EXECUTION DU PROGRAMME

    //demande = "adresse";//L'utilisateur demande a avoir une liste d'adresse
    LectureFichierConfiguration();//MISE A JOUR DE LA LISTE CONTENANT LES ADRESSES
    //demande = "nom";//L'utilisateur demande a avoir une liste de nom
    //LectureFichierConfiguration();//MISE A JOUR DE LA LISTE CONTENANT LES NOMS

    /*for (int i = 0; i < listeNom.count(); i++)//A partir des listes obtenues, une liste de qpushbutton et est crée ainsi que des qlabels
    {
        //BOUTON DE COULEUR
        QPushButton *p = new QPushButton("", this);//listeCollecteur[i]
        p->setMinimumHeight(30);
        p->setMinimumWidth(90);
        p->setStyleSheet("QPushButton {background:rgb(189, 17, 67);}");//rouge
        p->move(0,(i+1)*30);
        connect(p,SIGNAL(clicked(bool)),this,SLOT(alerte()));
        rectangle.append(p);

        //LABEL
        QLabel *l = new QLabel(listeNom[i] + "\n" + listeAdresse[i]);
        l->setMinimumHeight(25);
        l->setMinimumWidth(90);
        l->move(0,(i+1)*30);

        //AJOUT DU BOUTON ET LABEL DANS LE LAYOUT couche
        ui->couche->addRow(p,l);
    }*/

    timerHeure->start(1000);






    /*if(listeNom.isEmpty() || listeAdresse.isEmpty())
    {
        ui->LA_Satus->setText("Une erreur est intervenue lors de la lecture du fichier de configuration (" + fichierConfiguration.errorString() + ").");
    }
    else
    {
        ui->LA_Satus->setText("Liste de collecteur effectuée avec succès");
        k = 0;
        ui->LA_Satus->setText("Démarrage en cours...");
        //timer->start(1000);
    }*/

    //timerlog->start(5000);
}

void fen_map::alerte()
{
    QMessageBox alerte;
    alerte.setWindowTitle("Test");
    alerte.setIcon(QMessageBox::Critical);

    alerte.setText("");
    alerte.exec();
}


int fen_map::LectureFichierConfiguration()
{
    chemin = "C://ProgramData/superviseur/FichierSuperviseur.xml";
    fichierConfiguration.setFileName(chemin);

    QDomDocument document;
    QMessageBox alerte;
    alerte.setWindowTitle("Fichier de configuration non-reconnu");
    alerte.setIcon(QMessageBox::Critical);

    if(!fichierConfiguration.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString erreurMessage = fichierConfiguration.errorString();
        alerte.setText("Impossible d'ouvrir le fichier : " + erreurMessage + ".\nVeuillez vérifier l'emplacement du fichier de configuration FichierSuperviseur.xml.");
        alerte.exec();

        return -1;
    }
    else
    {
        if(!document.setContent(&fichierConfiguration))
        {

            alerte.setText("Impossible de charger le fichier.");
            return -1;
        }
        fichierConfiguration.close();
    }

    QDomElement racine = document.documentElement();
    //QString xml = document.toString();
    //ui->textEdit->append(xml);
    //ui->treeWidget->setColumnCount(2);

    //qDebug() << xml << "\n";

    qDebug() << "<" << racine.tagName() << ">";//<superviseur>

    QDomNode noeud = racine.firstChild();//<Lycee>


    do
    {
        QDomNodeList childnoeud = noeud.childNodes();//list of all children nodes

        QDomElement element = noeud.toElement();//convert QDomNode into a QDomElement

        QString nomSite = noeud.nodeName();

        //Obtenir attribut et valeurs du premier enfant
        QDomNamedNodeMap attributsNoeu = noeud.attributes();//all atributes
        QDomNode attributsItem = attributsNoeu.item(0);//first attr
        QDomAttr attributs = attributsItem.toAttr();//convert QDomNode into a QDomAttr
        QString attributeValue = attributs.value();//return the value of the attr

        qDebug() <<  attributeValue;// attr nom de <site>
        //Obtenir attribut et valeurs du premier enfant


        if(!element.isNull())
        {
            //AJOUT DE LA RACINE DANS QTREEWIDGET
            QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget);
            item->setText(0,attributeValue);
            qDebug() << nomSite;

            //AJOUT DES ENFANTS DANS QTREEWIDGET
            for(int i = 0; i < childnoeud.count(); i++)
            {
                QTreeWidgetItem *subitem = new QTreeWidgetItem(item);//création d'une sous-ligne

                //Nom du collecteur
                QDomNamedNodeMap z = childnoeud.at(i).attributes();//z contient tous les attributs de la ligne
                QDomNode attributsItems = z.namedItem("nom");//on pointe vers l'attribut name
                QDomAttr attributes = attributsItems.toAttr();//on transofmre name en attribut
                QString attributesValue = attributes.value();//on extraire la valeur de l'attribut name
                subitem->setText(0,attributesValue);//on ajouter la valeur dans la premiere colonne du treeview
                listeCollecteur << attributesValue;
                qDebug() << attributesValue;

                //Adresse
                attributsItems = z.namedItem("adresse");//on pointe vers l'attribut adresse
                attributes = attributsItems.toAttr();//on transofmre name en attribut
                attributesValue = attributes.value();//on extraire la valeur de l'attribut name
                subitem->setText(1,attributesValue);//on ajouter la valeur dans la premiere colonne du treeview
                listeCollecteur << attributesValue;
                qDebug() <<attributesValue;

                //Insertion
                item->addChild(subitem);//ajout de la sous-ligne dans le treewidget
            }
        }
        noeud = noeud.nextSibling();
    }while(!noeud.isNull());

    for(int i = 1; i < listeCollecteur.size(); i++)
    {
        ui->CB_Adresse->addItem(listeCollecteur[i++]);
    }







    qDebug() << "Lecture xml terminée";
    return 1;
}

fen_map::~fen_map()
{
    delete ui;
}

void fen_map::Validation()
{
    qDebug() << "Appel de Validation()";
}

void fen_map::Erreur()
{
    qDebug() << "Appel de Erreur()";
}

void fen_map::Interrogation()
{
    static int compteur = 0;
    static int nb = 0;
    static int minuteur = 0;

    if(compteur == 0)
    {
        ui->lcdNumber->display(compteur);//on affiche l'entier
        ui->LA_Satus->setText("Connexion au collecteur " + listeNom[nb]);//on informe l'utilisateur de la connexion
        site->connexionCollecteur(listeAdresse[nb]);
        compteur++;//on passe a la condition suivante
    }
    else if (compteur < 5 && connexionEtat == true)
    {
        ui->lcdNumber->display(compteur);//on affiche l'entier
        compteur++;
        ui->LA_Satus->setText("Connexion réussie à : " + listeNom[nb]);
        rectangle[nb]->setStyleSheet("QPushButton {background:rgb(0, 176, 80);}");//le bouton passe au vert
    }
    else if(compteur < 5 && connexionEtat == false)
    {
        ui->lcdNumber->display(compteur);//on affiche l'entier

        ui->LA_Satus->setText("Echec de connexion: " + listeNom[nb]);
        rectangle[nb]->setStyleSheet("QPushButton {background:rgb(112, 128, 144);}");//le bouton passe au vert
        compteur++;
    }
    else if(compteur == 5 && connexionEtat == true)
    {
        ui->lcdNumber->display(compteur);//on affiche l'entier
        site->deconnexionCollecteur();
        ui->LA_Satus->setText("Déconnexion : " + listeNom[nb]);
        compteur = 0;
        nb++;
        if(nb==nombreCollecteur)
        {
            nb = 0;
            compteur = 11;
        }
    }
    else if(compteur == 5 && connexionEtat == false)
    {
        ui->lcdNumber->display(compteur);//on affiche l'entier
        site->deconnexionCollecteur();
        ui->LA_Satus->setText("Déconnexion : " + listeNom[nb]);
        compteur = 0;
        nb++;
        if(nb==nombreCollecteur)
        {
            nb = 0;
            compteur = 11;
        }
    }
    else if(compteur == 11)
    {
        ui->LA_Satus->setText("Reprise dans " + QString::number(5-minuteur) + " secondes");

        if(minuteur < 5 && compteur > 10)
        {
            ui->lcdNumber->display(minuteur);
            minuteur++;
        }
        else if(minuteur == 5)
        {
            minuteur = 0;
            compteur = 0;
            nb = 0;
            ui->LA_Satus->setText("Reprise de l'interrogation...");
        }
    }
}

void fen_map::obtenirSocket(QString socketLivestatus)
{

    QRegExp caractere("[;/\n/]");

    if(requete == "Hotes")
    {
        contenu.append(socketLivestatus);
        contenusocket.append(socketLivestatus);
        listeHoteEtat.clear();
        listeHoteEtat = contenusocket.split(caractere);
        ui->textEdit->append("HOTES");
        for(int i = 0; i < listeHoteEtat.count(); i++)
        {
            ui->textEdit->append(listeHoteEtat[i]);
        }

        Remplissage(requete);
        contenusocket.clear();
    }
    else if(requete == "Services")
    {
        contenu.append(socketLivestatus);
        contenusocket.append(socketLivestatus);
        listeServiceEtat.clear();
        listeServiceEtat = contenusocket.split(caractere);
        ui->textEdit->append("SERVICES");
        for(int i = 0; i < listeServiceEtat.count(); i++)
        {
            ui->textEdit->append(listeServiceEtat[i]);
        }
        Remplissage(requete);
        contenusocket.clear();
    }





}


void fen_map::EtatConnexion()
{
    QString adresse = ui->treeWidget->currentItem()->text(1);
    connexionEtat = true;
}

void fen_map::EtatDeconnexion()
{
    QString adresse = ui->treeWidget->currentItem()->text(1);
    QString nom = ui->treeWidget->currentItem()->text(0);

    if(ui->TW_Hotes->rowCount() > 0)
    {
        ui->groupBox->setTitle("Connexion réussie : " +  nom + " (" + adresse + ")");

    }
    else
    {

        ui->groupBox->setTitle("Echec de la connexion : " + nom + " (" + adresse + ")");

    }

    connexionEtat = false;
}


void fen_map::on_pushButton_clicked()
{
    static bool affichageParametre = true;
    if(affichageParametre==true)
    {

        this->setFixedSize(1094, 699);
        affichageParametre = false;
    }
    else
    {
        this->setFixedSize(1094, 509);
        affichageParametre = true;

    }



}

void fen_map::on_PB_Logs_clicked()
{
    QString nom = ui->treeWidget->currentItem()->text(0);
    QString adresse = ui->treeWidget->currentItem()->text(1);

    recuperationLogs(adresse, nom + "_" + heurePC.currentTime().toString("hhmmss") + ".log");

}

void fen_map::recuperationLogs(QString adresse, QString nom)
{

    ftp->Connexion(adresse,21,"pi","SNIRNagios");
    ftp->Recuperation(nom);
}

void fen_map::Logloop(int value)
{
    if(value == 100)
    {
        ui->LA_InformationsUtilisateurs->setText("Téléchargement terminé");
    }
    else
    {
        ui->LA_InformationsUtilisateurs->setText("Transfert en cours...");
    }
}

void fen_map::AffichageHotes(QTreeWidgetItem* item, int colonne)
{
    ui->groupBox->setTitle("Veuillez sélectionner un collecteur");
    Supression("Hotes");
    Supression("Services");
    QString adresseIP = item->text(1);
    QString nomCollecteur = item->text(0);
    requete = "Hotes";

    if(adresseIP == "")
    {
        qDebug() << "Impossible de se connecte à " << adresseIP;

    }
    else
    {
        qDebug() << "AdresseIP : " << adresseIP;
        qDebug() << "Collecteur: " << nomCollecteur;
        ui->LA_InformationsUtilisateurs->setText("Tentative de connexion à " + nomCollecteur + " (" + adresseIP + ").");
        site->connexionCollecteur(adresseIP);
        site->obtenirHotes("GET hosts\nColumns: host_name state\n");

    }
}

void fen_map::AffichageServices(int ligne, int colonne)
{
    requete = "Services";
    Supression("Services");
    QString nomHote = ui->TW_Hotes->item(ligne,colonne-2)->data(0).toString();
    qDebug() << nomHote;

    QString adresse = ui->treeWidget->currentItem()->text(1);
    QString nom = ui->treeWidget->currentItem()->text(0);

    site->connexionCollecteur(adresse);
    site->obtenirHotes("GET services\nColumns: host_name service_description state\nFilter: host_name = " + nomHote + "\n");//Filter: state != 0\n

}

void fen_map::Remplissage(QString demande)
{
    if(demande == "Hotes")
    {

        ui->TW_Hotes->setEditTriggers(QAbstractItemView::EditTriggers(0));//On rend impossible l'édition des cellules de TW_Services
        ui->TW_Hotes->setColumnCount(3);//On ajoute 4 colonne à TW_Services
        ui->TW_Hotes->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);//On ajuste son entête 0
        ui->TW_Hotes->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);//On ajuste son entête 1
        QStringList enteteHote;//Créationd'une liste de string
        enteteHote << "Equipement" << "Etat" << "Statut";//On insére des QStrings dans la liste de QString
        ui->TW_Hotes->setHorizontalHeaderLabels(enteteHote);//On insére la liste dans l'entete de TW_Services
        ui->TW_Hotes->setColumnHidden(1, true);//On cache la troisiéme colonne pour une raison ergonomique

        int nom = 0;
        int state = 1;
        int compteurColonne = 0;
        int role =0;



        QString etats[2];
        etats[0] = "ACTIF";
        etats[1] = "NON-ACTIF";


        if(ui->TW_Hotes->rowCount() == 0)
        {
            //Boucle for pour l'insertion de ligne dans le tableau en fonction du nombre d'équipements
            for (int compteurLigne = 0; compteurLigne < (listeHoteEtat.size()-1)/2 ; compteurLigne++)
            {
                ui->TW_Hotes->insertRow(compteurLigne);//Insertion de ligne dans la tableWidget
                    //
                ui->TW_Hotes->setItem(compteurLigne,compteurColonne, new QTableWidgetItem(listeHoteEtat[nom]));//remplissage de la colonne nom
                    nom = nom +2;
                    //
                ui->TW_Hotes->setItem(compteurLigne,compteurColonne+1, new QTableWidgetItem(listeHoteEtat[state],role));//remplissage de la colonne Etat
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
        }

    }
    else if(demande == "Services")
    {
        //TW_SERVICES
        ui->TW_Services->setEditTriggers(QAbstractItemView::EditTriggers(0));//On rend impossible l'édition des cellules de TW_Services
        ui->TW_Services->setColumnCount(4);//On ajoute 4 colonne à TW_Services
        ui->TW_Services->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);//On ajuste son entête 0
        ui->TW_Services->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);//On ajuste son entête 1
        ui->TW_Services->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);//On ajuste son entête 3
        QStringList enteteService;//Créationd'une liste de string
        enteteService << "Equipement" << "Service "<< "Etat" << "Statut";//On insére des QStrings dans la liste de QString
        ui->TW_Services->setHorizontalHeaderLabels(enteteService);//On insére la liste dans l'entete de TW_Services
        ui->TW_Services->setColumnHidden(2, true);//On cache la troisiéme colonne pour une raison ergonomique

        int nom = 0;
        int service = 1;
        int state = 2;
        int compteurColonne = 0;

        QString etats[5];
        etats[0] = "ACTIF";
        etats[1] = "EN SUSPENS";
        etats[2] = "DANGER";
        etats[3] = "CRITIQUE";
        etats[4] = "INCONNU";


        int role = 0;


        //Boucle for pour l'insertion de ligne dans le tableau en fonction du nombre d'équipements
        for (int compteurLigne = 0; compteurLigne < (listeServiceEtat.size()-1)/3 ; compteurLigne++)
        {
            ui->TW_Services->insertRow(compteurLigne);//Insertion de ligne dans la tableWidget
            //
            ui->TW_Services->setItem(compteurLigne,compteurColonne, new QTableWidgetItem(listeServiceEtat[nom]));//remplissage de la colonne nom
            nom = nom +3;
            //
            ui->TW_Services->setItem(compteurLigne,compteurColonne+1, new QTableWidgetItem(listeServiceEtat[service]));
            service = service + 3;

            ui->TW_Services->setItem(compteurLigne,compteurColonne+2, new QTableWidgetItem(listeServiceEtat[state],role));//remplissage de la colonne Etat
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

void fen_map::Supression(QString element)
{
    if(element == "Hotes")
    {
        int nbLigne = ui->TW_Hotes->rowCount();
        ui->TW_Hotes->clearContents();
        for(int i = nbLigne; i >= 0; i--)
        {
            ui->TW_Hotes->removeRow(i);
        }

    }

    else if(element == "Services")
    {
        int nbLigne = ui->TW_Services->rowCount();
        ui->TW_Services->clearContents();
        for(int i = nbLigne; i >= 0; i--)
        {
            ui->TW_Services->removeRow(i);
        }
    }
}

void fen_map::RecuperationAutomatiqueLog()
{
    ui->LE_Temps->setText("Heure : " + heurePC.currentTime().toString("hh:mm:ss"));

    if(heurePC.currentTime().toString("hh:mm:ss") == "11:42:00")
    {
        timerHeure->stop();
    }

}

