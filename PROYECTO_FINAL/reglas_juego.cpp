#include "reglas_juego.h"
#include <chrono>
#include <QDebug>

reglas_juego::reglas_juego(QGraphicsView *graph)
{
    srand(time(NULL));
    this->graph = graph;
    duracion_nivel = new QTimer;
    duracion_nivel2 = new QTimer;
    disparo_timer = new QTimer(this);
    puede_disparar = true;
    musicPlayer = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    musicPlayer->setAudioOutput(audioOutput);

    musicPlayerboss = new QMediaPlayer(this);
    audioOutputboss = new QAudioOutput(this);
    musicPlayerboss->setAudioOutput(audioOutputboss);

    load_level_1();
    muralla_vida = 1;
    //niveles
    connect(duracion_nivel, SIGNAL(timeout()), this, SLOT(nivel2()));
    connect(duracion_nivel2, SIGNAL(timeout()), this, SLOT(nivel3()));
    //
    connect(disparo_timer, &QTimer::timeout, this, &reglas_juego::habilitar_disparo);
    QTimer *collision_timer = new QTimer(this);
    connect(collision_timer, SIGNAL(timeout()), this, SLOT(enemigos_Collisi()));
    collision_timer->start(50);

}

reglas_juego::~reglas_juego()
{
    delete scene;
    delete blas;
    delete musicPlayer;
    delete musicPlayerboss;
    delete duracion_nivel;
    delete duracion_nivel2;
    delete muralla;
    delete barcofinal;
    delete animacion_muerte;
    delete spawn_timer;
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
    duracion_nivel->start(80000);
    setup_enemy_spawn(":/imagenes/enemigo2.png", 0.5, 6000, 4);
    setup_enemy_spawn(":/imagenes/enemigo2.png", 0.5, 4000, 2);
    generate_map();
    setup_blas();
    star_music();
}
void reglas_juego::nivel2()
{
    duracion_nivel->stop();
    setup_scene(":/imagenes/fondo2.png");
    clear_scene();
    setup_enemy_spawn(":/imagenes/enemigo1.png", 0.5, 8000, 1);
    duracion_nivel2->start(70000);
    generate_map();
    setup_blas();
    star_music();
}
void reglas_juego::nivel3()
{
    if (musicPlayer->isPlaying()) {
        musicPlayer->stop();
    }
    duracion_nivel2->stop();
    setup_scene(":/imagenes/fondo3.png");
    clear_scene();
    setup_enemy_spawn(":/imagenes/enemigo2.png", 0.5, 7000, 2);
    setup_enemy_spawn(":/imagenes/balajefe.png", 0.5, 9000, 3);
    generate_map();
    generate_finalboss();
    setup_blas();
    star_musicboss();
}
void reglas_juego::clear_scene()
{
    duracion_nivel->stop();
    scene->clear();
    enemys.clear();
    disparos.clear();
}

void reglas_juego::habilitar_disparo()
{
    puede_disparar = true;
    disparo_timer->stop();
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

void reglas_juego::enemigos_Collisi()
{
    for (int i = 0; i < enemys.size(); ++i)
    {
        if (enemys[i]->collidesWithItem(muralla))
        {

            muralla_vida--;
            scene->removeItem(enemys[i]);
            delete enemys[i];
            enemys.remove(i);


            if (muralla_vida <= 0)
            {

                qDebug() << "Game Over";
                QApplication::quit();
            }
            break;
        }
    }
}


void reglas_juego::disparar()
{
    if (puede_disparar) {
        disparos.push_back(new Disparo(enemys, 0.03, 10.0, -1.0));
        connect(disparos[disparos.length()-1], SIGNAL(is_enemy_reached(QGraphicsItem*, int)), this, SLOT(enemy_is_reached(QGraphicsItem*, int)));
        connect(disparos[disparos.length()-1], SIGNAL(is_shoot_out_of_range(QGraphicsItem*)), this, SLOT(remove_shoot(QGraphicsItem*)));
        //qDebug() << "Bala creada";
        disparos[disparos.length()-1]->setPos(blas->x(), blas->y());
        scene->addItem(disparos[disparos.length()-1]);

        puede_disparar = false;
        disparo_timer->start(2000);
    }
}

void reglas_juego::enemy_is_reached(QGraphicsItem *item, int enemy)
{
    remove_shoot(item);

    QGraphicsItem* enemy_item = enemys[enemy];
    QPointF enemy_position = enemy_item->pos();
    enemys.remove(enemy);
    scene->removeItem(enemy_item);
    delete enemy_item;

    // Crear la animación de muerte

    animacion_muerte = new muerte(0.8);
    animacion_muerte->setPos(enemy_position);
    scene->addItem(animacion_muerte);
    connect(animacion_muerte, &muerte::animation_finished, [this]() {
        scene->removeItem(animacion_muerte);
        delete animacion_muerte;
        animacion_muerte = nullptr;
    });
    animacion_muerte->start_animation();
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

void reglas_juego::generate_finalboss()
{
    barcofinal = new finalboss(0.25);
    barcofinal->setPos(80,5);
    scene->addItem(barcofinal);
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

void reglas_juego::setup_enemy_spawn(QString sprite, float scale, int interval, int tipo_movimiento)
{
    spawn_timer = new QTimer;
    connect(spawn_timer, &QTimer::timeout, this, [this, sprite, scale, tipo_movimiento]() {
        this->spawn_enemy(sprite, scale, tipo_movimiento);
    });
    spawn_timer->start(interval);
}

void reglas_juego::spawn_enemy(QString sprite, float scale, int tipo_movimiento)
{
    int random_x = 30 + rand() % (200);
    int y = 0;
    enemigo* new_enemy = new enemigo(random_x, y, 20, scale, sprite);
    enemys.push_back(new_enemy);
    scene->addItem(new_enemy);

    switch (tipo_movimiento) {
    case 1:
        new_enemy->start_harmonic_movement(200, 1);
        break;
    case 2:
        new_enemy->start_pendulum_motion(200, 10);
        break;
    case 3:
        new_enemy->start_parabolic_movement();
        break;
    case 4:
        new_enemy->start_zigzag_movement();
        break;
    default:
        qDebug() << "Movimiento no válido";
        break;
    }
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

void reglas_juego::star_music() {
    if (musicPlayer->isPlaying()) {
        musicPlayer->stop();
    }
    audioOutput->setVolume(30);
    musicPlayer->setSource(QUrl("qrc:/imagenes/MUSICA EPICA PARA PIRATAS EPICOS.mp3"));
    musicPlayer->play();
}


void reglas_juego::star_musicboss() {
    if (musicPlayerboss->isPlaying()) {
        musicPlayerboss->stop();
    }
    audioOutputboss->setVolume(30);
    musicPlayerboss->setSource(QUrl("qrc:/imagenes/la-cancion-de-los-gigantes-dormidos-criaturas-mitologicas_kUk3HbNU.mp3"));
    musicPlayerboss->play();
}
