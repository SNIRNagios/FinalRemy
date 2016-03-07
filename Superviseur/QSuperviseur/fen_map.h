#ifndef FEN_MAP_H
#define FEN_MAP_H

#include <QDialog>
#include <QWidget>
#include <QLabel>
#include <QString>
#include <QMap>
#include <QFile>
#include <QMessageBox>
#include <QTimer>
#include <QHBoxLayout>
#include <QtXml>
#include <QPushButton>
#include "collecteur.h"

namespace Ui {
class fen_map;
}

class fen_map : public QDialog
{
    Q_OBJECT

public:
    explicit fen_map(QWidget *parent = 0);
    int LectureFichierConfiguration();
    int Lister(QDomElement root, QString tagname, QString attribute);
    ~fen_map();

private:
    Ui::fen_map *ui;
    QFile fichierConfiguration;
    QStringList listeAdresse;
    QStringList listeNom;
    QString chemin;
    QString demande;
    //QWidget *rectangle;
    //QPushButton *rectangleButton;
    QHBoxLayout *couche;
    QList<QPushButton*> rectangle;
};

#endif // FEN_MAP_H
