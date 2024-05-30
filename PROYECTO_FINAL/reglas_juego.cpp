#include "reglas_juego.h"
#include <chrono>
#include <QDebug>

reglas_juego::reglas_juego(QGraphicsView *graph)
{
    srand(time(NULL));
    this->graph = graph;
    duracion_nivel = new QTimer;
    load_level_1();
    //labels
    connect(duracion_nivel, SIGNAL(timeout()), this, SLOT(nivel2()));

}

reglas_juego::~reglas_juego()
{
    delete scene;
    delete blas;
    delete musicPlayer;
    delete duracion_nivel;
    for(int i=0; i<enemys.length(); i++) delete enemys[i];
    for(int i=0; i<disparos.length(); i++) delete disparos[i];
    enemys.clear();
    disparos.clear();
}


void reglas_juego::key_event(QKeyEvent *event)
{

    if(unsigned(event->key()) == blas_keys[0])blas->move(event->key(),pared_valida(true));
    else if(unsigned(event->key()) == blas_keys[1])blas->move(event->key(),pared_valida(false));
    else if(unsigned(event->key()) == blas_keys[2]) disparar();
}
bool reglas_juego::pared_valida(bool izq)
{
    int posicion = blas->x();

    if (izq) posicion -=8;
    else posicion +=8;

    if (posicion < -10 || posicion > 335){
        return false;
    }
    return true;
}

void reglas_juego::load_level_1()
{
    setup_scene(":/imagenes/fondo1.png");
    duracion_nivel->start(40000);
    setup_enemigo(":/imagenes/enemigo1.png",":/imagenes/enemigo2.png");
    start_parabolic();
    start_zigzag();
    start_harmonic();
    generate_map();
    setup_blas();
    start_pendulum();
    star_music();
}

void reglas_juego::clear_scene()
{
    duracion_nivel->stop();
    scene->clear();
    enemys.clear();
    disparos.clear();
}



void reglas_juego::remove_shoot(QGraphicsItem *shoot)
{
    scene->removeItem(shoot);
    for(int i=0; i<disparos.length(); i++){
        if(disparos[i] == shoot){
            disconnect(disparos[i]);
            disparos.remove(i);
            break;
        }
    }
}

void reglas_juego::nivel2()
{
    setup_scene(":/imagenes/fondo2.png");
    clear_scene();
    //duracion_nivel->start(40000);
    setup_enemigo(":/imagenes/enemigo1.png",":/imagenes/enemigo2.png");
    start_parabolic();
    start_zigzag();
    start_harmonic();
    generate_map();
    setup_blas();
    start_pendulum();
    star_music();
}
void reglas_juego::disparar()
{
    disparos.push_back(new Disparo(enemys, 0.03, 10.0, -1.0));
    connect(disparos[disparos.length()-1],SIGNAL(is_enemy_reached(QGraphicsItem*,int)),this,SLOT(enemy_is_reached(QGraphicsItem*,int)));
    connect(disparos[disparos.length()-1],SIGNAL(is_shoot_out_of_range(QGraphicsItem*)),this,SLOT(remove_shoot(QGraphicsItem*)));
    //qDebug() << "Bala creada";
    disparos[disparos.length()-1]->setPos(blas->x(), blas->y());
    scene->addItem(disparos[disparos.length()-1]);
}

void reglas_juego::enemy_is_reached(QGraphicsItem *item, int enemy)
{
    remove_shoot(item);
    // Llama la rutina de muerteaquiiiii
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

void reglas_juego::setup_scene(QString fondo)
{
    int new_width = 370;
    int new_height = 600;
    graph->setGeometry(0, 0, new_width, new_height);
    scene = new QGraphicsScene;
    scene->setSceneRect(0, 0, new_width - 2, new_height - 2);
    graph->setScene(scene);
    QPixmap background(fondo);
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


void reglas_juego::setup_enemigo(QString sprite,QString sprite2)
{
    enemys.push_back(new enemigo(30,0,20 ,0.5,sprite2));
    enemys.push_back(new enemigo(150,0,20 ,0.5,sprite));
    enemys.push_back(new enemigo(190,0,20 ,0.5,sprite2));
    enemys.push_back(new enemigo(50,0,20 ,0.5,sprite));

    for(short i=0; i<enemys.length(); i++) scene->addItem(enemys[i]);
}

void reglas_juego::start_parabolic()
{
    enemys[1]->start_parabolic_movement();
}

void reglas_juego::start_zigzag()
{
    enemys[0]->start_zigzag_movement();
}
void reglas_juego::start_harmonic()
{
    enemys[2]->start_harmonic_movement(200,1);
}
void reglas_juego::start_pendulum()
{
    enemys[3]->start_pendulum_motion(200,10);
}

void reglas_juego::star_music()
{
    musicPlayer = new QMediaPlayer;
    musicPlayer->setSource(QUrl(":/imagenes/MUSICA EPICA PARA PIRATAS EPICOS.mp3"));
    musicPlayer->setAudioOutput(new QAudioOutput);
    musicPlayer->audioOutput() ->setVolume(50);
    musicPlayer->play();
}




