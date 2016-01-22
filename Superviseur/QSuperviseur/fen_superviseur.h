#ifndef FEN_SUPERVISEUR_H
#define FEN_SUPERVISEUR_H
#include <QDialog>
#include <QWidget>
#include <QLabel>
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
    void on_pushButton_clicked();

private:
    Ui::fen_superviseur *ui;
    QWidget *rectangle;
    QLabel *statusLabel;
    Collecteur *site;
};

#endif // FEN_SUPERVISEUR_H
