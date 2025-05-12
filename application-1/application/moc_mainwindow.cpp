/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "dealCards",
    "",
    "updateUI",
    "determineWinner",
    "swapCardsWithDeck",
    "std::vector<int>",
    "indices",
    "showSwapButtons",
    "performSwap",
    "showOpponentCards",
    "hideOpponentCards",
    "performOpponentSwap",
    "swapLowestCard",
    "std::vector<Card>",
    "hand",
    "swapOtherTwoCards",
    "determineOpponentHand",
    "vector<Card>",
    "swapCardsWithDeck_opponent",
    "vector<int>",
    "swapOtherThreeCards"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x08,    1 /* Private */,
       3,    0,   99,    2, 0x08,    2 /* Private */,
       4,    0,  100,    2, 0x08,    3 /* Private */,
       5,    1,  101,    2, 0x08,    4 /* Private */,
       8,    0,  104,    2, 0x08,    6 /* Private */,
       9,    0,  105,    2, 0x08,    7 /* Private */,
      10,    0,  106,    2, 0x08,    8 /* Private */,
      11,    0,  107,    2, 0x08,    9 /* Private */,
      12,    0,  108,    2, 0x08,   10 /* Private */,
      13,    1,  109,    2, 0x08,   11 /* Private */,
      16,    1,  112,    2, 0x08,   13 /* Private */,
      17,    1,  115,    2, 0x08,   15 /* Private */,
      19,    1,  118,    2, 0x08,   17 /* Private */,
      21,    1,  121,    2, 0x08,   19 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Int, 0x80000000 | 18,   15,
    QMetaType::Void, 0x80000000 | 20,    7,
    QMetaType::Void, 0x80000000 | 18,   15,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'dealCards'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateUI'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'determineWinner'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'swapCardsWithDeck'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::vector<int> &, std::false_type>,
        // method 'showSwapButtons'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'performSwap'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showOpponentCards'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'hideOpponentCards'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'performOpponentSwap'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'swapLowestCard'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::vector<Card> &, std::false_type>,
        // method 'swapOtherTwoCards'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::vector<Card> &, std::false_type>,
        // method 'determineOpponentHand'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const vector<Card> &, std::false_type>,
        // method 'swapCardsWithDeck_opponent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const vector<int> &, std::false_type>,
        // method 'swapOtherThreeCards'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const vector<Card> &, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->dealCards(); break;
        case 1: _t->updateUI(); break;
        case 2: _t->determineWinner(); break;
        case 3: _t->swapCardsWithDeck((*reinterpret_cast< std::add_pointer_t<std::vector<int>>>(_a[1]))); break;
        case 4: _t->showSwapButtons(); break;
        case 5: _t->performSwap(); break;
        case 6: _t->showOpponentCards(); break;
        case 7: _t->hideOpponentCards(); break;
        case 8: _t->performOpponentSwap(); break;
        case 9: _t->swapLowestCard((*reinterpret_cast< std::add_pointer_t<std::vector<Card>>>(_a[1]))); break;
        case 10: _t->swapOtherTwoCards((*reinterpret_cast< std::add_pointer_t<std::vector<Card>>>(_a[1]))); break;
        case 11: { int _r = _t->determineOpponentHand((*reinterpret_cast< std::add_pointer_t<vector<Card>>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 12: _t->swapCardsWithDeck_opponent((*reinterpret_cast< std::add_pointer_t<vector<int>>>(_a[1]))); break;
        case 13: _t->swapOtherThreeCards((*reinterpret_cast< std::add_pointer_t<vector<Card>>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
