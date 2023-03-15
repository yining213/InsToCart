/****************************************************************************
** Meta object code from reading C++ file 'managestock.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../InsToCart/managestock.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'managestock.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ManageStock_t {
    const uint offsetsAndSize[34];
    char stringdata0[282];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ManageStock_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ManageStock_t qt_meta_stringdata_ManageStock = {
    {
QT_MOC_LITERAL(0, 11), // "ManageStock"
QT_MOC_LITERAL(12, 21), // "on_addProduct_clicked"
QT_MOC_LITERAL(34, 0), // ""
QT_MOC_LITERAL(35, 17), // "on_update_clicked"
QT_MOC_LITERAL(53, 31), // "on_listWidget_currentRowChanged"
QT_MOC_LITERAL(85, 10), // "currentRow"
QT_MOC_LITERAL(96, 14), // "on_del_clicked"
QT_MOC_LITERAL(111, 31), // "on_listWidget_itemDoubleClicked"
QT_MOC_LITERAL(143, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(160, 4), // "item"
QT_MOC_LITERAL(165, 15), // "on_back_clicked"
QT_MOC_LITERAL(181, 20), // "slotRowDoubleClicked"
QT_MOC_LITERAL(202, 11), // "QModelIndex"
QT_MOC_LITERAL(214, 5), // "index"
QT_MOC_LITERAL(220, 18), // "on_search1_clicked"
QT_MOC_LITERAL(239, 18), // "on_search2_clicked"
QT_MOC_LITERAL(258, 23) // "on_searchType_activated"

    },
    "ManageStock\0on_addProduct_clicked\0\0"
    "on_update_clicked\0on_listWidget_currentRowChanged\0"
    "currentRow\0on_del_clicked\0"
    "on_listWidget_itemDoubleClicked\0"
    "QListWidgetItem*\0item\0on_back_clicked\0"
    "slotRowDoubleClicked\0QModelIndex\0index\0"
    "on_search1_clicked\0on_search2_clicked\0"
    "on_searchType_activated"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ManageStock[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x08,    0 /* Private */,
       3,    0,   75,    2, 0x08,    1 /* Private */,
       4,    1,   76,    2, 0x08,    2 /* Private */,
       6,    0,   79,    2, 0x08,    4 /* Private */,
       7,    1,   80,    2, 0x08,    5 /* Private */,
      10,    0,   83,    2, 0x08,    7 /* Private */,
      11,    1,   84,    2, 0x08,    8 /* Private */,
      14,    0,   87,    2, 0x08,   10 /* Private */,
      15,    0,   88,    2, 0x08,   11 /* Private */,
      16,    1,   89,    2, 0x08,   12 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,

       0        // eod
};

void ManageStock::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ManageStock *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_addProduct_clicked(); break;
        case 1: _t->on_update_clicked(); break;
        case 2: _t->on_listWidget_currentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_del_clicked(); break;
        case 4: _t->on_listWidget_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->on_back_clicked(); break;
        case 6: _t->slotRowDoubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->on_search1_clicked(); break;
        case 8: _t->on_search2_clicked(); break;
        case 9: _t->on_searchType_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ManageStock::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_ManageStock.offsetsAndSize,
    qt_meta_data_ManageStock,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ManageStock_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *ManageStock::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ManageStock::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ManageStock.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ManageStock::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
