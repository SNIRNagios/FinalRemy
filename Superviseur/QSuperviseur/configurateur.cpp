#include "configurateur.h"

Configurateur::Configurateur(QObject *parent) : QObject(parent)
{

}

void Configurateur::Add(QString nom, QString ip)
{

    //Lecture du fichier XML
      QXmlStreamReader reader; // Objet servant à la navigation

      //Affectation
      nomFichier="configuration.xml";
      fichier=new QFile(nomFichier);
      k=1;

      //Ouverture du fichier et choix du mode d'ouverture
      if (fichier->open(QFile::ReadOnly | QFile::Text)) // Ouverture du fichier XML en lecture seule et en mode texte.
      {

      reader.setDevice(fichier); // Initialise l'instance reader avec le flux XML venant de file

      //Le but de cette boucle est de parcourir le fichier et de vérifier si l'on est au début d'un élément.

    //Lit le jeton suivant et retourne son type
      reader.readNext();
    //Effectue une boucle tant que le fichier XML n'a pas été lu entièrement
      while (!reader.atEnd())
      {
        //Au début d'un élément
          if (reader.isStartElement())
          {
                 //Si l'élément lu est "configuration"
                  if (reader.name() == "configuration")
                  {
                      //Lecture du prochain jeton
                      reader.readNext();
                      // Tant que celui-ci n'est pas un élément de départ on avance au jeton suivant
                      //while(reader.isStartElement()==false)
                          //reader.readNext();
                  }
                  if (reader.name()=="site")
                  {
                      k++;
                      nomSite= reader.attributes().value("nom").toString();//Lecture du nom du site
                      vector_nomSite.append(nomSite);//Stockage du nom dans le vector

                     if(reader.name() == "collecteur")
                     {

                        nomCollecteur = reader.attributes().value("nom").toString();//Lecture du nom du collecteur
                        vector_nomCollecteur.append(nomCollecteur);//Stockage du nom dans le vector

                        ipCollecteur = reader.attributes().value("ip").toString();//Lecture de l'ip du collecteur
                        vector_ipCollecteur.append(ipCollecteur);

                     }
                  }
          }
          reader.readNext(); // On va au prochain token
        }

      fichier->close();
      }

    // QString::number(k);
     vector_ipCollecteur.append(ip);
     vector_nomCollecteur.append(nom);

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

     //writer.writeAttribute("site",);


     //for (initialisation; test de continuation; boucle)
    for( int i=0; i < vector_nomCollecteur.size(); i++ )// size() Taille du tableau
     {

         writer.writeStartElement("collecteur");//<collecteur>

         writer.writeAttribute("nom",vector_nomCollecteur[i]);//Ajoute un nouvel attribut à l'élément collecteur
         writer.writeAttribute("ip",vector_ipCollecteur[i]);//Ajoute un autre attribut à l'élément collecteur

         writer.writeEndElement();//</collecteur>
 /*
         <Configuration>
         <site nom="Lycée">
             <collecteur nom="local" ip="127.0.0.1"/>
         </site>
         </Configuration>
 */
     }

     vector_nomCollecteur.clear();
     vector_ipCollecteur.clear();

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

void Configurateur::Edit()
{


}

