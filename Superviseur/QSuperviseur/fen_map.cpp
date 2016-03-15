#include "fen_map.h"
#include "ui_fen_map.h"

fen_map::fen_map(QWidget *parent) : QDialog(parent),ui(new Ui::fen_map)
{
    ui->setupUi(this);
    connexionEtat = false;
    ui->pushButton->hide();
    ui->textEdit->hide();

    //allocation dynamique
    site = new Collecteur(this);
    timer = new QTimer();

    //Signaux et slots
    connect(site, SIGNAL(vers_IHM_texte(QString)),this,SLOT(obtenirSocket(QString)));//Le signal vers_IHM_texte(QString) est connecté au slot ObtenirSocket(QString)
    connect(this, SIGNAL(siteTraiteValider()),this,SLOT(Validation()));
    connect(this, SIGNAL(siteTraiteErreur()),this,SLOT(Erreur()));
    connect(site, SIGNAL(vers_IHM_connexionEtat()),this,SLOT(EtatConnexion()));
    connect(site, SIGNAL(vers_IHM_deconnexionEtat()),this,SLOT(EtatDeconnexion()));
    connect(timer, SIGNAL(timeout()), this, SLOT(Interrogation()));//Le signal timeout() et connecté au slot interrogation()


    //EXECUTION DU PROGRAMME
    demande = "adresse";//L'utilisateur demande a avoir une liste d'adresse
    LectureFichierConfiguration();//MISE A JOUR DE LA LISTE CONTENANT LES ADRESSES
    demande = "nom";//L'utilisateur demande a avoir une liste de nom
    LectureFichierConfiguration();//MISE A JOUR DE LA LISTE CONTENANT LES NOMS

    for (int i = 0; i < listeNom.count(); i++)//A partir des listes obtenues, une liste de qpushbutton et est crée ainsi que des qlabels
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
    }
    if(listeNom.isEmpty() || listeAdresse.isEmpty())
    {
        ui->LA_Satus->setText("Une erreur est intervenue lors de la lecture du fichier de configuration (" + fichierConfiguration.errorString() + ").");
    }
    else
    {
        ui->LA_Satus->setText("Liste de collecteur effectuée avec succès");
        k = 0;
        ui->LA_Satus->setText("Démarrage en cours...");
        timer->start(1000);
    }
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
    QDomElement root = document.firstChildElement();

    if(demande == "adresse")
    {
        Lister(root, "collecteur", "adresse");
    }
    else
    {
        Lister(root, "collecteur", "name");
    }


    qDebug() << "Lecture xml terminée";
    return 1;
}

void fen_map::Lister(QDomElement root, QString balise, QString attribute)
{
    QDomNodeList items;
    QDomElement itemele;
    items = root.elementsByTagName(balise);

    nombreCollecteur = items.count();
    qDebug() << "Nombre d'items " << items.count();


    for (int i = 0; i < items.count(); i++)
    {
        QDomNode itemNode = items.at(i);
        if(itemNode.isElement())
        {
            itemele = itemNode.toElement();
            if(demande == "nom")
            {
                listeNom << itemele.attribute(attribute);
            }
            else
            {
                listeAdresse << itemele.attribute(attribute);
            }
        }

    }
}

fen_map::~fen_map()
{
    delete ui;
}

void fen_map::Validation()
{
    //
}

void fen_map::Erreur()
{
    //
}

void fen_map::Interrogation()
{
    static int compteur = 0;
    static int nb = 0;
    static int minuteur = 0;

    /*if(compteur == 0)
    {
        ui->lcdNumber->display(compteur);//on affiche l'entier
        ui->LA_Satus->setText("Connexion au collecteur " + listeNom[nb]);//on informe l'utilisateur de la connexion
        site->connexionCollecteur(listeAdresse[nb]);
        compteur++;//on passe a la condition suivante
    }
    else if (compteur < 5)
    {
        if(connexionEtat == true)//si vrai
        {
            ui->lcdNumber->display(compteur);//on affiche l'entier
            compteur++;
            ui->LA_Satus->setText("Connexion réussie à : " + listeNom[nb]);
            rectangle[nb]->setStyleSheet("QPushButton {background:rgb(0, 176, 80);}");//le bouton passe au vert
        }
        else if(connexionEtat == false)//si faux
        {
            ui->lcdNumber->display("ERR");//on affiche l'entier
            rectangle[nb]->setStyleSheet("QPushButton {background:rgb(112, 128, 144);}");//le bouton passe au gris
            ui->LA_Satus->setText("Echec de connexion sur : " + listeNom[nb]);


            compteur = 0;
            nb++;
        }
    }
    else if(compteur == 5)
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
    else
    {
        ui->LA_Satus->setText("Reprise dans " + QString::number(30-minuteur) + " secondes");

        if(minuteur < 30 && compteur > 10)
        {
            ui->lcdNumber->display(minuteur);
            minuteur++;
        }
        else if(minuteur == 30)
        {
            connexionEtat = false;
            minuteur = 0;
            compteur = 0;
            nb = 0;
        }

    }*/
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
    static int q = 0;

    contenu.append(socketLivestatus);

    /*if (contenu[q].isEmpty() || contenu[q] == "")
    {
        rectangle[q]->setStyleSheet("QPushButton {background:rgb(189, 17, 67);}");
        q++;
        emit siteTraiteErreur();
    }
    else
    {
        rectangle[q]->setStyleSheet("QPushButton {background:rgb(0, 176, 80);}");//vert
        ui->textEdit->append(contenu[q]);
        q++;
        emit siteTraiteValider();
    }



    if(q == nombreCollecteur)
    {
        q = 0;
    }*/
}


void fen_map::EtatConnexion()
{
    connexionEtat = true;
}

void fen_map::EtatDeconnexion()
{
    connexionEtat = false;
}


void fen_map::on_pushButton_clicked()
{


    ui->LA_Satus->setText("");





    //On active le timer qui s'executera toutes les 1000 msec (donc 1 seconde)



}
