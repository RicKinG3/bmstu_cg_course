/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../MainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[418];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 26), // "on_loadModelButton_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 28), // "on_deleteModelButton_clicked"
QT_MOC_LITERAL(4, 68, 32), // "on_deleteAllModelsButton_clicked"
QT_MOC_LITERAL(5, 101, 27), // "on_loadCameraButton_clicked"
QT_MOC_LITERAL(6, 129, 26), // "on_addCameraButton_clicked"
QT_MOC_LITERAL(7, 156, 29), // "on_deleteCameraButton_clicked"
QT_MOC_LITERAL(8, 186, 26), // "on_moveModelButton_clicked"
QT_MOC_LITERAL(9, 213, 27), // "on_scaleModelButton_clicked"
QT_MOC_LITERAL(10, 241, 28), // "on_rotateModelButton_clicked"
QT_MOC_LITERAL(11, 270, 27), // "on_moveCameraButton_clicked"
QT_MOC_LITERAL(12, 298, 29), // "on_rotateCameraButton_clicked"
QT_MOC_LITERAL(13, 328, 34), // "on_camerasList_currentIndexCh..."
QT_MOC_LITERAL(14, 363, 5), // "index"
QT_MOC_LITERAL(15, 369, 27), // "on_clearSceneButton_clicked"
QT_MOC_LITERAL(16, 397, 20) // "on_add_illum_clicked"

    },
    "MainWindow\0on_loadModelButton_clicked\0"
    "\0on_deleteModelButton_clicked\0"
    "on_deleteAllModelsButton_clicked\0"
    "on_loadCameraButton_clicked\0"
    "on_addCameraButton_clicked\0"
    "on_deleteCameraButton_clicked\0"
    "on_moveModelButton_clicked\0"
    "on_scaleModelButton_clicked\0"
    "on_rotateModelButton_clicked\0"
    "on_moveCameraButton_clicked\0"
    "on_rotateCameraButton_clicked\0"
    "on_camerasList_currentIndexChanged\0"
    "index\0on_clearSceneButton_clicked\0"
    "on_add_illum_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    0,   91,    2, 0x08 /* Private */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    1,   95,    2, 0x08 /* Private */,
      15,    0,   98,    2, 0x08 /* Private */,
      16,    0,   99,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_loadModelButton_clicked(); break;
        case 1: _t->on_deleteModelButton_clicked(); break;
        case 2: _t->on_deleteAllModelsButton_clicked(); break;
        case 3: _t->on_loadCameraButton_clicked(); break;
        case 4: _t->on_addCameraButton_clicked(); break;
        case 5: _t->on_deleteCameraButton_clicked(); break;
        case 6: _t->on_moveModelButton_clicked(); break;
        case 7: _t->on_scaleModelButton_clicked(); break;
        case 8: _t->on_rotateModelButton_clicked(); break;
        case 9: _t->on_moveCameraButton_clicked(); break;
        case 10: _t->on_rotateCameraButton_clicked(); break;
        case 11: _t->on_camerasList_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_clearSceneButton_clicked(); break;
        case 13: _t->on_add_illum_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE