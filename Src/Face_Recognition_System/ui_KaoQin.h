/********************************************************************************
** Form generated from reading UI file 'KaoQin.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KAOQIN_H
#define UI_KAOQIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KaoQin
{
public:

    void setupUi(QWidget *KaoQin)
    {
        if (KaoQin->objectName().isEmpty())
            KaoQin->setObjectName(QString::fromUtf8("KaoQin"));
        KaoQin->resize(400, 300);

        retranslateUi(KaoQin);

        QMetaObject::connectSlotsByName(KaoQin);
    } // setupUi

    void retranslateUi(QWidget *KaoQin)
    {
        KaoQin->setWindowTitle(QCoreApplication::translate("KaoQin", "KaoQin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KaoQin: public Ui_KaoQin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KAOQIN_H
