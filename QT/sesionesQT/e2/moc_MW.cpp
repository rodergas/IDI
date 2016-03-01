/****************************************************************************
** Meta object code from reading C++ file 'MW.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MW.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MW.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MW[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       4,    3,    3,    3, 0x0a,
      12,    3,    3,    3, 0x0a,
      20,    3,    3,    3, 0x0a,
      28,    3,    3,    3, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MW[] = {
    "MW\0\0RC(int)\0GC(int)\0BC(int)\0SET()\0"
};

void MW::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MW *_t = static_cast<MW *>(_o);
        switch (_id) {
        case 0: _t->RC((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->GC((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->BC((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->SET(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MW::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MW::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MW,
      qt_meta_data_MW, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MW::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MW::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MW::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MW))
        return static_cast<void*>(const_cast< MW*>(this));
    return QWidget::qt_metacast(_clname);
}

int MW::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
