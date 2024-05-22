#include "reglas_juego.h"
#include <chrono>

reglas_juego::reglas_juego(QGraphicsView *graph, QVector<QLabel *> game_labels)
{
    srand(time(NULL));
    this->graph = graph;
    labels = game_labels;
    setup_scene();
    setup_blas();
    generate_map();
    setup_enemigo();


}

reglas_juego::~reglas_juego()
{
    delete scene;
}


void reglas_juego::key_event(QKeyEvent *event)
{
    bool is_valid = true;

    if(unsigned(event->key()) == blas_keys[0]);
    else if(unsigned(event->key()) == blas_keys[1]);
    else if(unsigned(event->key()) == blas_keys[2]) is_valid = down_movement_is_valid(blas);
    if(blas->x()<700 && blas->x()>230);
    blas->move(event->key(),is_valid);

}
void reglas_juego::set_blas_keys()
{
    blas_keys[0] = Qt::Key_A;
    blas_keys[1] = Qt::Key_D;
    blas_keys[2] = Qt::Key_S;
}

void reglas_juego::generate_map()
{
    int start_row = game_map_rows - 1;
    for(unsigned int col = 0; col < game_map_col; col++) {
        blocks[start_row][col] = new escenario(2, 1);

        blocks[start_row][col]->setX(2 * blocks_pixel_x_size * col);
        blocks[start_row][col]->setY(2 * blocks_pixel_y_size * start_row);
        scene->addItem(blocks[start_row][col]);
    }
}


void reglas_juego::setup_scene()
{
    int new_width = 370;
    int new_height = 600;
    graph->setGeometry(0, 0, new_width, new_height);
    scene = new QGraphicsScene;
    scene->setSceneRect(0, 0, new_width - 2, new_height - 2);
    graph->setScene(scene);
    QPixmap background(":/imagenes/nivel1.png");
    scene->setBackgroundBrush(background);
}

void reglas_juego::setup_blas()
{
    set_blas_keys();

    blas = new personaje(game_scale_factor);
    blas->set_keys(blas_keys);
    blas->setPos(150,430);
    scene->addItem(blas);
}

bool reglas_juego::bernoulli_event()
{
    return (rand()/float(RAND_MAX)) < difficult;
}

bool reglas_juego::left_movement_is_valid(QGraphicsPixmapItem *item)
{
    int xf1,yf1,xf2,yf2;
    bool is_valid1, is_valid2;

    xf1 = item->x()-blas_speed;
    yf1 = item->y();
    xf2 = item->x()-blas_speed;
    yf2 = item->y()+(blas_pixel_y_size*game_scale_factor)-1;

    is_valid1 = blocks[yf1/(blas_pixel_y_size*game_scale_factor)][xf1/(blas_pixel_x_size*game_scale_factor)]->get_type()==0;
    is_valid2 = blocks[yf2/(blas_pixel_y_size*game_scale_factor)][xf2/(blas_pixel_x_size*game_scale_factor)]->get_type()==0;

    return is_valid2 && is_valid1;
}

bool reglas_juego::right_movement_is_valid(QGraphicsPixmapItem *item)
{
    int xf1,yf1,xf2,yf2;
    bool is_valid1, is_valid2;

    xf1 = item->x()+(blas_pixel_x_size*game_scale_factor)-1+blas_speed;
    yf1 = item->y();
    xf2 = item->x()+(blas_pixel_x_size*game_scale_factor)-1+blas_speed;
    yf2 = item->y()+(blas_pixel_y_size*game_scale_factor)-1;

    is_valid1 = blocks[yf1/(blas_pixel_y_size*game_scale_factor)][xf1/(blas_pixel_x_size*game_scale_factor)]->get_type()==0;
    is_valid2 = blocks[yf2/(blas_pixel_y_size*game_scale_factor)][xf2/(blas_pixel_x_size*game_scale_factor)]->get_type()==0;

    return is_valid2 && is_valid1;
}

bool reglas_juego::up_movement_is_valid(QGraphicsPixmapItem *item)
{
    int xf1,yf1,xf2,yf2;
    bool is_valid1, is_valid2;

    xf1 = item->x();
    yf1 = item->y() - blas_speed;
    xf2 = item->x() +(blas_pixel_x_size*game_scale_factor)-1;
    yf2 = item->y() - blas_speed;

    is_valid1 = blocks[yf1/(blas_pixel_y_size*game_scale_factor)][xf1/(blas_pixel_x_size*game_scale_factor)]->get_type()==0;
    is_valid2 = blocks[yf2/(blas_pixel_y_size*game_scale_factor)][xf2/(blas_pixel_x_size*game_scale_factor)]->get_type()==0;

    return is_valid2 && is_valid1;
}

bool reglas_juego::down_movement_is_valid(QGraphicsPixmapItem *item)
{
    int xf1,yf1,xf2,yf2;
    bool is_valid1, is_valid2;

    xf1 = item->x();
    yf1 = item->y() + blas_speed+(blas_pixel_y_size*game_scale_factor)-1;
    xf2 = item->x()+(blas_pixel_x_size*game_scale_factor)-1;
    yf2 = item->y()+(blas_pixel_y_size*game_scale_factor)-1 +blas_speed;

    is_valid1 = blocks[yf1/(blas_pixel_y_size*game_scale_factor)][xf1/(blas_pixel_x_size*game_scale_factor)];
    is_valid2 = blocks[yf2/(blas_pixel_y_size*game_scale_factor)][xf2/(blas_pixel_x_size*game_scale_factor)];

    return is_valid2 && is_valid1;
}


QBrush reglas_juego::set_rgb_color(int r, int g, int b, int a)
{
    QBrush color;

    color.setColor(QColor::fromRgb(r,g,b,a));
    color.setStyle(Qt::SolidPattern);

    return color;
}

void reglas_juego::setup_enemigo()
{
    enemigo *enemigo_sprite = new enemigo(game_scale_factor);
    enemigo_sprite->setPos(150, 0);
    scene->addItem(enemigo_sprite);
}
