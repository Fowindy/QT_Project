#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "KaoQin.h"
#include "FaceRecognition_Qt.h"
#include "jasonqt_face.h"

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
	KaoQin *mKaoQin;	//考勤对象
	/*JasonQt_Face*/FaceRecognition_Qt *m_Face;	//人脸识别接口对象

private slots:
	void on_btnExit_clicked();	//退出按钮
	void on_btnCheckInRecord_clicked();	//考勤记录按钮
};
#endif // MAINWINDOW_H
