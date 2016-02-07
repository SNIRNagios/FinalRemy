#ifndef TIMER_H
#define TIMER_H

#include <QObject>

class timer : public QObject
{
    Q_OBJECT
public:
    explicit timer(QObject *parent = 0);

signals:

public slots:
    void interrogationSites();
};

#endif // TIMER_H
