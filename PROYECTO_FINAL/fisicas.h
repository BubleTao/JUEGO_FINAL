
#ifndef FISICAS_H
#define FISICAS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

#define time_step 10
#define system_scale 50

class fisicas : public QObject
{
    Q_OBJECT
public:
    fisicas(int x, int y, int h, QGraphicsPixmapItem *item);
    ~fisicas();
    int get_x();
    int get_y();
    void start_parabolic_movement();
    void set_vx();
private:
    void set_pos_item();
    QGraphicsPixmapItem *item;
    QTimer *p_time, *default_movement;
    float x, y, vx, vy, ax, ay, g, x0, y0, vx0, vy0, n;
    int h;

private slots:
    void parabolic_shoot();
    void MRU();
    void set_starting_parameters(int x, int y, int vx, int vy);

};

#endif // FISICAS_H
