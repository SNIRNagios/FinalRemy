#include "fen_accueil.h"
#include "fen_superviseur.h"
#include "ui_fen_accueil.h"
#include "fen_map.h"

FEN_Accueil::FEN_Accueil(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FEN_Accueil)
{
    ui->setupUi(this);

    //MODIFICATION DE LA BARRE DE STATUS
    //Allocation dynamique du label
    statusLabel = new QLabel(this);

    //Création permanante de widgets dans la barre de status de MainWindow
    ui->SB_Informations->addPermanentWidget(statusLabel);

}

FEN_Accueil::~FEN_Accueil()
{
    delete ui;
}

void FEN_Accueil::on_BTN_Connexion_clicked()
{
    QString utilisateur = ui->LE_Utilisateur->text();
    QString motDePasse = ui->LE_MotDePasse->text();

    if (utilisateur == "Admin" && motDePasse == "Admin")
    {
        ui->SB_Informations->showMessage("La connexion a été réussie");

        this->hide();
        fen_administration fenetreAdministration;
        fenetreAdministration.setModal(true);
        fenetreAdministration.setFixedSize(500,400);
        fenetreAdministration.exec();
    }
    else
    {
        ui->SB_Informations->showMessage("Identifiants incorrectes");
    }
}

void FEN_Accueil::on_BTN_AccesSuperviseur_clicked()
{
    /*this->hide();
    fen_superviseur fenetreSuperviseur;
    fenetreSuperviseur.setModal(true);
    fenetreSuperviseur.setFixedSize(872,738);
    fenetreSuperviseur.exec();*/

    this->hide();
    fen_map supervision;
    supervision.setModal(true);
    //supervision.setFixedSize(400,250);
    supervision.exec();
}
