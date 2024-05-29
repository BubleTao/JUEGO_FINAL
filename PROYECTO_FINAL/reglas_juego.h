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

#include "personaje.h"
#include "escenario.h"

#define factor_escala_juego 2
#define filas_mapa_juego 13
#define columnas_mapa_juego 31
#define tamaño_columna_mapa_juego 16
#define tamaño_fila_mapa_juego 13

class reglas_juego
{
public:
    reglas_juego(QGraphicsView *vista, QVector<QLabel *> etiquetas_juego);
    ~reglas_juego();
    void key_event(QKeyEvent *evento);

private:
    QGraphicsView *vista;
    QVector<QLabel *> etiquetas;
    QGraphicsScene *escena;
    personaje *bomberman;
    escenario *bloques[filas_mapa_juego][columnas_mapa_juego];
    unsigned int teclas_bomberman[4];
    float dificultad = 0.2;

    void set_bomberman_keys();
    void generate_map();
    void setup_scene();
    void setup_bomberman();
    bool bernoulli_event();
};

#endif // REGLAS_JUEGO_H
