#ifndef MUERTE_H
#define MUERTE_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

#include "enemigos.h"
#include "sprites.h"

#define muerte_pixel_x_size 92
#define muerte_pixel_y_size 92

class muerte : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    muerte(float scale);
    ~muerte();
    void start_animation();

signals:
    void animation_finished(); // Añadir esta señal

private:
    QRect set_complete_sprites();
    void set_animations();

private slots:
    void update_animation_frame();

private:
    sprites *pixmap_management;
    QTimer *animation_timer;
    int current_frame;
    const int total_frames = 6;
    const int animation_duration = 1000; // Duración de la animación en milisegundos
};

#endif // MUERTE_H

