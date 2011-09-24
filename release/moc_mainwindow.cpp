/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Mon 3. May 17:59:00 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      54,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      25,   11,   11,   11, 0x08,
      40,   11,   11,   11, 0x08,
      48,   11,   11,   11, 0x08,
      62,   11,   11,   11, 0x08,
      71,   11,   11,   11, 0x08,
      81,   11,   11,   11, 0x08,
     100,   94,   11,   11, 0x08,
     132,  127,   11,   11, 0x08,
     162,   11,   11,   11, 0x08,
     189,   11,   11,   11, 0x08,
     212,   11,   11,   11, 0x08,
     227,   11,   11,   11, 0x08,
     237,   11,   11,   11, 0x08,
     244,   11,   11,   11, 0x08,
     253,   11,   11,   11, 0x08,
     267,   11,   11,   11, 0x08,
     281,   11,   11,   11, 0x08,
     307,  298,   11,   11, 0x08,
     331,   11,   11,   11, 0x08,
     347,   11,   11,   11, 0x08,
     360,   11,   11,   11, 0x08,
     372,   11,   11,   11, 0x08,
     391,   11,   11,   11, 0x08,
     417,  415,   11,   11, 0x08,
     437,   11,   11,   11, 0x08,
     460,   11,  449,   11, 0x08,
     481,   11,   11,   11, 0x08,
     516,   11,   11,   11, 0x08,
     528,   11,   11,   11, 0x08,
     545,   11,   11,   11, 0x08,
     565,   11,   11,   11, 0x08,
     579,   11,   11,   11, 0x08,
     588,   11,   11,   11, 0x08,
     600,   11,   11,   11, 0x08,
     608,   11,   11,   11, 0x08,
     619,   11,   11,   11, 0x08,
     635,   11,   11,   11, 0x08,
     647,   11,   11,   11, 0x08,
     661,   11,   11,   11, 0x08,
     675,   11,   11,   11, 0x08,
     689,   11,   11,   11, 0x08,
     700,   11,   11,   11, 0x08,
     711,   11,   11,   11, 0x08,
     723,   11,   11,   11, 0x08,
     735,   11,   11,   11, 0x08,
     748,   11,   11,   11, 0x08,
     758,   11,   11,   11, 0x08,
     785,  415,   11,   11, 0x08,
     813,   11,   11,   11, 0x08,
     827,   11,   11,   11, 0x08,
     848,  846,   11,   11, 0x08,
     871,  415,   11,   11, 0x08,
     896,   11,  892,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0deleteItem()\0arrowReverse()\0"
    "about()\0exportImage()\0addArc()\0addEdge()\0"
    "clearScene()\0scale\0sceneScaleChanged(QString)\0"
    "path\0gamiltonComboChanged(QString)\0"
    "addVertexImMatrix(Vertex*)\0"
    "addEdgeInMatrix(Edge*)\0findGamilton()\0"
    "newFile()\0save()\0saveAs()\0load(QString)\0"
    "getFileName()\0openRecentFile()\0fileName\0"
    "setCurrentFile(QString)\0setMatrixSize()\0"
    "buildGraph()\0filePrint()\0filePrintPreview()\0"
    "printPreview(QPrinter*)\0,\0cellChange(int,int)\0"
    "subClosed()\0SubWindow*\0createGraphicsView()\0"
    "setActiveSubWindow(QMdiSubWindow*)\0"
    "saveInTxt()\0tileSubWindows()\0"
    "cascadeSubWindows()\0rangChanged()\0"
    "algMet()\0algMetUpg()\0algRF()\0algRFUpg()\0"
    "algMultiChain()\0selectAll()\0setMoveMode()\0"
    "closeAllSub()\0startVisual()\0prevStep()\0"
    "nextStep()\0startStep()\0pauseStep()\0"
    "repeatStep()\0timeout()\0"
    "finish(QList<QStringList>)\0"
    "pathUpdate(QStringList,int)\0clearResult()\0"
    "updateWindowMenu()\0w\0setActiveSub(QWidget*)\0"
    "cellClicked(int,int)\0int\0getCountEdges(int)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: deleteItem(); break;
        case 1: arrowReverse(); break;
        case 2: about(); break;
        case 3: exportImage(); break;
        case 4: addArc(); break;
        case 5: addEdge(); break;
        case 6: clearScene(); break;
        case 7: sceneScaleChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: gamiltonComboChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: addVertexImMatrix((*reinterpret_cast< Vertex*(*)>(_a[1]))); break;
        case 10: addEdgeInMatrix((*reinterpret_cast< Edge*(*)>(_a[1]))); break;
        case 11: findGamilton(); break;
        case 12: newFile(); break;
        case 13: save(); break;
        case 14: saveAs(); break;
        case 15: load((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: getFileName(); break;
        case 17: openRecentFile(); break;
        case 18: setCurrentFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 19: setMatrixSize(); break;
        case 20: buildGraph(); break;
        case 21: filePrint(); break;
        case 22: filePrintPreview(); break;
        case 23: printPreview((*reinterpret_cast< QPrinter*(*)>(_a[1]))); break;
        case 24: cellChange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 25: subClosed(); break;
        case 26: { SubWindow* _r = createGraphicsView();
            if (_a[0]) *reinterpret_cast< SubWindow**>(_a[0]) = _r; }  break;
        case 27: setActiveSubWindow((*reinterpret_cast< QMdiSubWindow*(*)>(_a[1]))); break;
        case 28: saveInTxt(); break;
        case 29: tileSubWindows(); break;
        case 30: cascadeSubWindows(); break;
        case 31: rangChanged(); break;
        case 32: algMet(); break;
        case 33: algMetUpg(); break;
        case 34: algRF(); break;
        case 35: algRFUpg(); break;
        case 36: algMultiChain(); break;
        case 37: selectAll(); break;
        case 38: setMoveMode(); break;
        case 39: closeAllSub(); break;
        case 40: startVisual(); break;
        case 41: prevStep(); break;
        case 42: nextStep(); break;
        case 43: startStep(); break;
        case 44: pauseStep(); break;
        case 45: repeatStep(); break;
        case 46: timeout(); break;
        case 47: finish((*reinterpret_cast< QList<QStringList>(*)>(_a[1]))); break;
        case 48: pathUpdate((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 49: clearResult(); break;
        case 50: updateWindowMenu(); break;
        case 51: setActiveSub((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 52: cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 53: { int _r = getCountEdges((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 54;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
