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
private:
    QTimer *timer;
    QTimer *duracion_nivel;
    QGraphicsView *graph;


    QVector<QLabel *> labels;
    QGraphicsScene *scene;
    personaje *blas;
    QVector<enemigo *> enemys;
    escenario *muralla;
    unsigned int blas_keys[4];
    float difficult = 0.2;
    QVector<Disparo *> disparos; // Objeto de la clase Disparo
    QMediaPlayer *musicPlayer;


    void set_blas_keys();
    void generate_map();
    void setup_scene(QString fondo);
    void setup_enemigo(QString sprite, QString sprite2);
    void setup_blas();
    bool down_movement_is_valid(QGraphicsPixmapItem *item);
    void start_parabolic();
    void start_zigzag();
    void start_harmonic();
    void start_pendulum();
    void star_music();
    bool pared_valida(bool izq);
    void load_level_1();
    void clear_scene();

};



#endif // REGLAS_JUEGO_H
