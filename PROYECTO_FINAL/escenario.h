#ifndef ESCENARIO_H
#define ESCENARIO_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "sprites.h"

#define blocks_pixel_x_size 512
#define blocks_pixel_y_size 153

class escenario : public QObject, public QGraphicsPixmapItem
{
public:
    escenario(float scale);
    ~escenario();

private:
    sprites *pixmap;
    QRect set_complete_sprites();
    QRect set_non_destructible_block();
};

#endif // ESCENARIO_H
