#ifndef PANTALLA_INICIO_H
#define PANTALLA_INICIO_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class PantallaInicio : public QWidget
{
    Q_OBJECT
public:
    explicit PantallaInicio(QWidget *parent = nullptr);

signals:
    void jugarClicked();
    void salirClicked();

private:
    QLabel *fondoLabel;
    QLabel *tituloLabel;
    QPushButton *jugarButton;
    QPushButton *salirButton;
};

#endif // PANTALLA_INICIO_H
