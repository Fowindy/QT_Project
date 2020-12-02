#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "KaoQin.h"
#include "FaceRecognition_Qt.h"
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include "infomationInput.h"
#include "AdminLogin.h"
#include "AdminInfo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
#define REGISTER_TYPE	2	//注册
#define LOGIN_TYPE	1	//登录

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private:
	Ui::MainWindow *ui;
	KaoQin *mKaoQin;	//考勤对象
	FaceRecognition_Qt *m_Face;	//人脸识别接口对象
	QCamera *m_camera;	//相机对象_multimedia
	AdminLogin *m_Login;	//管理员登录界面
	AdminInfo *m_AdminInfo;	//管理界面
	QCameraViewfinder *m_cameraViewFinder;	//摄像头取景器部件_multimediawidgets
	QCameraImageCapture *m_cameraImageCapture;	//截图部件
	int m_ControlType;	//事件类型
	infomationInput *mInfo;	//信息页面对象

private slots:
	void on_btnExit_clicked();	//退出按钮
	void on_btnCheckInRecord_clicked();	//考勤记录按钮
	void on_btnWorkerInfoCaptured_clicked();	//员工信息采集按钮
	void on_btnCheckIn_clicked();	//确认打卡按钮
	void on_btnOpenCam_clicked();	//打开摄像头按钮
	void on_btnAdminLogin_clicked();	//管理员登录按钮
	int cameraImageCaptured(int index, QImage image);	//采图槽函数
	void timerUpdate(void);	//更新时间
};
#endif // MAINWINDOW_H
