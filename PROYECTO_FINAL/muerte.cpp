#include "muerte.h"

muerte::muerte(float scale)
{
    pixmap_management = new sprites(":/imagenes/muerte_enemigos.png", scale);
    pixmap_management->set_design_size(muerte_pixel_x_size, muerte_pixel_y_size);
    pixmap_management->cut_character_pixmap(set_complete_sprites());

    QPixmap pixmap = pixmap_management->get_fixed_image(set_complete_sprites());
    setPixmap(pixmap);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(~muerte()));

    timer->start(50);

    //qDebug() << "Disparo creado";
}

muerte::~muerte()
{
    delete pixmap_management;
}

QRect muerte::set_complete_sprites()
{
    QRect dim;
    dim.setX(0);
    dim.setY(2*muerte_pixel_y_size);
    dim.setHeight(muerte_pixel_y_size);
    dim.setWidth(6*muerte_pixel_x_size);
    return dim;
}

