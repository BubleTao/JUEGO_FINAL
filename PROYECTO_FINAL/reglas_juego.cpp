#include "reglas_juego.h"

reglas_juego::reglas_juego(QGraphicsView *graph, QVector<QLabel *> game_labels)
{
    srand(time(NULL));

    this->graph = graph;
    //labels = game_labels;
    setup_scene();
    setup_bomberman();
    generate_map();
}

reglas_juego::~reglas_juego()
{
    delete scene;
}

void reglas_juego::key_event(QKeyEvent *event)
{
    bomberman->move(event->key(),true);
}

void reglas_juego::set_bomberman_keys()
{
    bomberman_keys[0] = Qt::Key_A;
    bomberman_keys[1] = Qt::Key_D;
    bomberman_keys[2] = Qt::Key_W;
    bomberman_keys[3] = Qt::Key_S;
}

void reglas_juego::generate_map()
{
    for(unsigned int fil = 0; fil < game_map_rows; fil++){
        for(unsigned int col = 0; col< game_map_col; col++){
            if(fil == 0 || fil == game_map_rows-1 || col == 0 || col == game_map_col -1 || (col%2==0 && fil%2==0)) blocks[fil][col] = new escenario(game_scale_factor,1);
            else if(bernoulli_event()) blocks[fil][col] = new escenario(game_scale_factor,2);
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
}

void reglas_juego::setup_bomberman()
{
    set_bomberman_keys();

    bomberman = new personaje(game_scale_factor);
    bomberman->set_keys(bomberman_keys);
    scene->addItem(bomberman);
}

bool reglas_juego::bernoulli_event()
{
    return (rand()/float(RAND_MAX)) < difficult;
}
