#pragma execution_character_set("utf-8")
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "FaceRecognition_Qt.h"
#include <QBuffer>
#include <QInputDialog>
#include <QMessageBox>

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
	//系统摄像头设备
	m_camera = new QCamera(this);
	//摄像头取景部件实例化
	m_cameraViewFinder = new QCameraViewfinder(this);
	//摄像头截图部件实例化
	m_cameraImageCapture = new QCameraImageCapture(m_camera);
	//摄像头取景部件加载到界面
	ui->cameraWindow->addWidget(m_cameraViewFinder);
	//连接截图的信号和槽_实时刷新显示
	connect(m_cameraImageCapture, SIGNAL(imageCaptured(int, QImage)), this, SLOT(cameraImageCapture(int, QImage)));
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

/************************************
*@Method:    cameraImageCaptured
*@Access:    private
*@Returns:   int
*@Author: 	  Fowindy
*@Parameter: int id
*@Parameter: QImage image
*@Created:   2020/11/29 17:48
*@Describe:	 采图槽函数
*************************************/
int MainWindow::cameraImageCaptured(int index, QImage image)
{
	if (index >= 0)
	{
		//创建字节数组对象
		QByteArray byteArray;
		//将字节数组放到buffer中
		QBuffer buffer(&byteArray);
		//将图片保存到buffer中
		image.save(&buffer, "png");
		//将图片字节数据转换我Base64类型
		QString imgData = QString(byteArray.toBase64());
		//释放buffer
		buffer.close();
		//注册人脸
		if (m_ControlType == REGISTER_TYPE)
		{
			QDateTime time = QDateTime::currentDateTime();	//获取系统现在时间
			QString str = time.toString("yyyyMMddhhmmss");	//设置显示格式
			bool ok;
			//弹出输入学号的对话框
			QString text = QInputDialog::getText(this, tr("User_Id"), tr("请输入学号"), QLineEdit::Password, 0, &ok);
			//如果录入信息为空,则提示继续输入
			while (text.isEmpty())
			{
				QMessageBox::information(NULL, "错误", "请输入正确的学号!",
					QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
				text = QInputDialog::getText(this, tr("User_Id"), tr("请输入学号"), QLineEdit::Password, 0, &ok);
			}
			//人脸接口返回true提示人脸信息录入成功
			if (m_Face->RegisterMember(imgData, text))
			{
				qDebug() << "人脸信息录入成功";
				//弹出录入其他信息的对话框
				QMessageBox::information(NULL, "完成", "您的人脸信息已经录入！请录入其他信息！",
					QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
				//隐藏当前窗口
				this->hide();
				//显示信息窗口
			}
		}
	}
}

