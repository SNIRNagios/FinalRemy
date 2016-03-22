/****************************************************************************
** Meta object code from reading C++ file 'fen_map.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Superviseur/QSuperviseur/fen_map.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fen_map.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_fen_map_t {
    QByteArrayData data[12];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_fen_map_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_fen_map_t qt_meta_stringdata_fen_map = {
    {
QT_MOC_LITERAL(0, 0, 7), // "fen_map"
QT_MOC_LITERAL(1, 8, 17), // "siteTraiteValider"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 16), // "siteTraiteErreur"
QT_MOC_LITERAL(4, 44, 6), // "alerte"
QT_MOC_LITERAL(5, 51, 13), // "obtenirSocket"
QT_MOC_LITERAL(6, 65, 10), // "Validation"
QT_MOC_LITERAL(7, 76, 6), // "Erreur"
QT_MOC_LITERAL(8, 83, 13), // "Interrogation"
QT_MOC_LITERAL(9, 97, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(10, 119, 13), // "EtatConnexion"
QT_MOC_LITERAL(11, 133, 15) // "EtatDeconnexion"

    },
    "fen_map\0siteTraiteValider\0\0siteTraiteErreur\0"
    "alerte\0obtenirSocket\0Validation\0Erreur\0"
    "Interrogation\0on_pushButton_clicked\0"
    "EtatConnexion\0EtatDeconnexion"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_fen_map[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   66,    2, 0x08 /* Private */,
       5,    1,   67,    2, 0x08 /* Private */,
       6,    0,   70,    2, 0x08 /* Private */,
       7,    0,   71,    2, 0x08 /* Private */,
       8,    0,   72,    2, 0x08 /* Private */,
       9,    0,   73,    2, 0x08 /* Private */,
      10,    0,   74,    2, 0x08 /* Private */,
      11,    0,   75,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void fen_map::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        fen_map *_t = static_cast<fen_map *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->siteTraiteValider(); break;
        case 1: _t->siteTraiteErreur(); break;
        case 2: _t->alerte(); break;
        case 3: _t->obtenirSocket((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->Validation(); break;
        case 5: _t->Erreur(); break;
        case 6: _t->Interrogation(); break;
        case 7: _t->on_pushButton_clicked(); break;
        case 8: _t->EtatConnexion(); break;
        case 9: _t->EtatDeconnexion(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (fen_map::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&fen_map::siteTraiteValider)) {
                *result = 0;
            }
        }
        {
            typedef void (fen_map::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&fen_map::siteTraiteErreur)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject fen_map::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_fen_map.data,
      qt_meta_data_fen_map,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *fen_map::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *fen_map::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_fen_map.stringdata0))
        return static_cast<void*>(const_cast< fen_map*>(this));
    return QDialog::qt_metacast(_clname);
}

int fen_map::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void fen_map::siteTraiteValider()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void fen_map::siteTraiteErreur()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
