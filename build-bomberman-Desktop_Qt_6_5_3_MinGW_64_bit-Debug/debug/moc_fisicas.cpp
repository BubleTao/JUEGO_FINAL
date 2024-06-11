/****************************************************************************
** Meta object code from reading C++ file 'fisicas.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PROYECTO_FINAL/fisicas.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fisicas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
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
struct qt_meta_stringdata_CLASSfisicasENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSfisicasENDCLASS = QtMocHelpers::stringData(
    "fisicas",
    "parabolic_shoot",
    "",
    "MRU",
    "set_starting_parameters",
    "x",
    "y",
    "vx",
    "vy",
    "zigzag",
    "harmonic_motion",
    "pendulum_motion"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSfisicasENDCLASS_t {
    uint offsetsAndSizes[24];
    char stringdata0[8];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[4];
    char stringdata4[24];
    char stringdata5[2];
    char stringdata6[2];
    char stringdata7[3];
    char stringdata8[3];
    char stringdata9[7];
    char stringdata10[16];
    char stringdata11[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSfisicasENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSfisicasENDCLASS_t qt_meta_stringdata_CLASSfisicasENDCLASS = {
    {
        QT_MOC_LITERAL(0, 7),  // "fisicas"
        QT_MOC_LITERAL(8, 15),  // "parabolic_shoot"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 3),  // "MRU"
        QT_MOC_LITERAL(29, 23),  // "set_starting_parameters"
        QT_MOC_LITERAL(53, 1),  // "x"
        QT_MOC_LITERAL(55, 1),  // "y"
        QT_MOC_LITERAL(57, 2),  // "vx"
        QT_MOC_LITERAL(60, 2),  // "vy"
        QT_MOC_LITERAL(63, 6),  // "zigzag"
        QT_MOC_LITERAL(70, 15),  // "harmonic_motion"
        QT_MOC_LITERAL(86, 15)   // "pendulum_motion"
    },
    "fisicas",
    "parabolic_shoot",
    "",
    "MRU",
    "set_starting_parameters",
    "x",
    "y",
    "vx",
    "vy",
    "zigzag",
    "harmonic_motion",
    "pendulum_motion"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSfisicasENDCLASS[] = {

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
       1,    0,   50,    2, 0x08,    1 /* Private */,
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    4,   52,    2, 0x08,    3 /* Private */,
       9,    0,   61,    2, 0x08,    8 /* Private */,
      10,    0,   62,    2, 0x08,    9 /* Private */,
      11,    0,   63,    2, 0x08,   10 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    5,    6,    7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject fisicas::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSfisicasENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSfisicasENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSfisicasENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<fisicas, std::true_type>,
        // method 'parabolic_shoot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'MRU'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'set_starting_parameters'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'zigzag'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'harmonic_motion'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pendulum_motion'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void fisicas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<fisicas *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->parabolic_shoot(); break;
        case 1: _t->MRU(); break;
        case 2: _t->set_starting_parameters((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 3: _t->zigzag(); break;
        case 4: _t->harmonic_motion(); break;
        case 5: _t->pendulum_motion(); break;
        default: ;
        }
    }
}

const QMetaObject *fisicas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *fisicas::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSfisicasENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int fisicas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
