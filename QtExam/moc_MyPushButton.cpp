/****************************************************************************
** Meta object code from reading C++ file 'MyPushButton.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MyPushButton.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyPushButton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyPushButton[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   14,   13,   13, 0x05,
      35,   14,   13,   13, 0x05,
      55,   14,   13,   13, 0x05,
      77,   14,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
     100,   13,   13,   13, 0x0a,
     116,  113,   13,   13, 0x0a,
     135,  132,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyPushButton[] = {
    "MyPushButton\0\0n\0placesLliures(int)\0"
    "placesOcupades(int)\0placesLliuresIni(int)\0"
    "placesOcupadesIni(int)\0actualitza()\0"
    "ll\0cogerNumLl(int)\0oc\0cogerNumOc(int)\0"
};

void MyPushButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyPushButton *_t = static_cast<MyPushButton *>(_o);
        switch (_id) {
        case 0: _t->placesLliures((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->placesOcupades((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->placesLliuresIni((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->placesOcupadesIni((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->actualitza(); break;
        case 5: _t->cogerNumLl((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->cogerNumOc((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MyPushButton::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyPushButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_MyPushButton,
      qt_meta_data_MyPushButton, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyPushButton::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyPushButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyPushButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyPushButton))
        return static_cast<void*>(const_cast< MyPushButton*>(this));
    return QPushButton::qt_metacast(_clname);
}

int MyPushButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void MyPushButton::placesLliures(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyPushButton::placesOcupades(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyPushButton::placesLliuresIni(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyPushButton::placesOcupadesIni(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
