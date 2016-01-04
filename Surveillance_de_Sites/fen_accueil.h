#ifndef FEN_ACCUEIL_H
#define FEN_ACCUEIL_H

#include <QMainWindow>

namespace Ui {
class FEN_Accueil;
}

class FEN_Accueil : public QMainWindow
{
    Q_OBJECT

public:
    explicit FEN_Accueil(QWidget *parent = 0);
    ~FEN_Accueil();

private:
    Ui::FEN_Accueil *ui;
};

#endif // FEN_ACCUEIL_H
