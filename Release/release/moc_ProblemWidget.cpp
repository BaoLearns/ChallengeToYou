/****************************************************************************
** Meta object code from reading C++ file 'ProblemWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ProblemWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ProblemWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ProblemWidget_t {
    QByteArrayData data[7];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProblemWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProblemWidget_t qt_meta_stringdata_ProblemWidget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ProblemWidget"
QT_MOC_LITERAL(1, 14, 12), // "signalCommit"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 19), // "slotClickedPrevious"
QT_MOC_LITERAL(4, 48, 15), // "slotClickedNext"
QT_MOC_LITERAL(5, 64, 17), // "slotClickedCommit"
QT_MOC_LITERAL(6, 82, 15) // "slotTimerUpDate"

    },
    "ProblemWidget\0signalCommit\0\0"
    "slotClickedPrevious\0slotClickedNext\0"
    "slotClickedCommit\0slotTimerUpDate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProblemWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   42,    2, 0x0a /* Public */,
       4,    0,   43,    2, 0x0a /* Public */,
       5,    0,   44,    2, 0x0a /* Public */,
       6,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ProblemWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ProblemWidget *_t = static_cast<ProblemWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalCommit((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->slotClickedPrevious(); break;
        case 2: _t->slotClickedNext(); break;
        case 3: _t->slotClickedCommit(); break;
        case 4: _t->slotTimerUpDate(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ProblemWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProblemWidget::signalCommit)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ProblemWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ProblemWidget.data,
      qt_meta_data_ProblemWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ProblemWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProblemWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ProblemWidget.stringdata0))
        return static_cast<void*>(const_cast< ProblemWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ProblemWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ProblemWidget::signalCommit(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
