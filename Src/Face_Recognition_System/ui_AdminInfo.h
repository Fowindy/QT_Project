/********************************************************************************
** Form generated from reading UI file 'AdminInfo.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMININFO_H
#define UI_ADMININFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminInfo
{
public:

    void setupUi(QWidget *AdminInfo)
    {
        if (AdminInfo->objectName().isEmpty())
            AdminInfo->setObjectName(QString::fromUtf8("AdminInfo"));
        AdminInfo->resize(551, 483);

        retranslateUi(AdminInfo);

        QMetaObject::connectSlotsByName(AdminInfo);
    } // setupUi

    void retranslateUi(QWidget *AdminInfo)
    {
        AdminInfo->setWindowTitle(QCoreApplication::translate("AdminInfo", "AdminInfo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminInfo: public Ui_AdminInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMININFO_H
