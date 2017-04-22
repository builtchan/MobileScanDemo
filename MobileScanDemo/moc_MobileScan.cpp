/****************************************************************************
** Meta object code from reading C++ file 'MobileScan.h'
**
** Created: Sat Apr 22 17:02:24 2017
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MobileScan.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MobileScan.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CMobileScan[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      38,   12,   12,   12, 0x0a,
      60,   12,   12,   12, 0x0a,
      85,   12,   12,   12, 0x0a,
     113,   12,   12,   12, 0x0a,
     142,   12,   12,   12, 0x0a,
     167,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CMobileScan[] = {
    "CMobileScan\0\0New_QRCode_has_Created()\0"
    "on_click_Connet_Btn()\0on_click_Disconnet_Btn()\0"
    "on_click_PaymentBegin_Btn()\0"
    "on_click_CancelPayment_Btn()\0"
    "on_click_GetStatus_Btn()\0"
    "create_QRCode_and_Show()\0"
};

const QMetaObject CMobileScan::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CMobileScan,
      qt_meta_data_CMobileScan, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CMobileScan::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CMobileScan::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CMobileScan::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CMobileScan))
        return static_cast<void*>(const_cast< CMobileScan*>(this));
    if (!strcmp(_clname, "CIWebPayEvenHandler"))
        return static_cast< CIWebPayEvenHandler*>(const_cast< CMobileScan*>(this));
    return QWidget::qt_metacast(_clname);
}

int CMobileScan::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: New_QRCode_has_Created(); break;
        case 1: on_click_Connet_Btn(); break;
        case 2: on_click_Disconnet_Btn(); break;
        case 3: on_click_PaymentBegin_Btn(); break;
        case 4: on_click_CancelPayment_Btn(); break;
        case 5: on_click_GetStatus_Btn(); break;
        case 6: create_QRCode_and_Show(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void CMobileScan::New_QRCode_has_Created()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
