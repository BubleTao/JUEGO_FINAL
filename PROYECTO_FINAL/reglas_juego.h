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

#include "personaje.h"
#include "escenario.h"
#include "disparo.h"
#include "enemigos.h"

#define game_scale_factor 1
#define game_map_rows 13
#define game_map_col 31
#define game_map_size_col 16
#define game_map_size_fil 13

class reglas_juego
{
public:
    reglas_juego(QGraphicsView *graph, QVector<QLabel *> game_labels);
    ~reglas_juego();
    void key_event(QKeyEvent *event);

public slots:
    void disparar();


private:
    QTimer *timer;
    QGraphicsView *graph;


    QVector<QLabel *> labels;
    QGraphicsScene *scene;
    personaje *blas;
    enemigo *enemigo2;
    enemigo *enemigo1;
    enemigo *enemigo3;
    enemigo *enemigo4;
    escenario *muralla;
    unsigned int blas_keys[4];
    float difficult = 0.2;
    Disparo *nuevo_disparo; // Objeto de la clase Disparo
    QMediaPlayer *musicPlayer;

    void set_blas_keys();
    void generate_map();
    void setup_scene();
    void setup_enemigo();
    void setup_blas();
    bool down_movement_is_valid(QGraphicsPixmapItem *item);
    QBrush set_rgb_color(int r, int g, int b, int a = 255);
    void start_parabolic();
    void start_zigzag();
    void start_harmonic();
    void start_pendulum();


};



#endif // REGLAS_JUEGO_H
