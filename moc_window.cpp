/****************************************************************************
** Meta object code from reading C++ file 'window.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "includes/window.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Window[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,   16,   16,   16, 0x08,
      17,   16,   16,   16, 0x08,
      28,   16,   16,   16, 0x08,
      39,   16,   16,   16, 0x08,
      51,   16,   16,   16, 0x08,
      61,   16,   16,   16, 0x08,
      72,   16,   16,   16, 0x08,
      84,   16,   16,   16, 0x08,
      97,   16,   16,   16, 0x08,
     107,   16,   16,   16, 0x08,
     120,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Window[] = {
    "Window\0UpSlot()\0\0DownSlot()\0LeftSlot()\0"
    "RightSlot()\0ZinSlot()\0ZoutSlot()\0"
    "ZinSlot_y()\0ZoutSlot_y()\0NewSlot()\0"
    "DeleteSlot()\0ScreenSlot()\0"
};

void Window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Window *_t = static_cast<Window *>(_o);
        switch (_id) {
        case 0: _t->UpSlot(); break;
        case 1: _t->DownSlot(); break;
        case 2: _t->LeftSlot(); break;
        case 3: _t->RightSlot(); break;
        case 4: _t->ZinSlot(); break;
        case 5: _t->ZoutSlot(); break;
        case 6: _t->ZinSlot_y(); break;
        case 7: _t->ZoutSlot_y(); break;
        case 8: _t->NewSlot(); break;
        case 9: _t->DeleteSlot(); break;
        case 10: _t->ScreenSlot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Window::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Window::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Window,
      qt_meta_data_Window, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Window::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Window::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Window))
        return static_cast<void*>(const_cast< Window*>(this));
    return QWidget::qt_metacast(_clname);
}

int Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
