/********************************************************************************
** Form generated from reading UI file 'ventanas.ui'
**
** Created by: Qt User Interface Compiler version 6.5.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANAS_H
#define UI_VENTANAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ventanas
{
public:
    QWidget *centralwidget;
    QWidget *Game_window;
    QLabel *L_life_counter;
    QLabel *L_life;
    QLabel *L_time;
    QLabel *L_Points;
    QLabel *L_time_counter;
    QGraphicsView *graphicsView;

    void setupUi(QMainWindow *ventanas)
    {
        if (ventanas->objectName().isEmpty())
            ventanas->setObjectName("ventanas");
        ventanas->resize(409, 542);
        centralwidget = new QWidget(ventanas);
        centralwidget->setObjectName("centralwidget");
        Game_window = new QWidget(centralwidget);
        Game_window->setObjectName("Game_window");
        Game_window->setGeometry(QRect(20, 20, 571, 481));
        L_life_counter = new QLabel(Game_window);
        L_life_counter->setObjectName("L_life_counter");
        L_life_counter->setGeometry(QRect(10, 40, 49, 16));
        L_life = new QLabel(Game_window);
        L_life->setObjectName("L_life");
        L_life->setGeometry(QRect(20, 70, 49, 16));
        L_time = new QLabel(Game_window);
        L_time->setObjectName("L_time");
        L_time->setGeometry(QRect(70, 40, 49, 16));
        L_Points = new QLabel(Game_window);
        L_Points->setObjectName("L_Points");
        L_Points->setGeometry(QRect(80, 70, 49, 16));
        L_time_counter = new QLabel(Game_window);
        L_time_counter->setObjectName("L_time_counter");
        L_time_counter->setGeometry(QRect(30, 20, 49, 16));
        graphicsView = new QGraphicsView(Game_window);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(-10, -10, 370, 600));
        ventanas->setCentralWidget(centralwidget);

        retranslateUi(ventanas);

        QMetaObject::connectSlotsByName(ventanas);
    } // setupUi

    void retranslateUi(QMainWindow *ventanas)
    {
        ventanas->setWindowTitle(QCoreApplication::translate("ventanas", "ventanas", nullptr));
        L_life_counter->setText(QCoreApplication::translate("ventanas", "TextLabel", nullptr));
        L_life->setText(QCoreApplication::translate("ventanas", "TextLabel", nullptr));
        L_time->setText(QCoreApplication::translate("ventanas", "TextLabel", nullptr));
        L_Points->setText(QCoreApplication::translate("ventanas", "TextLabel", nullptr));
        L_time_counter->setText(QCoreApplication::translate("ventanas", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ventanas: public Ui_ventanas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAS_H
