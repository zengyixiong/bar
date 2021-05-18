/****************************************************************************
** Meta object code from reading C++ file 'socketModule.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../socketModule.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'socketModule.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_socketModule_t {
    QByteArrayData data[26];
    char stringdata0[334];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_socketModule_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_socketModule_t qt_meta_stringdata_socketModule = {
    {
QT_MOC_LITERAL(0, 0, 12), // "socketModule"
QT_MOC_LITERAL(1, 13, 17), // "signal_newConnect"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 17), // "signal_disconnect"
QT_MOC_LITERAL(4, 50, 21), // "signal_receiveDataAll"
QT_MOC_LITERAL(5, 72, 11), // "signal_beat"
QT_MOC_LITERAL(6, 84, 16), // "signal_checkBars"
QT_MOC_LITERAL(7, 101, 9), // "barsInfor"
QT_MOC_LITERAL(8, 111, 5), // "infor"
QT_MOC_LITERAL(9, 117, 16), // "signal_checkWeld"
QT_MOC_LITERAL(10, 134, 3), // "pos"
QT_MOC_LITERAL(11, 138, 13), // "signal_dataIn"
QT_MOC_LITERAL(12, 152, 3), // "str"
QT_MOC_LITERAL(13, 156, 4), // "type"
QT_MOC_LITERAL(14, 161, 13), // "slot_sendData"
QT_MOC_LITERAL(15, 175, 8), // "barsData"
QT_MOC_LITERAL(16, 184, 4), // "data"
QT_MOC_LITERAL(17, 189, 16), // "slot_sendWeldRet"
QT_MOC_LITERAL(18, 206, 13), // "QVector<bool>"
QT_MOC_LITERAL(19, 220, 3), // "ret"
QT_MOC_LITERAL(20, 224, 17), // "slot_sendData_new"
QT_MOC_LITERAL(21, 242, 20), // "slot_sendWeldRet_new"
QT_MOC_LITERAL(22, 263, 14), // "slot_newClient"
QT_MOC_LITERAL(23, 278, 16), // "slot_receiveData"
QT_MOC_LITERAL(24, 295, 17), // "slot_disconnected"
QT_MOC_LITERAL(25, 313, 20) // "slot_receiveData_new"

    },
    "socketModule\0signal_newConnect\0\0"
    "signal_disconnect\0signal_receiveDataAll\0"
    "signal_beat\0signal_checkBars\0barsInfor\0"
    "infor\0signal_checkWeld\0pos\0signal_dataIn\0"
    "str\0type\0slot_sendData\0barsData\0data\0"
    "slot_sendWeldRet\0QVector<bool>\0ret\0"
    "slot_sendData_new\0slot_sendWeldRet_new\0"
    "slot_newClient\0slot_receiveData\0"
    "slot_disconnected\0slot_receiveData_new"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_socketModule[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,
       4,    1,   91,    2, 0x06 /* Public */,
       5,    0,   94,    2, 0x06 /* Public */,
       6,    1,   95,    2, 0x06 /* Public */,
       9,    1,   98,    2, 0x06 /* Public */,
      11,    2,  101,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    1,  106,    2, 0x0a /* Public */,
      17,    1,  109,    2, 0x0a /* Public */,
      20,    2,  112,    2, 0x0a /* Public */,
      21,    1,  117,    2, 0x0a /* Public */,
      22,    0,  120,    2, 0x08 /* Private */,
      23,    0,  121,    2, 0x08 /* Private */,
      24,    0,  122,    2, 0x08 /* Private */,
      25,    0,  123,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   12,   13,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, 0x80000000 | 15, 0x80000000 | 18,   16,   19,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void socketModule::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        socketModule *_t = static_cast<socketModule *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_newConnect(); break;
        case 1: _t->signal_disconnect(); break;
        case 2: _t->signal_receiveDataAll((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->signal_beat(); break;
        case 4: _t->signal_checkBars((*reinterpret_cast< barsInfor(*)>(_a[1]))); break;
        case 5: _t->signal_checkWeld((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->signal_dataIn((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->slot_sendData((*reinterpret_cast< barsData(*)>(_a[1]))); break;
        case 8: _t->slot_sendWeldRet((*reinterpret_cast< QVector<bool>(*)>(_a[1]))); break;
        case 9: _t->slot_sendData_new((*reinterpret_cast< barsData(*)>(_a[1])),(*reinterpret_cast< QVector<bool>(*)>(_a[2]))); break;
        case 10: _t->slot_sendWeldRet_new((*reinterpret_cast< QVector<bool>(*)>(_a[1]))); break;
        case 11: _t->slot_newClient(); break;
        case 12: _t->slot_receiveData(); break;
        case 13: _t->slot_disconnected(); break;
        case 14: _t->slot_receiveData_new(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<bool> >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<bool> >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<bool> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (socketModule::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&socketModule::signal_newConnect)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (socketModule::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&socketModule::signal_disconnect)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (socketModule::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&socketModule::signal_receiveDataAll)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (socketModule::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&socketModule::signal_beat)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (socketModule::*_t)(barsInfor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&socketModule::signal_checkBars)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (socketModule::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&socketModule::signal_checkWeld)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (socketModule::*_t)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&socketModule::signal_dataIn)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject socketModule::staticMetaObject = {
    { &IServer::staticMetaObject, qt_meta_stringdata_socketModule.data,
      qt_meta_data_socketModule,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *socketModule::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *socketModule::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_socketModule.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "ModuleBase"))
        return static_cast< ModuleBase*>(this);
    return IServer::qt_metacast(_clname);
}

int socketModule::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void socketModule::signal_newConnect()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void socketModule::signal_disconnect()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void socketModule::signal_receiveDataAll(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void socketModule::signal_beat()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void socketModule::signal_checkBars(barsInfor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void socketModule::signal_checkWeld(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void socketModule::signal_dataIn(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
