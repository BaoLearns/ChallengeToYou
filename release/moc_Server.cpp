/****************************************************************************
** Meta object code from reading C++ file 'Server.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ChallengeToYou/Server.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CTYServer_t {
    QByteArrayData data[3];
    char stringdata0[30];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CTYServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CTYServer_t qt_meta_stringdata_CTYServer = {
    {
QT_MOC_LITERAL(0, 0, 9), // "CTYServer"
QT_MOC_LITERAL(1, 10, 18), // "clientDisconnected"
QT_MOC_LITERAL(2, 29, 0) // ""

    },
    "CTYServer\0clientDisconnected\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CTYServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void CTYServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CTYServer *_t = static_cast<CTYServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clientDisconnected(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CTYServer::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_CTYServer.data,
      qt_meta_data_CTYServer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CTYServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CTYServer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CTYServer.stringdata0))
        return static_cast<void*>(const_cast< CTYServer*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int CTYServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
