#ifndef DISPARO_H
#define DISPARO_H
#include <QGraphicsPixmapItem>
#include <QObject>

#include "enemigos.h"
#include "muerte.h"
#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include <QDebug>

#include "sprites.h"
#define bala_pixel_x_size 433
#define bala_pixel_y_size 433
class Disparo : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Disparo(float scale, float speed = 10.0, float direction = -1.0);
    ~Disparo();

private:
    muerte *animacion_muerte;
    QRect set_complete_sprites();
    void set_animations();
    float speed;
    float direction;
    sprites *pixmap_management;

public slots:
    void move();
};

#endif // DISPARO_H

