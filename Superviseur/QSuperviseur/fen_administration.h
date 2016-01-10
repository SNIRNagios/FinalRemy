#ifndef FEN_ADMINISTRATION_H
#define FEN_ADMINISTRATION_H

#include <QDialog>

namespace Ui {
class fen_administration;
}

class fen_administration : public QDialog
{
    Q_OBJECT

public:
    explicit fen_administration(QWidget *parent = 0);
    ~fen_administration();

private:
    Ui::fen_administration *ui;
};

#endif // FEN_ADMINISTRATION_H
