#include "pantallaInicio.h"

PantallaInicio::PantallaInicio(QWidget *parent) : QWidget(parent)
{
    // Configurar la pantalla de inicio
    setFixedSize(375, 600); // Establecer el tamaño fijo de la ventana
    setWindowTitle("Pantalla de Inicio"); // Establecer el título de la ventana

    // Crear el fondo
    QPixmap fondo(":/imagenes/menu.png");
    fondo = fondo.scaled(375, 600); // Escalar la imagen al tamaño de la ventana
    fondoLabel = new QLabel(this);
    fondoLabel->setPixmap(fondo);

    // Crear los elementos de la pantalla
    tituloLabel = new QLabel("Título del Juego", this);
    jugarButton = new QPushButton("Jugar", this);
    salirButton = new QPushButton("Salir", this);

    // Crear el diseño de la pantalla
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(fondoLabel);
    layout->addWidget(tituloLabel);
    layout->addWidget(jugarButton);
    layout->addWidget(salirButton);

    // Conectar los botones a las señales correspondientes
    connect(jugarButton, &QPushButton::clicked, this, &PantallaInicio::jugarClicked);
    connect(salirButton, &QPushButton::clicked, this, &PantallaInicio::salirClicked);
}
