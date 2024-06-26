QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    disparo.cpp \
    enemigos.cpp \
    escenario.cpp \
    finalboss.cpp \
    fisicas.cpp \
    main.cpp \
    muerte.cpp \
    personaje.cpp \
    reglas_juego.cpp \
    sprites.cpp \
    ventanas.cpp

HEADERS += \
    disparo.h \
    enemigos.h \
    escenario.h \
    finalboss.h \
    fisicas.h \
    muerte.h \
    personaje.h \
    reglas_juego.h \
    sprites.h \
    ventanas.h

FORMS += \
    ventanas.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
