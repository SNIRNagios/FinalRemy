#include "fen_accueil.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Création de la fenêtre d'acceuil
    FEN_Accueil fenAccueil;//Création de l'instance FEN_Acceuil
    fenAccueil.setFixedSize(403, 187);//Exiger une taille fixe de 403px en largeur et 187px en hauteur
    fenAccueil.show();//Affichage de la fenêtre d'accueil

    return a.exec();
}
