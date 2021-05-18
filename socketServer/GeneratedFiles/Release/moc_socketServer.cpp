/****************************************************************************
** Meta object code from reading C++ file 'socketServer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../socketServer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'socketServer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_socketServer_t {
    QByteArrayData data[16];
    char stringdata0[227];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_socketServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_socketServer_t qt_meta_stringdata_socketServer = {
    {
QT_MOC_LITERAL(0, 0, 12), // "socketServer"
QT_MOC_LITERAL(1, 13, 17), // "signal_newConnect"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 17), // "signal_disconnect"
QT_MOC_LITERAL(4, 50, 21), // "signal_receiveDataAll"
QT_MOC_LITERAL(5, 72, 11), // "signal_beat"
QT_MOC_LITERAL(6, 84, 18), // "signal_detectStart"
QT_MOC_LITERAL(7, 103, 17), // "signal_detectStop"
QT_MOC_LITERAL(8, 121, 16), // "signal_caliStart"
QT_MOC_LITERAL(9, 138, 15), // "signal_caliStop"
QT_MOC_LITERAL(10, 154, 13), // "signal_dataIn"
QT_MOC_LITERAL(11, 168, 3), // "str"
QT_MOC_LITERAL(12, 172, 4), // "type"
QT_MOC_LITERAL(13, 177, 14), // "slot_newClient"
QT_MOC_LITERAL(14, 192, 16), // "slot_receiveData"
QT_MOC_LITERAL(15, 209, 17) // "slot_disconnected"

    },
    "socketServer\0signal_newConnect\0\0"
    "signal_disconnect\0signal_receiveDataAll\0"
    "signal_beat\0signal_detectStart\0"
    "signal_detectStop\0signal_caliStart\0"
    "signal_caliStop\0signal_dataIn\0str\0"
    "type\0slot_newClient\0slot_receiveData\0"
    "slot_disconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_socketServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,
       4,    1,   76,    2, 0x06 /* Public */,
       5,    0,   79,    2, 0x06 /* Public */,
       6,    0,   80,    2, 0x06 /* Public */,
       7,    0,   81,    2, 0x06 /* Public */,
       8,    0,   82,    2, 0x06 /* Public */,
       9,    0,   83,    2, 0x06 /* Public */,
      10,    2,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,   89,    2, 0x08 /* Private */,
      14,    0,   90,    2, 0x08 /* Private */,
      15,    0,   91,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   11,   12,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void socketServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        socketServer *_t = static_cast<socketServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_newConnect(); break;
        case 1: _t->signal_disconnect(); break;
        case 2: _t->signal_receiveDataAll((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->signal_beat(); break;
        case 4: _t->signal_detectStart(); break;
        case 5: _t->signal_detectStop(); break;
        case 6: _t->signal_caliStart(); break;
        case 7: _t->signal_caliStop(); break;
        case 8: _t->signal_dataIn((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->slot_newClient(); break;
        case 10: _t->slot_receiveData(); break;
        case 11: _t->slot_disconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (socketServer::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&socketServer::signal_newConnect)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (socketServer::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&socketServer::signal_disconnect)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (socketServer::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&socketServer::signal_receiveDataAll)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (socketServer::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&socketServer::signal_beat)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (socketServer::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&socketServer::signal_detectStart)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (socketServer::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&socketServer::signal_detectStop)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (socketServer::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&socketServer::signal_caliStart)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (socketServer::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&socketServer::signal_caliStop)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (socketServer::*_t)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&socketServer::signal_dataIn)) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject socketServer::staticMetaObject = {
    { &IServer::staticMetaObject, qt_meta_stringdata_socketServer.data,
      qt_meta_data_socketServer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *socketServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *socketServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_socketServer.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "ModuleBase"))
        return static_cast< ModuleBase*>(this);
    return IServer::qt_metacast(_clname);
}

int socketServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void socketServer::signal_newConnect()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void socketServer::signal_disconnect()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void socketServer::signal_receiveDataAll(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void socketServer::signal_beat()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void socketServer::signal_detectStart()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void socketServer::signal_detectStop()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void socketServer::signal_caliStart()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void socketServer::signal_caliStop()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void socketServer::signal_dataIn(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
