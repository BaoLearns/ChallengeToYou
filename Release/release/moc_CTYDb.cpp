/****************************************************************************
** Meta object code from reading C++ file 'CTYDb.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CTYDb.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CTYDb.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CTYDb_t {
    QByteArrayData data[5];
    char stringdata0[60];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CTYDb_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CTYDb_t qt_meta_stringdata_CTYDb = {
    {
QT_MOC_LITERAL(0, 0, 5), // "CTYDb"
QT_MOC_LITERAL(1, 6, 18), // "signalMatchSuccess"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 15), // "signalMatchFail"
QT_MOC_LITERAL(4, 42, 17) // "signalContestDone"

    },
    "CTYDb\0signalMatchSuccess\0\0signalMatchFail\0"
    "signalContestDone"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CTYDb[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       3,    1,   32,    2, 0x06 /* Public */,
       4,    0,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

       0        // eod
};

void CTYDb::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CTYDb *_t = static_cast<CTYDb *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalMatchSuccess((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->signalMatchFail((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->signalContestDone(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CTYDb::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CTYDb::signalMatchSuccess)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CTYDb::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CTYDb::signalMatchFail)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CTYDb::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CTYDb::signalContestDone)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject CTYDb::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CTYDb.data,
      qt_meta_data_CTYDb,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CTYDb::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CTYDb::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CTYDb.stringdata0))
        return static_cast<void*>(const_cast< CTYDb*>(this));
    return QObject::qt_metacast(_clname);
}

int CTYDb::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void CTYDb::signalMatchSuccess(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CTYDb::signalMatchFail(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CTYDb::signalContestDone()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
