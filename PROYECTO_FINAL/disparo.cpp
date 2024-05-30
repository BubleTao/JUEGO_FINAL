
#include "disparo.h"

Disparo::Disparo(QVector<enemigo *> enemy, float scale, float speed, float direction)
    : speed(speed), direction(direction)
{
    pixmap_management = new sprites(":/imagenes/disparo.png", scale);
    pixmap_management->set_design_size(bala_pixel_x_size, bala_pixel_y_size);
    pixmap_management->cut_character_pixmap(set_complete_sprites());

    QPixmap pixmap = pixmap_management->get_fixed_image(set_complete_sprites());
    setPixmap(pixmap);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
    this->enemy = enemy;
    //qDebug() << "Disparo creado";
}

Disparo::~Disparo()
{
    delete pixmap_management;
    delete timer;
}

QRect Disparo::set_complete_sprites()
{
    QRect dim;
    dim.setX(0);
    dim.setY(0);
    dim.setHeight(bala_pixel_y_size);
    dim.setWidth(bala_pixel_x_size);
    return dim;
}

bool Disparo::test_collition()
{
    bool is_deleted = false;
    for(int i=0; i< enemy.length(); i++){
        if(enemy.at(i)->collidesWithItem(this)){
            timer->stop();
            emit is_enemy_reached(this,i);
            is_deleted = true;
            break;
        }
    }

    return is_deleted;
}

bool Disparo::test_range()
{
    bool is_deleted = false;
    if(y()<0){
        emit is_shoot_out_of_range(this);
        is_deleted = true;
    }

    return is_deleted;
}

void Disparo::move()
{
    setPos(x(), y() + direction * speed);
    if(test_collition() || test_range()) delete this;
}
