#include "fen_superviseur.h"
#include "ui_fen_superviseur.h"

fen_superviseur::fen_superviseur(QWidget *parent) : QDialog(parent), ui(new Ui::fen_superviseur)
{
    ui->setupUi(this);



    //PARTIE IHM
    statusLabel = new QLabel(this);


    //PARTIE RECTANGLE
    ui->W_Rectangle->setStyleSheet("background-color:green");
    ui->W_RectangleFailure->setStyleSheet("background-color:red");

    site = new Collecteur(this);

    //rectangle = new QWidget(this);
    //rectangle->setGeometry(100,20,200,100);
    //rectangle->setStyleSheet("background-color:green");
    //rectangle->show();
}

fen_superviseur::~fen_superviseur()
{
    //delete rectangle;
    delete ui;
    delete statusLabel;
}







void fen_superviseur::on_pushButton_clicked()
{
    site->connexionCollecteur("172.17.50.202");
    site->obtenirHotes("GET hosts\nColumns: host_name state");

    site->deconnexionCollecteur();
}
