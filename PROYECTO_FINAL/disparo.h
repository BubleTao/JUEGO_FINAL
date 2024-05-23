#ifndef DISPARO_H
#define DISPARO_H
#include <QGraphicsRectItem>
#include <QObject>

class Disparo : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Disparo();
public slots:
    void move();
};

#endif // DISPARO_H
