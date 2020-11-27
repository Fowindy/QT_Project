#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "KaoQin.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private:
	Ui::MainWindow *ui;
	KaoQin *mKaoQin;

private slots:
	void on_btnExit_clicked();	//退出按钮
	void on_btnCheckInRecord_clicked();	//考勤记录按钮
};
#endif // MAINWINDOW_H
