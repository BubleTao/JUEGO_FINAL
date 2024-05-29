
#include "disparo.h"

Disparo::Disparo(float scale, float speed, float direction)
    : speed(speed), direction(direction)
{
    pixmap_management = new sprites(":/imagenes/disparo.png", scale);
    pixmap_management->set_design_size(bala_pixel_x_size, bala_pixel_y_size);
    pixmap_management->cut_character_pixmap(set_complete_sprites());

    QPixmap pixmap = pixmap_management->get_fixed_image(set_complete_sprites());
    setPixmap(pixmap);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);

    //qDebug() << "Disparo creado";
}

Disparo::~Disparo()
{
    delete pixmap_management;
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

void Disparo::move()
{
    setPos(x(), y() + direction * speed);

    // Collisions
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (QGraphicsItem *item : colliding_items) {
        if (typeid(*item) == typeid(enemigo)) {
            scene()->removeItem(item);
            scene()->removeItem(this);
            //animacion_muerte = new muerte(0.5);
            //scene()->addItem(animacion_muerte);
            delete item;
            delete this;
            return;
        }
    }

    // Quitar la bala
    if (pos().y() + pixmap().height() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
