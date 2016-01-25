#include "fen_superviseur.h"
#include "ui_fen_superviseur.h"

fen_superviseur::fen_superviseur(QWidget *parent) : QDialog(parent), ui(new Ui::fen_superviseur)
{
    ui->setupUi(this);
    statusLabel = new QLabel(this);
    ui->W_Rectangle->setStyleSheet("background-color:green");
    ui->W_RectangleFailure->setStyleSheet("background-color:red");

    site = new Collecteur(this);
    connect(site, SIGNAL(vers_IHM_texte(QString)),this,SLOT(obtenirSocket(QString)));

    //rectangle = new QWidget(this);
    //rectangle->setGeometry(100,20,200,100);
    //rectangle->setStyleSheet("background-color:green");
    //rectangle->show();
}

fen_superviseur::~fen_superviseur()
{
    delete ui;
    delete statusLabel;
}

void fen_superviseur::on_BTN_getHosts_clicked()
{
    site->connexionCollecteur("172.17.50.202");
    site->obtenirHotes("GET hosts\nColumns: host_name state\n");
    ui->textEdit->append(contenu);
}

QString fen_superviseur::obtenirSocket(QString socketLivestatus)
{
    contenu = socketLivestatus;
    return contenu;
}
