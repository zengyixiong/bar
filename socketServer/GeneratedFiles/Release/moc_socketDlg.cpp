/****************************************************************************
** Meta object code from reading C++ file 'socketDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../socketDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'socketDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_socketDlg_t {
    QByteArrayData data[13];
    char stringdata0[228];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_socketDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_socketDlg_t qt_meta_stringdata_socketDlg = {
    {
QT_MOC_LITERAL(0, 0, 9), // "socketDlg"
QT_MOC_LITERAL(1, 10, 28), // "on_pushButton_listen_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 26), // "on_pushButton_send_clicked"
QT_MOC_LITERAL(4, 67, 19), // "slot_receiveDataAll"
QT_MOC_LITERAL(5, 87, 4), // "data"
QT_MOC_LITERAL(6, 92, 15), // "slot_newConnect"
QT_MOC_LITERAL(7, 108, 15), // "slot_disconnect"
QT_MOC_LITERAL(8, 124, 9), // "slot_beat"
QT_MOC_LITERAL(9, 134, 29), // "on_pushButton_Connect_clicked"
QT_MOC_LITERAL(10, 164, 26), // "on_pushButton_Send_clicked"
QT_MOC_LITERAL(11, 191, 16), // "socket_Read_Data"
QT_MOC_LITERAL(12, 208, 19) // "socket_Disconnected"

    },
    "socketDlg\0on_pushButton_listen_clicked\0"
    "\0on_pushButton_send_clicked\0"
    "slot_receiveDataAll\0data\0slot_newConnect\0"
    "slot_disconnect\0slot_beat\0"
    "on_pushButton_Connect_clicked\0"
    "on_pushButton_Send_clicked\0socket_Read_Data\0"
    "socket_Disconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_socketDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    1,   66,    2, 0x08 /* Private */,
       6,    0,   69,    2, 0x08 /* Private */,
       7,    0,   70,    2, 0x08 /* Private */,
       8,    0,   71,    2, 0x08 /* Private */,
       9,    0,   72,    2, 0x08 /* Private */,
      10,    0,   73,    2, 0x08 /* Private */,
      11,    0,   74,    2, 0x08 /* Private */,
      12,    0,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void socketDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        socketDlg *_t = static_cast<socketDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_listen_clicked(); break;
        case 1: _t->on_pushButton_send_clicked(); break;
        case 2: _t->slot_receiveDataAll((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->slot_newConnect(); break;
        case 4: _t->slot_disconnect(); break;
        case 5: _t->slot_beat(); break;
        case 6: _t->on_pushButton_Connect_clicked(); break;
        case 7: _t->on_pushButton_Send_clicked(); break;
        case 8: _t->socket_Read_Data(); break;
        case 9: _t->socket_Disconnected(); break;
        default: ;
        }
    }
}

const QMetaObject socketDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_socketDlg.data,
      qt_meta_data_socketDlg,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *socketDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *socketDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_socketDlg.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int socketDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
