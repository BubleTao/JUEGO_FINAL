#include "reglas_juego.h"
#include <chrono>
#include <QDebug>

reglas_juego::reglas_juego(QGraphicsView *graph, QVector<QLabel *> game_labels)
{
    srand(time(NULL));
    this->graph = graph;
    labels = game_labels;
    setup_scene();
    setup_enemigo();
    start_parabolic();
    start_zigzag();
    start_harmonic();
    generate_map();
    setup_blas();
    start_pendulum();
    //playBackgroundMusic();
    //labels

}

reglas_juego::~reglas_juego()
{
    delete scene;
    delete blas;
    delete enemigo1;
    delete enemigo2;
    delete enemigo3;
    delete enemigo4;
    delete musicPlayer;


}


void reglas_juego::key_event(QKeyEvent *event)
{

    if(unsigned(event->key()) == blas_keys[0])blas->move(event->key(),true);
    else if(unsigned(event->key()) == blas_keys[1])blas->move(event->key(),true);
    else if(unsigned(event->key()) == blas_keys[2]) disparar();
}

void reglas_juego::disparar()
{
    nuevo_disparo = new Disparo(0.05, 10.0, -1.0);
    //qDebug() << "Bala creada";
    nuevo_disparo->setPos(blas->x(), blas->y());
    scene->addItem(nuevo_disparo);
}

void reglas_juego::set_blas_keys()
{
    blas_keys[0] = Qt::Key_A;
    blas_keys[1] = Qt::Key_D;
    blas_keys[2] = Qt::Key_Space;
}

void reglas_juego::generate_map()
{
        muralla = new escenario(0.72);
        muralla->setPos(0,396);
        scene->addItem(muralla);
}

void reglas_juego::setup_scene()
{
    int new_width = 370;
    int new_height = 600;
    graph->setGeometry(0, 0, new_width, new_height);
    scene = new QGraphicsScene;
    scene->setSceneRect(0, 0, new_width - 2, new_height - 2);
    graph->setScene(scene);
    QPixmap background(":/imagenes/fondo1.png");
    scene->setBackgroundBrush(background);
}

void reglas_juego::setup_blas()
{
    set_blas_keys();

    blas = new personaje(game_scale_factor);
    blas->set_keys(blas_keys);
    blas->setPos(150,440);
    scene->addItem(blas);
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
    enemigo1 = new enemigo(30,0,20 ,0.5);
    enemigo2 = new enemigo(150,0,20 ,0.5);
    enemigo3 = new enemigo(190,0,20 ,0.5);
    enemigo4 = new enemigo(50,0,20 ,0.5);
    scene->addItem(enemigo2);
    scene->addItem(enemigo1);
    scene->addItem(enemigo3);
    scene->addItem(enemigo4);
}

void reglas_juego::start_parabolic()
{
    enemigo2->start_parabolic_movement();
}

void reglas_juego::start_zigzag()
{
    enemigo1->start_zigzag_movement();
}
void reglas_juego::start_harmonic()
{
    enemigo3->start_harmonic_movement(200,1);
}
void reglas_juego::start_pendulum()
{
    enemigo4->start_pendulum_motion(200,10);
}

