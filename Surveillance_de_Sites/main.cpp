#include "fen_accueil.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FEN_Accueil w;
    w.show();

    return a.exec();
}
