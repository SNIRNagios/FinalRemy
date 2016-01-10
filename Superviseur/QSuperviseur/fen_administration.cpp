#include "fen_administration.h"
#include "ui_fen_administration.h"

fen_administration::fen_administration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fen_administration)
{
    ui->setupUi(this);
}

fen_administration::~fen_administration()
{
    delete ui;
}
