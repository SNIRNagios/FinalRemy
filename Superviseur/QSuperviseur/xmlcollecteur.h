#ifndef XMLCOLLECTEUR_H
#define XMLCOLLECTEUR_H

#include <QObject>
#include <QHostAddress>

class xmlCollecteur : public QObject
{
    Q_OBJECT
public:
    explicit xmlCollecteur(QObject *parent = 0);
    void ajouterCollecteur(QString nom, QString ip);

signals:

public slots:
private:
    QString nom;
    QString ip;
};

#endif // XMLCOLLECTEUR_H
