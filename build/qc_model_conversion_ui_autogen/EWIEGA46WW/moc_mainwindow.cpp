/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[339];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 21), // "onUploadButtonClicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 21), // "onOutputButtonClicked"
QT_MOC_LITERAL(4, 56, 22), // "onConvertButtonClicked"
QT_MOC_LITERAL(5, 79, 23), // "onQuantizeButtonClicked"
QT_MOC_LITERAL(6, 103, 23), // "onQuantizeChoiceChanged"
QT_MOC_LITERAL(7, 127, 4), // "text"
QT_MOC_LITERAL(8, 132, 21), // "onEncodeChoiceChanged"
QT_MOC_LITERAL(9, 154, 24), // "onUploadDLCButtonClicked"
QT_MOC_LITERAL(10, 179, 24), // "onVisualizeButtonClicked"
QT_MOC_LITERAL(11, 204, 27), // "onUploadEncodeButtonClicked"
QT_MOC_LITERAL(12, 232, 25), // "onResolutionChoiceChanged"
QT_MOC_LITERAL(13, 258, 19), // "executePythonScript"
QT_MOC_LITERAL(14, 278, 10), // "scriptPath"
QT_MOC_LITERAL(15, 289, 9), // "arguments"
QT_MOC_LITERAL(16, 299, 20), // "successMessagePrefix"
QT_MOC_LITERAL(17, 320, 18) // "errorMessagePrefix"

    },
    "MainWindow\0onUploadButtonClicked\0\0"
    "onOutputButtonClicked\0onConvertButtonClicked\0"
    "onQuantizeButtonClicked\0onQuantizeChoiceChanged\0"
    "text\0onEncodeChoiceChanged\0"
    "onUploadDLCButtonClicked\0"
    "onVisualizeButtonClicked\0"
    "onUploadEncodeButtonClicked\0"
    "onResolutionChoiceChanged\0executePythonScript\0"
    "scriptPath\0arguments\0successMessagePrefix\0"
    "errorMessagePrefix"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    1,   73,    2, 0x08 /* Private */,
       8,    1,   76,    2, 0x08 /* Private */,
       9,    0,   79,    2, 0x08 /* Private */,
      10,    0,   80,    2, 0x08 /* Private */,
      11,    0,   81,    2, 0x08 /* Private */,
      12,    1,   82,    2, 0x08 /* Private */,
      13,    4,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList, QMetaType::QString, QMetaType::QString,   14,   15,   16,   17,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onUploadButtonClicked(); break;
        case 1: _t->onOutputButtonClicked(); break;
        case 2: _t->onConvertButtonClicked(); break;
        case 3: _t->onQuantizeButtonClicked(); break;
        case 4: _t->onQuantizeChoiceChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->onEncodeChoiceChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->onUploadDLCButtonClicked(); break;
        case 7: _t->onVisualizeButtonClicked(); break;
        case 8: _t->onUploadEncodeButtonClicked(); break;
        case 9: _t->onResolutionChoiceChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->executePythonScript((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
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
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
