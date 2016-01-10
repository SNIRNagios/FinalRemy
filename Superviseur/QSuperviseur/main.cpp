#include "fen_accueil.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    FEN_Accueil accueil;
    accueil.setFixedSize(759,221);
    accueil.show();

    return a.exec();
}
