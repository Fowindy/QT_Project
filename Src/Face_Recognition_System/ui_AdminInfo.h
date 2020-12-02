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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminInfo
{
public:
    QTableWidget *worker;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btnAddWorker;
    QPushButton *btnDelWorker;
    QPushButton *btnRefreshTable;
    QPushButton *btnReturn;

    void setupUi(QWidget *AdminInfo)
    {
        if (AdminInfo->objectName().isEmpty())
            AdminInfo->setObjectName(QString::fromUtf8("AdminInfo"));
        AdminInfo->resize(671, 375);
        worker = new QTableWidget(AdminInfo);
        if (worker->columnCount() < 4)
            worker->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        worker->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        worker->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        worker->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        worker->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (worker->rowCount() < 9)
            worker->setRowCount(9);
        worker->setObjectName(QString::fromUtf8("worker"));
        worker->setGeometry(QRect(10, 10, 451, 321));
        worker->setRowCount(9);
        layoutWidget = new QWidget(AdminInfo);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(480, 10, 181, 321));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btnAddWorker = new QPushButton(layoutWidget);
        btnAddWorker->setObjectName(QString::fromUtf8("btnAddWorker"));

        verticalLayout->addWidget(btnAddWorker);

        btnDelWorker = new QPushButton(layoutWidget);
        btnDelWorker->setObjectName(QString::fromUtf8("btnDelWorker"));

        verticalLayout->addWidget(btnDelWorker);

        btnRefreshTable = new QPushButton(layoutWidget);
        btnRefreshTable->setObjectName(QString::fromUtf8("btnRefreshTable"));

        verticalLayout->addWidget(btnRefreshTable);

        btnReturn = new QPushButton(layoutWidget);
        btnReturn->setObjectName(QString::fromUtf8("btnReturn"));

        verticalLayout->addWidget(btnReturn);


        retranslateUi(AdminInfo);

        QMetaObject::connectSlotsByName(AdminInfo);
    } // setupUi

    void retranslateUi(QWidget *AdminInfo)
    {
        AdminInfo->setWindowTitle(QCoreApplication::translate("AdminInfo", "AdminInfo", nullptr));
        QTableWidgetItem *___qtablewidgetitem = worker->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("AdminInfo", "\345\267\245\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = worker->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("AdminInfo", "\345\247\223\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = worker->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("AdminInfo", "\351\203\250\351\227\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = worker->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("AdminInfo", "\350\201\214\344\275\215", nullptr));
        btnAddWorker->setText(QCoreApplication::translate("AdminInfo", "\345\242\236\345\212\240\345\221\230\345\267\245\344\277\241\346\201\257", nullptr));
        btnDelWorker->setText(QCoreApplication::translate("AdminInfo", "\345\210\240\351\231\244\345\221\230\345\267\245\344\277\241\346\201\257", nullptr));
        btnRefreshTable->setText(QCoreApplication::translate("AdminInfo", "\345\210\267\346\226\260\345\210\227\350\241\250", nullptr));
        btnReturn->setText(QCoreApplication::translate("AdminInfo", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminInfo: public Ui_AdminInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMININFO_H
