/****************************************************************************
** Meta object code from reading C++ file 'cartwd.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../InsToCart/cartwd.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cartwd.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CartWD_t {
    const uint offsetsAndSize[10];
    char stringdata0[63];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_CartWD_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_CartWD_t qt_meta_stringdata_CartWD = {
    {
QT_MOC_LITERAL(0, 6), // "CartWD"
QT_MOC_LITERAL(7, 11), // "pressRemove"
QT_MOC_LITERAL(19, 0), // ""
QT_MOC_LITERAL(20, 14), // "dsValueChanged"
QT_MOC_LITERAL(35, 27) // "on_pushButton_place_clicked"

    },
    "CartWD\0pressRemove\0\0dsValueChanged\0"
    "on_pushButton_place_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CartWD[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x08,    0 /* Private */,
       3,    1,   33,    2, 0x08,    1 /* Private */,
       4,    0,   36,    2, 0x08,    3 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,

       0        // eod
};

void CartWD::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CartWD *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->pressRemove(); break;
        case 1: _t->dsValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_place_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject CartWD::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CartWD.offsetsAndSize,
    qt_meta_data_CartWD,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_CartWD_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *CartWD::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CartWD::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CartWD.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CartWD::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
