#include "sprites.h"

sprites::sprites(QObject *parent)
{
    timer = new QTimer();
    filas = 0;
    columnas=0;
    pixmap = new QPixmap(":/personaje.png");
    connect(timer,&QTimer::timeout, this, &sprites::actualizacion);
    timer -> star(250)
}

void sprites::actualizacion()
{
    columnas += 35;
    if (columnas >= 280){
        columnas=0;

    }
    this -> update(-ancho/2,-alto/2, ancho, alto);
}
QRectF sprites::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2, ancho, alto);
}

void sprites::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter -> drawPixmap(-ancho/2,-alto/2, *pixmap, columnas,0,ancho, alto);
}


