#include "xmlsite.h"

xmlSite::xmlSite(QObject *parent) : QObject(parent)
{

}

bool xmlSite::lecture()

{

    //Affectation
    nomFichier="C://ProgramData/Superviseur/configuration.xml";// adresse de localisation du fichier de configuration

    //Lecture du fichier XML
    QXmlStreamReader reader; // Objet servant à la navigation

    fichier=new QFile(nomFichier);// créer un objet QFile pour intéragir avec le fichier de configuration

    //Ouverture du fichier et choix du mode d'ouverture
    if (fichier->open(QFile::ReadOnly | QFile::Text)) // Ouverture du fichier XML en lecture seule et en mode texte.
    {

        reader.setDevice(fichier); // Initialise l'instance reader avec le flux XML venant de file
        qDebug() << reader.lineNumber();
        reader.readNextStartElement();// On Passe à l'élément de start suivant
        qDebug() << reader.lineNumber();

        while (!reader.atEnd())// Effectue une boucle tant que le fichier XML n'a pas été lu entièrement
        {

            qDebug() << reader.name().toString();
            if (reader.name().toString() == "configuration")// Lit l'élément de start configuration
            {

                reader.readNextStartElement();//On passe à l'élément de start suivant

            }
            else
            {
                return false;
            }


            while(reader.name()=="site")//Lit l'élément de start site
            {

                nomSite= reader.attributes().value("nom").toString();//Lecture et récupération de l'attribut nom
                qDebug() << "Condition 2 réussie, le nom du site lu est:"<< nomSite;
                reader.readNextStartElement();//On passe à l'élément de start suivant

                static int i=1;//entier
                QStringList valeur;//Liste de string

                if(reader.name() == "collecteur")//Lit l'élément collecteur
                {
                    do
                    {


                         nomCollecteur = reader.attributes().value("nom").toString();//Lecture et recup du nom du collecteur
                         ipCollecteur = reader.attributes().value("ip").toString();//Lecture et recup de l'ip du collecteur

                         valeur <<  nomCollecteur << ipCollecteur;//Ajout des attributs dans la QStringList
                         m_collecteur[nomSite] = valeur;//Ajout du nom du site et des attributs du collecteur dans la QMap

                         qDebug() << QString::number(i) +  reader.name().toString() + " " + nomCollecteur + " " + ipCollecteur;
                         //qDebug() << reader.lineNumber();
                         i++;// Incrémentaion de i
                         reader.readNextStartElement();//Passe à l'élément suivant </collecteur>
                         reader.readNextStartElement();//Passe au collecteur suivant

                    } while(reader.name().toString() == "collecteur");//Tant que l'élément se nomme collecteur

                 }

                else
                 {
                return false;
                 }

               reader.readNextStartElement();//On passe à l'élément suivant


            } //fin du if

        }//fin du while

          fichier->close();//fermeture de l'objet
}





}//Fin de la méthode



void xmlSite::ajouterSite(QString nom)
{

    // Création et ouverture du fichier XML ou seulement ouverture du fichier XML si le fichier existe déjà
    // Ouverture du fichier en écriture et en texte.
    if(fichier->open(QFile::WriteOnly | QFile::Text))
    {
              // Permet d'éditer le fichier XML - Objet servant à l'écriture
              QXmlStreamWriter writer(fichier);

              // Active l'indentation du fichier XML pour avoir une meilleur visibilité
              writer.setAutoFormatting(true);//bool

              // Écrit l'en-tête du fichier XML : <?xml version="1.0" encoding="UTF-8" ?>
              writer.writeStartDocument();

              writer.writeStartElement("configuration");//<configuration>

              writer.writeStartElement("site");
              writer.writeAttribute("nom","Lycée");



              //for (initialisation; test de continuation; boucle)
            // for( int i=0; i < vector_nomCollecteur.size(); i++ )// size() Taille du tableau
           //   {

                  writer.writeStartElement("collecteur");//<collecteur>

                  writer.writeAttribute("nom","salle125");//Ajoute un nouvel attribut à l'élément collecteur
                  writer.writeAttribute("ip","127.0.0.1");//Ajoute un autre attribut à l'élément collecteur

                  writer.writeEndElement();//</collecteur>
             // }

              //vector_nomCollecteur.clear();
              //vector_ipCollecteur.clear();

              writer.writeEndElement();//</configuration>

              // Finalise le document XML
              writer.writeEndDocument();

              // Fermer le fichier pour bien enregistrer le document et ferme l'élément "configuration"
              fichier->close();
              // Message d'information généré après la mise à jour du fichier XML
              QMessageBox alerte;
              alerte.setWindowTitle("Enregistrement");
              alerte.setText("Le fichier de configuration a bien été mis à jour");
              alerte.setIcon(QMessageBox::Information);
              alerte.exec();

    }


}

void xmlSite::supprimerSite(QString nom)
{


}


