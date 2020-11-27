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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KaoQin
{
public:
    QTableWidget *WorkerDaKa;
    QPushButton *btnReturn;

    void setupUi(QWidget *KaoQin)
    {
        if (KaoQin->objectName().isEmpty())
            KaoQin->setObjectName(QString::fromUtf8("KaoQin"));
        KaoQin->resize(720, 445);
        WorkerDaKa = new QTableWidget(KaoQin);
        if (WorkerDaKa->columnCount() < 5)
            WorkerDaKa->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        WorkerDaKa->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        WorkerDaKa->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        WorkerDaKa->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        WorkerDaKa->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        WorkerDaKa->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        if (WorkerDaKa->rowCount() < 19)
            WorkerDaKa->setRowCount(19);
        WorkerDaKa->setObjectName(QString::fromUtf8("WorkerDaKa"));
        WorkerDaKa->setGeometry(QRect(0, 0, 721, 391));
        WorkerDaKa->setRowCount(19);
        WorkerDaKa->setColumnCount(5);
        btnReturn = new QPushButton(KaoQin);
        btnReturn->setObjectName(QString::fromUtf8("btnReturn"));
        btnReturn->setGeometry(QRect(570, 400, 75, 23));

        retranslateUi(KaoQin);

        QMetaObject::connectSlotsByName(KaoQin);
    } // setupUi

    void retranslateUi(QWidget *KaoQin)
    {
        KaoQin->setWindowTitle(QCoreApplication::translate("KaoQin", "\350\200\203\345\213\244\350\256\260\345\275\225", nullptr));
        QTableWidgetItem *___qtablewidgetitem = WorkerDaKa->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("KaoQin", "\345\267\245\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = WorkerDaKa->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("KaoQin", "\345\247\223\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = WorkerDaKa->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("KaoQin", "\351\203\250\351\227\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = WorkerDaKa->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("KaoQin", "\350\201\214\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = WorkerDaKa->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("KaoQin", "\346\211\223\345\215\241\346\227\266\351\227\264", nullptr));
        btnReturn->setText(QCoreApplication::translate("KaoQin", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KaoQin: public Ui_KaoQin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KAOQIN_H
