#ifndef FEN_SUPERVISEUR_H
#define FEN_SUPERVISEUR_H
#include <QDialog>
#include <QWidget>
#include <QLabel>
#include <QString>
#include "collecteur.h"

namespace Ui
{
    class fen_superviseur;
}
class fen_superviseur : public QDialog
{
    Q_OBJECT
public:
    explicit fen_superviseur(QWidget *parent = 0);

    ~fen_superviseur();
private slots:
    void on_BTN_getHosts_clicked();
    QString obtenirSocket(QString);

private:
    Ui::fen_superviseur *ui;
    QWidget *rectangle;
    QLabel *statusLabel;
    Collecteur *site;
    QString contenu;
};

#endif // FEN_SUPERVISEUR_H
