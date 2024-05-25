#include "sprites.h"

sprites::sprites(QString main_pixmap_path, float scale)
{
    this->main_pixmap = new QPixmap(main_pixmap_path);
    this->character_pixmap = new QPixmap;
    this->scale = scale;
    this->animation_counter = 0;
}

void sprites::set_design_size(unsigned int x, unsigned int y)
{
    height = y;
    width = x;
}

void sprites::cut_character_pixmap(QRect size)
{
    *character_pixmap = main_pixmap->copy(size);
}

void sprites::add_new_animation(QRect size, unsigned int number)
{
    animations.push_back(size);
    animations_size.push_back(number);
}

QPixmap sprites::get_current_pixmap(unsigned int animation)
{
    animation_counter++;
    if (animation_counter >= animations_size[animation]) animation_counter = 0;

    return character_pixmap->copy(animations[animation]).copy(animation_counter * width, 0, width, height).scaled(width * scale, height * scale);
}

QPixmap sprites::get_fixed_image(QRect size)
{
    QPixmap pixmap = character_pixmap->copy(size).scaled(width * scale, height * scale);
    //qDebug() << "Scaled image size:" << pixmap.size();
    return pixmap;
}


