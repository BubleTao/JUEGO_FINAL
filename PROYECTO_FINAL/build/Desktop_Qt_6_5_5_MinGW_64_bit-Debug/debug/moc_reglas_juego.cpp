/****************************************************************************
** Meta object code from reading C++ file 'reglas_juego.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../reglas_juego.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'reglas_juego.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSreglas_juegoENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSreglas_juegoENDCLASS = QtMocHelpers::stringData(
    "reglas_juego",
    "disparar",
    "",
    "enemy_is_reached",
    "QGraphicsItem*",
    "item",
    "enemy",
    "remove_shoot",
    "shoot",
    "nivel2",
    "nivel3",
    "enemigos_Collisi"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSreglas_juegoENDCLASS_t {
    uint offsetsAndSizes[24];
    char stringdata0[13];
    char stringdata1[9];
    char stringdata2[1];
    char stringdata3[17];
    char stringdata4[15];
    char stringdata5[5];
    char stringdata6[6];
    char stringdata7[13];
    char stringdata8[6];
    char stringdata9[7];
    char stringdata10[7];
    char stringdata11[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSreglas_juegoENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSreglas_juegoENDCLASS_t qt_meta_stringdata_CLASSreglas_juegoENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "reglas_juego"
        QT_MOC_LITERAL(13, 8),  // "disparar"
        QT_MOC_LITERAL(22, 0),  // ""
        QT_MOC_LITERAL(23, 16),  // "enemy_is_reached"
        QT_MOC_LITERAL(40, 14),  // "QGraphicsItem*"
        QT_MOC_LITERAL(55, 4),  // "item"
        QT_MOC_LITERAL(60, 5),  // "enemy"
        QT_MOC_LITERAL(66, 12),  // "remove_shoot"
        QT_MOC_LITERAL(79, 5),  // "shoot"
        QT_MOC_LITERAL(85, 6),  // "nivel2"
        QT_MOC_LITERAL(92, 6),  // "nivel3"
        QT_MOC_LITERAL(99, 16)   // "enemigos_Collisi"
    },
    "reglas_juego",
    "disparar",
    "",
    "enemy_is_reached",
    "QGraphicsItem*",
    "item",
    "enemy",
    "remove_shoot",
    "shoot",
    "nivel2",
    "nivel3",
    "enemigos_Collisi"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSreglas_juegoENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x0a,    1 /* Public */,
       3,    2,   51,    2, 0x0a,    2 /* Public */,
       7,    1,   56,    2, 0x0a,    5 /* Public */,
       9,    0,   59,    2, 0x0a,    7 /* Public */,
      10,    0,   60,    2, 0x0a,    8 /* Public */,
      11,    0,   61,    2, 0x0a,    9 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Int,    5,    6,
    QMetaType::Void, 0x80000000 | 4,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject reglas_juego::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSreglas_juegoENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSreglas_juegoENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSreglas_juegoENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<reglas_juego, std::true_type>,
        // method 'disparar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'enemy_is_reached'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QGraphicsItem *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'remove_shoot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QGraphicsItem *, std::false_type>,
        // method 'nivel2'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'nivel3'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'enemigos_Collisi'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void reglas_juego::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<reglas_juego *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->disparar(); break;
        case 1: _t->enemy_is_reached((*reinterpret_cast< std::add_pointer_t<QGraphicsItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 2: _t->remove_shoot((*reinterpret_cast< std::add_pointer_t<QGraphicsItem*>>(_a[1]))); break;
        case 3: _t->nivel2(); break;
        case 4: _t->nivel3(); break;
        case 5: _t->enemigos_Collisi(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QGraphicsItem* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QGraphicsItem* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *reglas_juego::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *reglas_juego::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSreglas_juegoENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int reglas_juego::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
