#pragma execution_character_set("utf-8")
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "FaceRecognition_Qt.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	//实例化考勤对象
	mKaoQin = new KaoQin();
	//KaoQin对象连接信号和槽_KaoQin页面返回按钮显示首页
	connect(mKaoQin, SIGNAL(KaoQinSignal()), this, SLOT(show()));
	//实例化人脸识别对象
	m_Face = new FaceRecognition_Qt("VB5zp8jnFjLf6wjLtw4lbnme", "ohlu3eO12VMs1qKT8MiSGxb3hShmUyfj");
	//刷新Token
	m_Face->refreshToken();
}

MainWindow::~MainWindow()
{
	delete ui;
}

/************************************
*@Method:    on_bExit_clicked
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/11/27 17:20
*@Describe:	 退出程序按钮函数实现
*************************************/
void MainWindow::on_btnExit_clicked()
{
	this->close();
}

/************************************
*@Method:    on_btnCheckIn_clicked
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/11/27 21:17
*@Describe:	 考勤记录按钮函数实现
*************************************/
void MainWindow::on_btnCheckInRecord_clicked()
{
	//隐藏首页
	this->hide();
	//显示考勤页
	mKaoQin->show();
}

