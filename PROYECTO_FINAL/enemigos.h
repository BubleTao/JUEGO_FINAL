#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "sprites.h"
#include "fisicas.h"

#define enemigo_pixel_x_size 208
#define enemigo_pixel_y_size 192
#define enemigo_speed 5


class enemigo : public fisicas, public QGraphicsPixmapItem
{
public:
    enemigo(int x, int y, int h,float scale,QString ruta);
    ~enemigo();
    void muerte();

private:
    QRect set_complete_sprites();
    void set_animations();

    sprites *pixmap_management;
};

#endif // ENEMIGO_H
