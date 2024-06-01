#ifndef FINALBOSS_H
#define FINALBOSS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "sprites.h"

#define boss_pixel_x_size 900
#define boss_pixel_y_size 520

class finalboss : public QObject, public QGraphicsPixmapItem
{
public:
    finalboss(float scale);
    ~finalboss();

private:
    sprites *pixmap;
    QRect set_complete_sprites();
    QRect objeto();
};

#endif // FINALBOSS_H
