#include "fen_map.h"
#include "ui_fen_map.h"

fen_map::fen_map(QWidget *parent) : QDialog(parent),ui(new Ui::fen_map)
{
    ui->setupUi(this);


    demande = "adresse";
    LectureFichierConfiguration();

    demande = "nom";
    LectureFichierConfiguration();




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

int fen_map::Lister(QDomElement root, QString balise, QString attribute)
{
    QDomNodeList items;
    QDomElement itemele;
    items = root.elementsByTagName(balise);
    int nombreCollecteur;
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




    for (int i = 0; i < nombreCollecteur; i++)
    {
        if(demande == "adresse")
        {
            QPushButton *p = new QPushButton("", this);//listeCollecteur[i]

            p->setMinimumHeight(30);
            p->setMinimumWidth(90);
            p->setStyleSheet("QPushButton {background:rgb(0, 176, 80);}");//vert
            //p->setStyleSheet("QPushButton {background:rgb(189, 17, 67);}");//rouge
            p->move(0,(i+1)*30);
            ui->couche->addWidget(p);
            rectangle.append(p);

        }
        else
        {
            QLabel *l = new QLabel(listeNom[i]);
            ui->coucheNom->addWidget(l);
        }

    }

    return nombreCollecteur;
}

fen_map::~fen_map()
{
    delete ui;
}




