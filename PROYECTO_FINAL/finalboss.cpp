#include "finalboss.h"

finalboss::finalboss(float scale)
{

    pixmap = new sprites(":/imagenes/finalboss.png",scale);
    pixmap->cut_character_pixmap(set_complete_sprites());
    pixmap->set_design_size(boss_pixel_x_size,
                            boss_pixel_y_size);
    setPixmap(pixmap->get_fixed_image(set_complete_sprites()));

}

finalboss::~finalboss()
{
    delete pixmap;
}



QRect finalboss::set_complete_sprites()
{
    QRect dim;

    dim.setX(0);
    dim.setY(0);
    dim.setHeight(boss_pixel_y_size);
    dim.setWidth(boss_pixel_x_size);

    return dim;
}

QRect finalboss::objeto()
{
    QRect dim;

    dim.setX(0);
    dim.setY(0);
    dim.setHeight(boss_pixel_y_size);
    dim.setWidth(boss_pixel_x_size);

    return dim;
}

