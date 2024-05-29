#ifndef MUERTE_H
#define MUERTE_H
#include <QGraphicsPixmapItem>
#include <QObject>

#include "enemigos.h"
#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include <QDebug>

#include "sprites.h"
#define muerte_pixel_x_size 96
#define muerte_pixel_y_size 78
class muerte : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    muerte(float scale);
    ~muerte();

private:
    QRect set_complete_sprites();
    void set_animations();
    sprites *pixmap_management;

};

#endif // MUERTE_H
