#ifndef FEN_SUPERVISEUR_H
#define FEN_SUPERVISEUR_H

#include <QDialog>
#include <QWidget>

namespace Ui {
class fen_superviseur;
}

class fen_superviseur : public QDialog
{
    Q_OBJECT

public:
    explicit fen_superviseur(QWidget *parent = 0);
    ~fen_superviseur();

private:
    Ui::fen_superviseur *ui;
    QWidget *rectangle;
};

#endif // FEN_SUPERVISEUR_H
