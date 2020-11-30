/********************************************************************************
** Form generated from reading UI file 'infomationInput.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOMATIONINPUT_H
#define UI_INFOMATIONINPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_infomationInput
{
public:

    void setupUi(QWidget *infomationInput)
    {
        if (infomationInput->objectName().isEmpty())
            infomationInput->setObjectName(QString::fromUtf8("infomationInput"));
        infomationInput->resize(400, 300);

        retranslateUi(infomationInput);

        QMetaObject::connectSlotsByName(infomationInput);
    } // setupUi

    void retranslateUi(QWidget *infomationInput)
    {
        infomationInput->setWindowTitle(QCoreApplication::translate("infomationInput", "infomationInput", nullptr));
    } // retranslateUi

};

namespace Ui {
    class infomationInput: public Ui_infomationInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOMATIONINPUT_H
