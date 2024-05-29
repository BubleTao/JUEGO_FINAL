#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setup_game_rules();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete game;

}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    game->key_event(event);
}

void MainWindow::setup_game_rules()
{
    QVector<QLabel *> labels;

    //labels.push_back(ui->L_Points);
    //labels.push_back(ui->L_life);
    //labels.push_back(ui->L_life_counter);
    //labels.push_back(ui->L_time);
    //labels.push_back(ui->L_time_counter);

    game = new reglas_juego(ui->graphs,labels);
}
