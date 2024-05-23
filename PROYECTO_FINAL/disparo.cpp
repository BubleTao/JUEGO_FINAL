#include "disparo.h"
#include <QTimer>


Disparo::Disparo(float scale)
{

    pixmap_management = new sprites(":/imagenes/disparo.png", scale); // Cargamos la imagen del enemigo - Falta configurarlo.
    pixmap_management->cut_character_pixmap(set_complete_sprites());
    setPixmap(pixmap_management->get_fixed_image(set_complete_sprites()));

    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

Disparo::~Disparo()
{
    delete pixmap_management;
}

QRect Disparo::set_complete_sprites()
{
    QRect dim;
    dim.setX(0);
    dim.setY(0);
    dim.setHeight(430);
    dim.setWidth(430);
    return dim;
}



void Disparo::move()
{
    setPos(x(),y()-10);
}


