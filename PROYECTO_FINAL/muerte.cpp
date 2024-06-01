#include "muerte.h"

muerte::muerte(float scale) : current_frame(0)
{
    pixmap_management = new sprites(":/imagenes/muerte_enemigos.png", scale);
    pixmap_management->set_design_size(muerte_pixel_x_size, muerte_pixel_y_size);
    pixmap_management->cut_character_pixmap(set_complete_sprites());

    QPixmap pixmap = pixmap_management->get_fixed_image(set_complete_sprites());
    setPixmap(pixmap);

    animation_timer = new QTimer(this);
    connect(animation_timer, &QTimer::timeout, this, &muerte::update_animation_frame);
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
    dim.setHeight(muerte_pixel_y_size);
    dim.setWidth(muerte_pixel_x_size);
    return dim;
}

void muerte::start_animation()
{
    int frame_duration = animation_duration / total_frames;
    animation_timer->start(frame_duration);
}

void muerte::update_animation_frame()
{
    QRect frame_rect(current_frame * muerte_pixel_x_size, 2 * muerte_pixel_y_size, muerte_pixel_x_size, muerte_pixel_y_size);
    QPixmap frame_pixmap = pixmap_management->get_fixed_image(frame_rect);
    setPixmap(frame_pixmap);

    current_frame++;
    if (current_frame >= total_frames) {
        animation_timer->stop();
        emit animation_finished();
    }
}

void muerte::set_animations()
{
    // por si da tiempo para meter mas animaciones jeje
}

