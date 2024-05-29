#include "personaje.h"

personaje::personaje(unsigned int scale)
{
    pixmap_management = new sprites("::/personaje.png",scale);
    pixmap_management->cut_character_pixmap(set_complete_sprites());
    pixmap_management->set_design_size(blas_pixel_x_size,
                                       blas_pixel_y_size);
    set_animations();
    setX(0);
    setY(0);
    setPixmap(pixmap_management->get_current_pixmap(3));
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
        setPixmap(pixmap_management->get_current_pixmap(1));
        if(is_valid) setX(x()+blas_speed);
    }
    else if(key == keys[2]){
        setPixmap(pixmap_management->get_current_pixmap(2));
        if(is_valid) setY(y()-blas_speed);
    }
    else if(key == keys[3]){
        setPixmap(pixmap_management->get_current_pixmap(3));
        if(is_valid) setY(y()+blas_speed);
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
    dim.setHeight(3*blas_pixel_y_size);
    dim.setWidth(7*blas_pixel_x_size);

    return dim;
}

void personaje::set_animations()
{
    set_left_animation();
    set_right_animation();
    set_up_animation();
    set_down_animation();
    set_death_animation();
}

void personaje::set_left_animation()
{
    QRect dim;

    dim.setX(0);
    dim.setY(0);
    dim.setHeight(1*blas_pixel_y_size);
    dim.setWidth(3*blas_pixel_x_size);

    pixmap_management->add_new_animation(dim,3);
}

void personaje::set_right_animation()
{
    QRect dim;

    dim.setX(0);
    dim.setY(1*blas_pixel_y_size);
    dim.setHeight(1*blas_pixel_y_size);
    dim.setWidth(3*blas_pixel_x_size);

    pixmap_management->add_new_animation(dim,3);
}

void personaje::set_up_animation()
{
    QRect dim;

    dim.setX(3*blas_pixel_x_size);
    dim.setY(1*blas_pixel_y_size);
    dim.setHeight(1*blas_pixel_y_size);
    dim.setWidth(3*blas_pixel_x_size);

    pixmap_management->add_new_animation(dim,3);
}

void personaje::set_down_animation()
{
    QRect dim;

    dim.setX(3*blas_pixel_x_size);
    dim.setY(0);
    dim.setHeight(1*blas_pixel_y_size);
    dim.setWidth(3*blas_pixel_x_size);

    pixmap_management->add_new_animation(dim,3);
}

void personaje::set_death_animation()
{
    QRect dim;

    dim.setX(0);
    dim.setY(2*blas_pixel_y_size);
    dim.setHeight(1*blas_pixel_y_size);
    dim.setWidth(7*blas_pixel_x_size);

    pixmap_management->add_new_animation(dim,7);
}
