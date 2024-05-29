#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "reglas_juego.h"
#include <QKeyEvent>
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    reglas_juego *game;
    void setup_game_rules();


};
#endif // MAINWINDOW_H
