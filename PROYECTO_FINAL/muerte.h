#ifndef MUERTE_H
#define MUERTE_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include "sprites.h"

#define muerte_pixel_x_size 96
#define muerte_pixel_y_size 77
#define muerte_speed 5


class muerte : public QGraphicsPixmapItem
{
public:
    muerte(float scale);
    ~muerte();

private:
    QRect set_complete_sprites();
    void set_animations();
    void muerte1();
    void muerte2();
    void muerte3();
    void muerte4();
    void muerte5();
    void muerte6();

    sprites *pixmap_management;
};
#endif // MUERTE_H
