#include "disparo.h"
#include <QTimer>


Disparo::Disparo()
{
    setRect(0,0,10,50);
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Disparo::move()
{
    setPos(x(),y()-10);
}
