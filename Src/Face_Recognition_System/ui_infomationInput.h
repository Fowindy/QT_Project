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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_infomationInput
{
public:
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *info_Name;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *info_Id;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *info_Department;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *info_Post;
    QListWidget *listWidget;
    QPushButton *btnSure;
    QPushButton *btnReturn;

    void setupUi(QWidget *infomationInput)
    {
        if (infomationInput->objectName().isEmpty())
            infomationInput->setObjectName(QString::fromUtf8("infomationInput"));
        infomationInput->resize(650, 374);
        widget = new QWidget(infomationInput);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 20, 601, 331));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        info_Name = new QLineEdit(widget);
        info_Name->setObjectName(QString::fromUtf8("info_Name"));

        horizontalLayout->addWidget(info_Name);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        info_Id = new QLineEdit(widget);
        info_Id->setObjectName(QString::fromUtf8("info_Id"));

        horizontalLayout_2->addWidget(info_Id);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        info_Department = new QLineEdit(widget);
        info_Department->setObjectName(QString::fromUtf8("info_Department"));

        horizontalLayout_3->addWidget(info_Department);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        info_Post = new QLineEdit(widget);
        info_Post->setObjectName(QString::fromUtf8("info_Post"));

        horizontalLayout_4->addWidget(info_Post);


        gridLayout->addLayout(horizontalLayout_4, 3, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        listWidget = new QListWidget(widget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout_2->addWidget(listWidget, 0, 1, 3, 1);

        btnSure = new QPushButton(widget);
        btnSure->setObjectName(QString::fromUtf8("btnSure"));

        gridLayout_2->addWidget(btnSure, 1, 0, 1, 1);

        btnReturn = new QPushButton(widget);
        btnReturn->setObjectName(QString::fromUtf8("btnReturn"));

        gridLayout_2->addWidget(btnReturn, 2, 0, 1, 1);


        retranslateUi(infomationInput);

        QMetaObject::connectSlotsByName(infomationInput);
    } // setupUi

    void retranslateUi(QWidget *infomationInput)
    {
        infomationInput->setWindowTitle(QCoreApplication::translate("infomationInput", "\344\277\241\346\201\257\345\275\225\345\205\245", nullptr));
        label->setText(QCoreApplication::translate("infomationInput", "\345\247\223\345\220\215:", nullptr));
        label_2->setText(QCoreApplication::translate("infomationInput", "\345\267\245\345\217\267:", nullptr));
        label_3->setText(QCoreApplication::translate("infomationInput", "\351\203\250\351\227\250:", nullptr));
        label_4->setText(QCoreApplication::translate("infomationInput", "\350\201\214\344\275\215:", nullptr));
        btnSure->setText(QCoreApplication::translate("infomationInput", "\347\241\256\350\256\244\346\217\220\344\272\244", nullptr));
        btnReturn->setText(QCoreApplication::translate("infomationInput", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class infomationInput: public Ui_infomationInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOMATIONINPUT_H
