/****************************************************************************
** Meta object code from reading C++ file 'UserWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../UserWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UserWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UserWidget_t {
    QByteArrayData data[9];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserWidget_t qt_meta_stringdata_UserWidget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "UserWidget"
QT_MOC_LITERAL(1, 11, 11), // "signalStart"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 12), // "signalLogout"
QT_MOC_LITERAL(4, 37, 16), // "slotClickedStart"
QT_MOC_LITERAL(5, 54, 16), // "slotMatchSuccess"
QT_MOC_LITERAL(6, 71, 13), // "slotMatchFail"
QT_MOC_LITERAL(7, 85, 10), // "slotLogout"
QT_MOC_LITERAL(8, 96, 11) // "slotTimeout"

    },
    "UserWidget\0signalStart\0\0signalLogout\0"
    "slotClickedStart\0slotMatchSuccess\0"
    "slotMatchFail\0slotLogout\0slotTimeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   51,    2, 0x08 /* Private */,
       5,    1,   52,    2, 0x08 /* Private */,
       6,    1,   55,    2, 0x08 /* Private */,
       7,    0,   58,    2, 0x08 /* Private */,
       8,    0,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UserWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UserWidget *_t = static_cast<UserWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalStart(); break;
        case 1: _t->signalLogout(); break;
        case 2: _t->slotClickedStart(); break;
        case 3: _t->slotMatchSuccess((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->slotMatchFail((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->slotLogout(); break;
        case 6: _t->slotTimeout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UserWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UserWidget::signalStart)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (UserWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UserWidget::signalLogout)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject UserWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_UserWidget.data,
      qt_meta_data_UserWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UserWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UserWidget.stringdata0))
        return static_cast<void*>(const_cast< UserWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int UserWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void UserWidget::signalStart()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void UserWidget::signalLogout()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
