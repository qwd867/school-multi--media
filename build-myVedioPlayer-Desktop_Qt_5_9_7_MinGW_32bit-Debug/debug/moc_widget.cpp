/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../myVedioPlayer/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[17];
    char stringdata0[382];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 32), // "on_pushButton_start_puse_clicked"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 26), // "on_pushButton_stop_clicked"
QT_MOC_LITERAL(4, 68, 25), // "on_pushButton_pre_clicked"
QT_MOC_LITERAL(5, 94, 26), // "on_pushButton_next_clicked"
QT_MOC_LITERAL(6, 121, 26), // "on_pushButton_open_clicked"
QT_MOC_LITERAL(7, 148, 29), // "on_hSlider_voice_valueChanged"
QT_MOC_LITERAL(8, 178, 5), // "value"
QT_MOC_LITERAL(9, 184, 34), // "on_hSlider_progressBar_slider..."
QT_MOC_LITERAL(10, 219, 8), // "position"
QT_MOC_LITERAL(11, 228, 31), // "on_pushButton_playorder_clicked"
QT_MOC_LITERAL(12, 260, 33), // "on_pushButton_voicestates_cli..."
QT_MOC_LITERAL(13, 294, 32), // "on_pushButton_fullscreen_clicked"
QT_MOC_LITERAL(14, 327, 14), // "onItemDBCliked"
QT_MOC_LITERAL(15, 342, 5), // "index"
QT_MOC_LITERAL(16, 348, 33) // "on_pushButton_screenshots_cli..."

    },
    "Widget\0on_pushButton_start_puse_clicked\0"
    "\0on_pushButton_stop_clicked\0"
    "on_pushButton_pre_clicked\0"
    "on_pushButton_next_clicked\0"
    "on_pushButton_open_clicked\0"
    "on_hSlider_voice_valueChanged\0value\0"
    "on_hSlider_progressBar_sliderMoved\0"
    "position\0on_pushButton_playorder_clicked\0"
    "on_pushButton_voicestates_clicked\0"
    "on_pushButton_fullscreen_clicked\0"
    "onItemDBCliked\0index\0"
    "on_pushButton_screenshots_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

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
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    1,   79,    2, 0x08 /* Private */,
       9,    1,   82,    2, 0x08 /* Private */,
      11,    0,   85,    2, 0x08 /* Private */,
      12,    0,   86,    2, 0x08 /* Private */,
      13,    0,   87,    2, 0x08 /* Private */,
      14,    1,   88,    2, 0x08 /* Private */,
      16,    0,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   15,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Widget *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_start_puse_clicked(); break;
        case 1: _t->on_pushButton_stop_clicked(); break;
        case 2: _t->on_pushButton_pre_clicked(); break;
        case 3: _t->on_pushButton_next_clicked(); break;
        case 4: _t->on_pushButton_open_clicked(); break;
        case 5: _t->on_hSlider_voice_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_hSlider_progressBar_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_pushButton_playorder_clicked(); break;
        case 8: _t->on_pushButton_voicestates_clicked(); break;
        case 9: _t->on_pushButton_fullscreen_clicked(); break;
        case 10: _t->onItemDBCliked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 11: _t->on_pushButton_screenshots_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget.data,
      qt_meta_data_Widget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
