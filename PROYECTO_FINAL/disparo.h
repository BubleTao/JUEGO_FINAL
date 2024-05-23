#ifndef DISPARO_H
#define DISPARO_H
#include <QGraphicsPixmapItem>
#include <QObject>

#include "sprites.h"
#define bala_pixel_x_size 433
#define bala_pixel_y_size 433
class Disparo : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Disparo(float scale);
    ~Disparo();

private:
    QRect set_complete_sprites();
    void set_animations();

    sprites *pixmap_management;

public slots:
    void move();
};

#endif // DISPARO_H

