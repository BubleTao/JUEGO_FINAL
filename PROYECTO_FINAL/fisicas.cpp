#include "fisicas.h"

fisicas::fisicas(int x, int y, int h, QGraphicsPixmapItem *item)
{
    this->item = item;
    this->x = x;
    this->y = h-y;
    this->h = h;
    vy = system_scale*-1;
    vx = 1;
    vx0 = vx;
    vy0 = vy;
    x0=x;
    y0 = y;
    g = system_scale*9.8;
    n=0;


    p_time = new QTimer;
    default_movement = new QTimer;
    connect(p_time,SIGNAL(timeout()),this,SLOT(parabolic_shoot()));
    connect(default_movement,SIGNAL(timeout()),this,SLOT(MRU()));
    default_movement->start(time_step);
}

fisicas::~fisicas()
{
    delete p_time;
}

void fisicas::start_parabolic_movement()
{

    default_movement->stop();
    set_starting_parameters(x,y,800,0);
    p_time->start(time_step);
}

void fisicas::set_vx()
{
    vx+=system_scale*2;
}

void fisicas::set_pos_item()
{
    item->setX(x);
    item->setY(h-y);
}

void fisicas::parabolic_shoot()
{
    float t = ((time_step/1000.0)*n);
    vx = vx0;
    vy = vy0-g*t;
    x = x0+vx0*t;
    y = y0+vy0*t-(g*t*t)/2;
    n++;
    set_pos_item();
    if(y-90 <=0) {
        set_starting_parameters(x,y,vx,100);
        p_time->stop();
        default_movement->start(time_step);
    }
}

void fisicas::MRU()
{
    float t = ((time_step/1000.0)*n);
    x = x0+vx0*t;
    y = y0+vy0*t;
    n++;
    set_pos_item();
}

void fisicas::set_starting_parameters(int x, int y, int vx, int vy)
{
    x0 = x;
    y0 = y;
    vx0 = vx;
    vy0 = vy;
    n=0;
}
