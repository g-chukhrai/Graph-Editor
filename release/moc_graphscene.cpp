/****************************************************************************
** Meta object code from reading C++ file 'graphscene.h'
**
** Created: Mon 3. May 17:58:59 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../graphscene.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphscene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GraphScene[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      39,   11,   11,   11, 0x05,
      62,   11,   11,   11, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_GraphScene[] = {
    "GraphScene\0\0addVertexImMatrix(Vertex*)\0"
    "addEdgeInMatrix(Edge*)\0setMoveMode()\0"
};

const QMetaObject GraphScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_GraphScene,
      qt_meta_data_GraphScene, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GraphScene::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GraphScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GraphScene::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GraphScene))
        return static_cast<void*>(const_cast< GraphScene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int GraphScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: addVertexImMatrix((*reinterpret_cast< Vertex*(*)>(_a[1]))); break;
        case 1: addEdgeInMatrix((*reinterpret_cast< Edge*(*)>(_a[1]))); break;
        case 2: setMoveMode(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void GraphScene::addVertexImMatrix(Vertex * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GraphScene::addEdgeInMatrix(Edge * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GraphScene::setMoveMode()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
