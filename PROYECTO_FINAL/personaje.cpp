#include "personaje.h"
#include <QObject>
#include <QGraphicsScene>

personaje::personaje(unsigned int scale)
{
    pixmap_management = new sprites(":/imagenes/personaje.png",scale);
    pixmap_management->cut_character_pixmap(set_complete_sprites());
    pixmap_management->set_design_size(blas_pixel_x_size,
                                       blas_pixel_y_size);
    //setPixmap();
    set_animations();
    setX(1*blas_pixel_y_size*scale);
    setY(1*blas_pixel_x_size*scale);
    setPixmap(pixmap_management->get_current_pixmap(0));
}

void personaje::set_keys(unsigned int *keys)
{
    for(unsigned int i=0;i<4;i++) this->keys[i] = keys[i];
}

void personaje::move(unsigned int key, bool is_valid)
{
    if(key == keys[0]){
        setPixmap(pixmap_management->get_current_pixmap(0));
        if(is_valid) setX(x()-blas_speed);
    }
    else if(key == keys[1]){
        setPixmap(pixmap_management->get_current_pixmap(0));
        if(is_valid) setX(x()+blas_speed);
    }
    else if(key == keys[2]){
        setPixmap(pixmap_management->get_current_pixmap(0));
        if(is_valid);
    }
}

personaje::~personaje()
{
    delete pixmap_management;
}

QRect personaje::set_complete_sprites()
{
    QRect dim;

    dim.setX(0);
    dim.setY(0);
    dim.setHeight(1*blas_pixel_y_size);
    dim.setWidth(4*blas_pixel_x_size);

    return dim;
}

void personaje::set_animations()
{
    set_down_animation();
}


void personaje::set_down_animation()
{
    QRect dim;

    dim.setX(2*blas_pixel_x_size);
    dim.setY(0);
    dim.setHeight(1*blas_pixel_y_size);
    dim.setWidth(4*blas_pixel_x_size);

    pixmap_management->add_new_animation(dim,2);
}


