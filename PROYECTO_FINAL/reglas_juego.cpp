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
    else if(unsigned(event->key()) == blas_keys[3]) is_valid = down_movement_is_valid(blas);
    if(blas->x()<700 && blas->x()>230) set_focus_element(blas,blas_pixel_x_size*game_scale_factor,0);
    blas->move(event->key(),is_valid);

}
void reglas_juego::set_blas_keys()
{
    blas_keys[0] = Qt::Key_A;
    blas_keys[1] = Qt::Key_D;
    blas_keys[3] = Qt::Key_S;
}

void reglas_juego::generate_map()
{
    for(unsigned int fil = 0; fil < game_map_rows; fil++){
        for(unsigned int col = 0; col< game_map_col; col++){
            if(fil == 0 || fil == game_map_rows-1 || col == 0 || col == game_map_col -1 || (col%2==0 && fil%2==0)) blocks[fil][col] = new escenario(game_scale_factor,1);
            else blocks[fil][col] = new escenario(game_scale_factor,0);
            blocks[fil][col]->setX(game_scale_factor*blocks_pixel_x_size*col);
            blocks[fil][col]->setY(game_scale_factor*blocks_pixel_y_size*fil);
            scene->addItem(blocks[fil][col]);
        }
    }
}

void reglas_juego::setup_scene()
{

    graph->setGeometry(0,0,
                       game_scale_factor*blocks_pixel_x_size*game_map_size_col,
                       game_scale_factor*blocks_pixel_y_size*game_map_size_fil);
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,graph->width()-2, graph->height()-2);
    graph->setScene(scene);
    scene->setBackgroundBrush(set_rgb_color(56,135,0));
}

void reglas_juego::setup_blas()
{
    set_blas_keys();

    blas = new personaje(game_scale_factor);
    blas->set_keys(blas_keys);
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

    is_valid1 = blocks[yf1/(blas_pixel_y_size*game_scale_factor)][xf1/(blas_pixel_x_size*game_scale_factor)]->get_type()==0;
    is_valid2 = blocks[yf2/(blas_pixel_y_size*game_scale_factor)][xf2/(blas_pixel_x_size*game_scale_factor)]->get_type()==0;

    return is_valid2 && is_valid1;
}

void reglas_juego::set_focus_element(QGraphicsPixmapItem *item,unsigned int scalex, unsigned int scaley)
{
    scene->setSceneRect(item->x()+scalex-scene->width()/2,0,scene->width(),scene->height());
}

QBrush reglas_juego::set_rgb_color(int r, int g, int b, int a)
{
    QBrush color;

    color.setColor(QColor::fromRgb(r,g,b,a));
    color.setStyle(Qt::SolidPattern);

    return color;
}


