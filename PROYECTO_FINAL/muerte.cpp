#include "muerte.h"
#include "enemigos.h"

muerte::muerte(float scale)
{
    pixmap_management = new sprites(":/imagenes/muerte_enemigos.png", scale);
    pixmap_management->cut_character_pixmap(set_complete_sprites());
    pixmap_management->set_design_size(enemigo_pixel_x_size, enemigo_pixel_y_size);
    set_animations();
    setPixmap(pixmap_management->get_current_pixmap(0));
}

muerte::~muerte()
{
    delete pixmap_management;
}

QRect muerte::set_complete_sprites()
{
    QRect dim;
    dim.setX(0);
    dim.setY(0);
    dim.setHeight(6 * muerte_pixel_y_size);
    dim.setWidth(9 * muerte_pixel_x_size);
    return dim;
}
void muerte::set_animations()
{
    muerte1();
    muerte2();
    muerte3();
    muerte4();
    muerte5();
    muerte6();
}

void muerte::muerte1()
{
   QRect dim;
   dim.setX(0);
   dim.setY(0);
   dim.setHeight(1 * muerte_pixel_y_size);
   dim.setWidth(4 * muerte_pixel_x_size);
   pixmap_management->add_new_animation(dim,4);
}

void muerte::muerte2()
{
   QRect dim;
   dim.setX(0);
   dim.setY(1*muerte_pixel_y_size);
   dim.setHeight(1 * muerte_pixel_y_size);
   dim.setWidth(4 * muerte_pixel_x_size);
   pixmap_management->add_new_animation(dim,4);
}

void muerte::muerte3()
{
   QRect dim;
   dim.setX(0);
   dim.setY(2*muerte_pixel_y_size);
   dim.setHeight(1 * muerte_pixel_y_size);
   dim.setWidth(4 * muerte_pixel_x_size);
   pixmap_management->add_new_animation(dim,4);
}

void muerte::muerte4()
{
   QRect dim;
   dim.setX(0);
   dim.setY(3*muerte_pixel_y_size);
   dim.setHeight(1 * muerte_pixel_y_size);
   dim.setWidth(4 * muerte_pixel_x_size);
   pixmap_management->add_new_animation(dim,4);
}
void muerte::muerte5()
{
   QRect dim;
   dim.setX(0);
   dim.setY(4*muerte_pixel_y_size);
   dim.setHeight(1 * muerte_pixel_y_size);
   dim.setWidth(4 * muerte_pixel_x_size);
   pixmap_management->add_new_animation(dim,4);
}
void muerte::muerte6()
{
   QRect dim;
   dim.setX(0);
   dim.setY(5*muerte_pixel_y_size);
   dim.setHeight(1 * muerte_pixel_y_size);
   dim.setWidth(4 * muerte_pixel_x_size);
   pixmap_management->add_new_animation(dim,4);
}
