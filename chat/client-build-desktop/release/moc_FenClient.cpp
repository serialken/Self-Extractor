/****************************************************************************
** Meta object code from reading C++ file 'FenClient.h'
**
** Created: Tue 21. Jun 12:21:01 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client/FenClient.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FenClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FenClient[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      40,   10,   10,   10, 0x08,
      67,   10,   10,   10, 0x08,
      94,   10,   10,   10, 0x08,
     110,   10,   10,   10, 0x08,
     121,   10,   10,   10, 0x08,
     141,  134,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FenClient[] = {
    "FenClient\0\0on_boutonConnexion_clicked()\0"
    "on_boutonEnvoyer_clicked()\0"
    "on_message_returnPressed()\0donneesRecues()\0"
    "connecte()\0deconnecte()\0erreur\0"
    "erreurSocket(QAbstractSocket::SocketError)\0"
};

const QMetaObject FenClient::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FenClient,
      qt_meta_data_FenClient, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FenClient::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FenClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FenClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FenClient))
        return static_cast<void*>(const_cast< FenClient*>(this));
    return QWidget::qt_metacast(_clname);
}

int FenClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_boutonConnexion_clicked(); break;
        case 1: on_boutonEnvoyer_clicked(); break;
        case 2: on_message_returnPressed(); break;
        case 3: donneesRecues(); break;
        case 4: connecte(); break;
        case 5: deconnecte(); break;
        case 6: erreurSocket((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
