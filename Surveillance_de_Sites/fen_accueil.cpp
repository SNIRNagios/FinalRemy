#include "fen_accueil.h"
#include "ui_fen_accueil.h"

FEN_Accueil::FEN_Accueil(QWidget *parent) : QMainWindow(parent), ui(new Ui::FEN_Accueil)
{
    ui->setupUi(this);
}

FEN_Accueil::~FEN_Accueil()
{
    delete ui;
}
