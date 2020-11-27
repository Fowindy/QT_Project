/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *kq_time;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QLineEdit *kq_name;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *kq_id;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *kq_department;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *kq_post;
    QTextBrowser *cameraWindow;
    QPushButton *btnCheckIn;
    QPushButton *btnWorkerInfoCaptured;
    QPushButton *btnOpenCam;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btnCheckInRecord;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *btnAdminLogin;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *btnExit;
    QSpacerItem *horizontalSpacer_8;
    QWidget *tab_2;
    QWidget *tab_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 341, 31));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 70, 261, 361));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setTextFormat(Qt::AutoText);

        horizontalLayout_5->addWidget(label_3);

        kq_time = new QLineEdit(groupBox);
        kq_time->setObjectName(QString::fromUtf8("kq_time"));

        horizontalLayout_5->addWidget(kq_time);


        gridLayout_2->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setTextFormat(Qt::AutoText);

        horizontalLayout->addWidget(label_4);

        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        kq_name = new QLineEdit(groupBox);
        kq_name->setObjectName(QString::fromUtf8("kq_name"));

        horizontalLayout->addWidget(kq_name);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setTextFormat(Qt::AutoText);

        horizontalLayout_2->addWidget(label_5);

        horizontalSpacer_2 = new QSpacerItem(18, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        kq_id = new QLineEdit(groupBox);
        kq_id->setObjectName(QString::fromUtf8("kq_id"));

        horizontalLayout_2->addWidget(kq_id);


        gridLayout_2->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setTextFormat(Qt::AutoText);

        horizontalLayout_3->addWidget(label_8);

        horizontalSpacer_3 = new QSpacerItem(18, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        kq_department = new QLineEdit(groupBox);
        kq_department->setObjectName(QString::fromUtf8("kq_department"));

        horizontalLayout_3->addWidget(kq_department);


        gridLayout_2->addLayout(horizontalLayout_3, 3, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setTextFormat(Qt::AutoText);

        horizontalLayout_4->addWidget(label_6);

        horizontalSpacer_4 = new QSpacerItem(18, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        kq_post = new QLineEdit(groupBox);
        kq_post->setObjectName(QString::fromUtf8("kq_post"));

        horizontalLayout_4->addWidget(kq_post);


        gridLayout_2->addLayout(horizontalLayout_4, 4, 0, 1, 1);

        cameraWindow = new QTextBrowser(tab);
        cameraWindow->setObjectName(QString::fromUtf8("cameraWindow"));
        cameraWindow->setGeometry(QRect(270, 40, 361, 391));
        btnCheckIn = new QPushButton(tab);
        btnCheckIn->setObjectName(QString::fromUtf8("btnCheckIn"));
        btnCheckIn->setGeometry(QRect(10, 40, 141, 23));
        btnWorkerInfoCaptured = new QPushButton(tab);
        btnWorkerInfoCaptured->setObjectName(QString::fromUtf8("btnWorkerInfoCaptured"));
        btnWorkerInfoCaptured->setGeometry(QRect(660, 40, 91, 31));
        btnOpenCam = new QPushButton(tab);
        btnOpenCam->setObjectName(QString::fromUtf8("btnOpenCam"));
        btnOpenCam->setGeometry(QRect(660, 120, 91, 23));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(110, 450, 661, 25));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        btnCheckInRecord = new QPushButton(layoutWidget);
        btnCheckInRecord->setObjectName(QString::fromUtf8("btnCheckInRecord"));

        horizontalLayout_6->addWidget(btnCheckInRecord);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        btnAdminLogin = new QPushButton(layoutWidget);
        btnAdminLogin->setObjectName(QString::fromUtf8("btnAdminLogin"));

        horizontalLayout_6->addWidget(btnAdminLogin);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);

        btnExit = new QPushButton(layoutWidget);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));

        horizontalLayout_6->addWidget(btnExit);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_8);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\344\272\272\350\204\270\350\257\206\345\210\253\347\263\273\347\273\237", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\254\242\350\277\216\350\277\233\345\205\245\344\272\272\350\204\270\350\257\206\345\210\253\350\200\203\345\213\244\347\263\273\347\273\237", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\350\200\203\345\213\244\344\277\241\346\201\257", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\350\200\203\345\213\244\346\227\266\351\227\264:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\247\223\345\220\215:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\345\267\245\345\217\267:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\351\203\250\351\227\250:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\350\201\214\344\275\215:", nullptr));
        btnCheckIn->setText(QCoreApplication::translate("MainWindow", "\344\270\200\351\224\256\346\211\223\345\215\241", nullptr));
        btnWorkerInfoCaptured->setText(QCoreApplication::translate("MainWindow", "\345\221\230\345\267\245\344\277\241\346\201\257\351\207\207\351\233\206", nullptr));
        btnOpenCam->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\221\204\345\203\217\345\244\264", nullptr));
        btnCheckInRecord->setText(QCoreApplication::translate("MainWindow", "\350\200\203\345\213\244\350\256\260\345\275\225", nullptr));
        btnAdminLogin->setText(QCoreApplication::translate("MainWindow", "\346\225\231\345\270\210\347\231\273\345\275\225", nullptr));
        btnExit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\344\272\272\350\204\270\350\200\203\345\213\244\347\263\273\347\273\237", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\351\242\234\345\200\274\350\257\204\345\210\206\347\263\273\347\273\237", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\344\272\272\350\204\270\346\257\224\345\257\271\347\263\273\347\273\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
