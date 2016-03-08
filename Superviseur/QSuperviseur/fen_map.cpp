#include "fen_map.h"
#include "ui_fen_map.h"

fen_map::fen_map(QWidget *parent) : QDialog(parent),ui(new Ui::fen_map)
{
    ui->setupUi(this);
    site = new Collecteur(this);
    timer = new QTimer();
    connect(site, SIGNAL(vers_IHM_texte(QString)),this,SLOT(obtenirSocket(QString)));//Le signal vers_IHM_texte(QString) est connecté au slot ObtenirSocket(QString)
    connect(this, SIGNAL(siteTraiteValider()),this,SLOT(Validation()));
    connect(this, SIGNAL(siteTraiteErreur()),this,SLOT(Erreur()));

    connect(timer, SIGNAL(timeout()), this, SLOT(Interrogation()));//Le siganl timeout() et connecté au slot interrogation()

    demande = "adresse";
    LectureFichierConfiguration();//MISE A JOUR DE LA LISTE CONTENANT LES ADRESSES

    demande = "nom";
    LectureFichierConfiguration();//MISE A JOUR DE LA LISTE CONTENANT LES NOMS

    for (int i = 0; i < listeNom.count(); i++)
    {
        //BOUTON DE COULEUR
        QPushButton *p = new QPushButton("", this);//listeCollecteur[i]
        p->setMinimumHeight(30);
        p->setMinimumWidth(90);
        p->setStyleSheet("QPushButton {background:rgb(0, 176, 80);}");//vert
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
    k = 0;

    //timer = new QTimer();
    //connect(timer, SIGNAL(timeout()), this, SLOT(Interrogation(QString adresse)));
    //timer->start(1000);//On active le timer qui s'executera toutes les 1000 msec (donc 1 seconde)
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
    ui->LA_Erreur->setText("Communication réussie");
}

void fen_map::Erreur()
{
    ui->LA_Erreur->setText("Erreur de communication");
}

void fen_map::Interrogation()
{
    static int compteur = 0;

    if(compteur == 0)
    {
        ui->lcdNumber->display(compteur);
        compteur++;
        site->connexionCollecteur(listeAdresse[k]);
        site->obtenirHotes("GET hosts\nColumns: host_name state\n");
    }
    else if(compteur < 10)
    {
        ui->lcdNumber->display(compteur);
        compteur++;
    }
    else if(compteur == 10)
    {
        ui->lcdNumber->display(compteur);
        compteur = 0;
        site->deconnexionCollecteur();
        k++;
        if(k+1==nombreCollecteur)
        {
            k = 0;
        }

    }




}

void fen_map::obtenirSocket(QString socketLivestatus)
{
    static int q = 0;

    contenu.append(socketLivestatus);

    if (contenu[q].isEmpty() || contenu[q] == "")
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
    }
}






void fen_map::on_pushButton_clicked()
{
    timer->start(1000);//On active le timer qui s'executera toutes les 1000 msec (donc 1 seconde)

}
