#include "enemigos.h"

enemigo::enemigo(int x, int y, int h,float scale) : fisicas(x,y,h,this)
{
    pixmap_management = new sprites(":/imagenes/enemigo2.png", scale); // Cargamos la imagen del enemigo - Falta configurarlo.
    pixmap_management->cut_character_pixmap(set_complete_sprites());
    pixmap_management->set_design_size(enemigo_pixel_x_size, enemigo_pixel_y_size);
    set_animations();
    setPixmap(pixmap_management->get_current_pixmap(0));
    setPos(x,y);
}

enemigo::~enemigo()
{
    delete pixmap_management;
}

QRect enemigo::set_complete_sprites()
{
    QRect dim;
    dim.setX(0);
    dim.setY(0);
    dim.setHeight(1 * enemigo_pixel_y_size);
    dim.setWidth(4 * enemigo_pixel_x_size);
    return dim;
}

void enemigo::set_animations()
{
    QRect dim;
    dim.setX(0);
    dim.setY(0);
    dim.setHeight(1 * enemigo_pixel_y_size);
    dim.setWidth(4 * enemigo_pixel_x_size);
    pixmap_management->add_new_animation(dim,4);
}
