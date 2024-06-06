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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ventanas
{
public:
    QWidget *centralwidget;
    QWidget *Game_window;
    QGraphicsView *graphicsView;
    QWidget *widget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;

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
        graphicsView = new QGraphicsView(Game_window);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(-10, -10, 370, 600));
        widget = new QWidget(Game_window);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 361, 481));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(60, 300, 75, 24));
        pushButton->setStyleSheet(QString::fromUtf8(""));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(200, 300, 75, 24));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 70, 200, 200));
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-image: url(:/imagenes/titulo..png);\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"\n"
"}"));
        label->setScaledContents(false);
        ventanas->setCentralWidget(centralwidget);

        retranslateUi(ventanas);

        QMetaObject::connectSlotsByName(ventanas);
    } // setupUi

    void retranslateUi(QMainWindow *ventanas)
    {
        ventanas->setWindowTitle(QCoreApplication::translate("ventanas", "ventanas", nullptr));
        pushButton->setText(QCoreApplication::translate("ventanas", "JUGAR", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ventanas", "SALIR", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ventanas: public Ui_ventanas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAS_H
