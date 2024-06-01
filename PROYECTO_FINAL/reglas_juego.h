#ifndef REGLAS_JUEGO_H
#define REGLAS_JUEGO_H

#include <QWidget>
#include <QVector>
#include <QLabel>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <cstdlib>
#include <ctime>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QApplication>
#include <QTimer>
#include <QMediaPlayer>
#include <QAudioOutput>

#include "personaje.h"
#include "escenario.h"
#include "finalboss.h"
#include "disparo.h"
#include "enemigos.h"

#define game_scale_factor 1
#define game_map_rows 13
#define game_map_col 31
#define game_map_size_col 16
#define game_map_size_fil 13

class reglas_juego : public QObject
{
    Q_OBJECT
public:
    reglas_juego(QGraphicsView *graph);
    ~reglas_juego();
    void key_event(QKeyEvent *event);

public slots:
    void disparar();
    void enemy_is_reached(QGraphicsItem *item, int enemy);
    void remove_shoot(QGraphicsItem *shoot);
    void nivel2();
    void nivel3();
    void enemigos_Collisi();
private:
    QTimer *timer;
    QTimer *duracion_nivel;
    QTimer *duracion_nivel2;
    QGraphicsView *graph;
    int muralla_vida;


    QVector<QLabel *> labels;
    QGraphicsScene *scene;
    personaje *blas;
    QVector<enemigo *> enemys;
    escenario *muralla;
    finalboss *barcofinal;
    muerte *animacion_muerte;
    unsigned int blas_keys[4];
    float difficult = 0.2;
    QVector<Disparo *> disparos; // Objeto de la clase Disparo
    QMediaPlayer *musicPlayer;
    QMediaPlayer *musicPlayerboss;


    void set_blas_keys();
    void generate_map();
    void generate_finalboss();
    void setup_scene(QString fondo);
    void setup_enemigo(QString sprite, QString sprite2, float scale);
    void setup_blas();
    bool down_movement_is_valid(QGraphicsPixmapItem *item);
    void start_parabolic();
    void start_zigzag();
    void start_harmonic();
    void start_pendulum();
    void star_music();
    void star_musicboss();
    bool pared_valida(bool izq);
    void load_level_1();
    void clear_scene();

};



#endif // REGLAS_JUEGO_H
