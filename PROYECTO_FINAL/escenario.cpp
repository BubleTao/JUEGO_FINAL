#include "escenario.h"

escenario::escenario(float scale)
{

    pixmap = new sprites(":/imagenes/muralla.png",scale);
    pixmap->cut_character_pixmap(set_complete_sprites());
    pixmap->set_design_size(blocks_pixel_x_size,
                            blocks_pixel_y_size);
    setPixmap(pixmap->get_fixed_image(set_complete_sprites()));

}

escenario::~escenario()
{
    delete pixmap;
}



QRect escenario::set_complete_sprites()
{
    QRect dim;

    dim.setX(0);
    dim.setY(0);
    dim.setHeight(blocks_pixel_y_size);
    dim.setWidth(blocks_pixel_x_size);

    return dim;
}

QRect escenario::set_non_destructible_block()
{
    QRect dim;

    dim.setX(0);
    dim.setY(0);
    dim.setHeight(blocks_pixel_y_size);
    dim.setWidth(blocks_pixel_x_size);

    return dim;
}


