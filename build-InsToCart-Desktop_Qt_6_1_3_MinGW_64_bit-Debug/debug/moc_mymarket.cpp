/****************************************************************************
** Meta object code from reading C++ file 'mymarket.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../InsToCart/mymarket.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mymarket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyMarket_t {
    const uint offsetsAndSize[36];
    char stringdata0[349];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MyMarket_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MyMarket_t qt_meta_stringdata_MyMarket = {
    {
QT_MOC_LITERAL(0, 8), // "MyMarket"
QT_MOC_LITERAL(9, 21), // "on_addProduct_clicked"
QT_MOC_LITERAL(31, 0), // ""
QT_MOC_LITERAL(32, 17), // "on_update_clicked"
QT_MOC_LITERAL(50, 14), // "on_del_clicked"
QT_MOC_LITERAL(65, 15), // "on_back_clicked"
QT_MOC_LITERAL(81, 20), // "slotRowDoubleClicked"
QT_MOC_LITERAL(102, 11), // "QModelIndex"
QT_MOC_LITERAL(114, 5), // "index"
QT_MOC_LITERAL(120, 30), // "slotRowDoubleClicked_completed"
QT_MOC_LITERAL(151, 34), // "slotRowDoubleClicked_tobecomp..."
QT_MOC_LITERAL(186, 38), // "slotComboboxIndexChanged_tobe..."
QT_MOC_LITERAL(225, 18), // "on_search1_clicked"
QT_MOC_LITERAL(244, 18), // "on_search2_clicked"
QT_MOC_LITERAL(263, 23), // "on_searchType_activated"
QT_MOC_LITERAL(287, 22), // "on_managestock_clicked"
QT_MOC_LITERAL(310, 22), // "on_manageorder_clicked"
QT_MOC_LITERAL(333, 15) // "on_save_clicked"

    },
    "MyMarket\0on_addProduct_clicked\0\0"
    "on_update_clicked\0on_del_clicked\0"
    "on_back_clicked\0slotRowDoubleClicked\0"
    "QModelIndex\0index\0slotRowDoubleClicked_completed\0"
    "slotRowDoubleClicked_tobecompleted\0"
    "slotComboboxIndexChanged_tobecompleted\0"
    "on_search1_clicked\0on_search2_clicked\0"
    "on_searchType_activated\0on_managestock_clicked\0"
    "on_manageorder_clicked\0on_save_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyMarket[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x08,    0 /* Private */,
       3,    0,   99,    2, 0x08,    1 /* Private */,
       4,    0,  100,    2, 0x08,    2 /* Private */,
       5,    0,  101,    2, 0x08,    3 /* Private */,
       6,    1,  102,    2, 0x08,    4 /* Private */,
       9,    1,  105,    2, 0x08,    6 /* Private */,
      10,    1,  108,    2, 0x08,    8 /* Private */,
      11,    1,  111,    2, 0x08,   10 /* Private */,
      12,    0,  114,    2, 0x08,   12 /* Private */,
      13,    0,  115,    2, 0x08,   13 /* Private */,
      14,    1,  116,    2, 0x08,   14 /* Private */,
      15,    0,  119,    2, 0x08,   16 /* Private */,
      16,    0,  120,    2, 0x08,   17 /* Private */,
      17,    0,  121,    2, 0x08,   18 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyMarket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyMarket *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_addProduct_clicked(); break;
        case 1: _t->on_update_clicked(); break;
        case 2: _t->on_del_clicked(); break;
        case 3: _t->on_back_clicked(); break;
        case 4: _t->slotRowDoubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->slotRowDoubleClicked_completed((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->slotRowDoubleClicked_tobecompleted((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->slotComboboxIndexChanged_tobecompleted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_search1_clicked(); break;
        case 9: _t->on_search2_clicked(); break;
        case 10: _t->on_searchType_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_managestock_clicked(); break;
        case 12: _t->on_manageorder_clicked(); break;
        case 13: _t->on_save_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MyMarket::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_MyMarket.offsetsAndSize,
    qt_meta_data_MyMarket,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MyMarket_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MyMarket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyMarket::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyMarket.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int MyMarket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
