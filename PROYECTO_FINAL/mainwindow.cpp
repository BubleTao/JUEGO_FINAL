#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRect Desktop= Desktop(400,600);
    x=Desktop,x();
    y=Desktop.y();
    ancho = Desktop.width()-50;
    alto = Desktop.height()-50;

    scene = new QGraphicsScene(x,y,ancho,alto);
    ui->graphicsView->setScene(scene);

    hola = new sprites();
    scene->addItem(hola);

    hola->setPos(0,0);
}

MainWindow::~MainWindow()
{
    delete ui;

}
