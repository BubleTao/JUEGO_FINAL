#include "ventanas.h"
#include "ui_ventanas.h"

ventanas::ventanas(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ventanas)
{
    ui->setupUi(this);
    ui->graphicsView->setVisible(false);
    ui->widget->setVisible(true);
    ui->widget->setStyleSheet("background-image: url(:/imagenes/menu.png)");
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(setup_game_rules()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(close()));
    //setup_game_rules();
    //pushButton_2
}

ventanas::~ventanas()
{
    delete ui;
    delete game;
}

void ventanas::keyPressEvent(QKeyEvent *event)
{
    game->key_event(event);
}

void ventanas::setup_game_rules()
{
    ui->graphicsView->setVisible(true);
    ui->widget->setVisible(false);
    game = new reglas_juego(ui->graphicsView);
}

