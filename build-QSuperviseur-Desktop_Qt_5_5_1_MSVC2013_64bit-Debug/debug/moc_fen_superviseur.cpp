/****************************************************************************
** Meta object code from reading C++ file 'fen_superviseur.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Superviseur/QSuperviseur/fen_superviseur.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fen_superviseur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_fen_superviseur_t {
    QByteArrayData data[16];
    char stringdata0[297];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_fen_superviseur_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_fen_superviseur_t qt_meta_stringdata_fen_superviseur = {
    {
QT_MOC_LITERAL(0, 0, 15), // "fen_superviseur"
QT_MOC_LITERAL(1, 16, 13), // "obtenirSocket"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 23), // "on_BTN_getHosts_clicked"
QT_MOC_LITERAL(4, 55, 26), // "on_BTN_getServices_clicked"
QT_MOC_LITERAL(5, 82, 24), // "on_BTN_Connexion_clicked"
QT_MOC_LITERAL(6, 107, 26), // "on_BTN_Deconnexion_clicked"
QT_MOC_LITERAL(7, 134, 21), // "on_toolButton_clicked"
QT_MOC_LITERAL(8, 156, 13), // "interrogation"
QT_MOC_LITERAL(9, 170, 19), // "analyseProblemeHote"
QT_MOC_LITERAL(10, 190, 5), // "ligne"
QT_MOC_LITERAL(11, 196, 7), // "colonne"
QT_MOC_LITERAL(12, 204, 22), // "analyseProblemeService"
QT_MOC_LITERAL(13, 227, 20), // "on_BTN_Timer_clicked"
QT_MOC_LITERAL(14, 248, 24), // "on_BTN_StopTimer_clicked"
QT_MOC_LITERAL(15, 273, 23) // "on_toolButton_2_clicked"

    },
    "fen_superviseur\0obtenirSocket\0\0"
    "on_BTN_getHosts_clicked\0"
    "on_BTN_getServices_clicked\0"
    "on_BTN_Connexion_clicked\0"
    "on_BTN_Deconnexion_clicked\0"
    "on_toolButton_clicked\0interrogation\0"
    "analyseProblemeHote\0ligne\0colonne\0"
    "analyseProblemeService\0on_BTN_Timer_clicked\0"
    "on_BTN_StopTimer_clicked\0"
    "on_toolButton_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_fen_superviseur[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x08 /* Private */,
       3,    0,   77,    2, 0x08 /* Private */,
       4,    0,   78,    2, 0x08 /* Private */,
       5,    0,   79,    2, 0x08 /* Private */,
       6,    0,   80,    2, 0x08 /* Private */,
       7,    0,   81,    2, 0x08 /* Private */,
       8,    0,   82,    2, 0x08 /* Private */,
       9,    2,   83,    2, 0x08 /* Private */,
      12,    2,   88,    2, 0x08 /* Private */,
      13,    0,   93,    2, 0x08 /* Private */,
      14,    0,   94,    2, 0x08 /* Private */,
      15,    0,   95,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::QString, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void fen_superviseur::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        fen_superviseur *_t = static_cast<fen_superviseur *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QString _r = _t->obtenirSocket((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 1: _t->on_BTN_getHosts_clicked(); break;
        case 2: _t->on_BTN_getServices_clicked(); break;
        case 3: _t->on_BTN_Connexion_clicked(); break;
        case 4: _t->on_BTN_Deconnexion_clicked(); break;
        case 5: _t->on_toolButton_clicked(); break;
        case 6: _t->interrogation(); break;
        case 7: _t->analyseProblemeHote((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->analyseProblemeService((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->on_BTN_Timer_clicked(); break;
        case 10: _t->on_BTN_StopTimer_clicked(); break;
        case 11: _t->on_toolButton_2_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject fen_superviseur::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_fen_superviseur.data,
      qt_meta_data_fen_superviseur,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *fen_superviseur::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *fen_superviseur::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_fen_superviseur.stringdata0))
        return static_cast<void*>(const_cast< fen_superviseur*>(this));
    return QDialog::qt_metacast(_clname);
}

int fen_superviseur::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
