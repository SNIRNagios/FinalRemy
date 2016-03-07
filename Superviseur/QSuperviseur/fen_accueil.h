#ifndef FEN_ACCUEIL_H
#define FEN_ACCUEIL_H

#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
#include <QTimer>
#include "fen_administration.h"


namespace Ui {
class FEN_Accueil;
}

class FEN_Accueil : public QMainWindow
{
    Q_OBJECT

public:
    explicit FEN_Accueil(QWidget *parent = 0);
    ~FEN_Accueil();

private slots:
    void on_BTN_Connexion_clicked();

    void on_BTN_AccesSuperviseur_clicked();

private:
    Ui::FEN_Accueil *ui;
    QLabel *statusLabel;
};

#endif // FEN_ACCUEIL_H
