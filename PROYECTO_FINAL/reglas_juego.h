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
#include <fstream>

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
    void setup_enemy_spawn(QString sprite, float scale, int interval, int tipo_movimiento);
    void spawn_enemy(QString sprite, float scale, int tipo_movimiento);
private:
    QTimer *timer;
    QTimer *duracion_nivel;
    QTimer *duracion_nivel2;
    QTimer *spawn_timer;
    QGraphicsView *graph;
    int muralla_vida;
    QTimer *disparo_timer;
    bool puede_disparar;

    QVector<QLabel *> labels;
    QGraphicsScene *scene;
    personaje *blas;
    QVector<enemigo *> enemys;
    escenario *muralla;
    finalboss *barcofinal;
    muerte *animacion_muerte;
    unsigned int blas_keys[4];
    QVector<Disparo *> disparos; // Objeto de la clase Disparo
    QMediaPlayer *musicPlayer;
    QMediaPlayer *musicPlayerboss;
    QAudioOutput *audioOutput;
    QAudioOutput *audioOutputboss;

    int score;


    void set_blas_keys();
    void generate_map();
    void generate_finalboss();
    void setup_scene(QString fondo);
    void setup_blas();
    bool down_movement_is_valid(QGraphicsPixmapItem *item);
    void start_parabolic();
    void start_zigzag();
    void start_harmonic();
    void start_pendulum();
    void star_music();
    void star_music2();
    void star_musicboss();
    bool pared_valida(bool izq);
    void load_level_1();
    void clear_scene();
    void habilitar_disparo();

    // Métodos para manejo de archivos
    void create_score_file();
    void update_score_file();
    int read_score_from_file();

};

#endif // REGLAS_JUEGO_H
