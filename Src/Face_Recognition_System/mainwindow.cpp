#pragma execution_character_set("utf-8")
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "FaceRecognition_Qt.h"
#include <QBuffer>
#include <QInputDialog>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QThread>
#include <QObject>
static int temp = 0;
MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	//实例化信息界面对象
	mInfo = new infomationInput();
	//实例化管理对象
	m_AdminInfo = new AdminInfo();
	//实例化考勤对象
	mKaoQin = new KaoQin();
	//KaoQin对象连接信号和槽_KaoQin页面返回按钮显示首页
	connect(mKaoQin, SIGNAL(KaoQinSignal()), this, SLOT(show()));
	//管理界面连接信号和槽
	connect(m_AdminInfo, SIGNAL(adminInfoSignal()), this, SLOT(show()));
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
	connect(m_cameraImageCapture, SIGNAL(imageCaptured(int, QImage)), this, SLOT(cameraImageCaptured(int, QImage)));
	//信息录入对象连接信号和槽_信息录入页面返回按钮显示首页
	connect(mInfo, SIGNAL(infoSignal()), this, SLOT(show()));
	//设置截图目标
	m_cameraImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
	//设置截图方式
	m_camera->setCaptureMode(QCamera::CaptureStillImage);
	//加载取景部件
	m_camera->setViewfinder(m_cameraViewFinder);
	//启用摄像头
	m_camera->start();
	//设定事件类型_登录
	m_ControlType = LOGIN_TYPE;
	//定时器对象
	QTimer *timer = new QTimer(this);
	//实时刷新显示时间
	connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
	//刷新频率1秒
	timer->start(1000);
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
	//刷新考勤页数据
	mKaoQin->RefreshTable();
	//显示考勤页
	mKaoQin->show();
}

/************************************
*@Method:    on_btnWorkerInfoCaptured_clicked
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/11/30 18:16
*@Describe:	 员工信息采集按钮
*************************************/
void MainWindow::on_btnWorkerInfoCaptured_clicked()
{
	//设置事件类型_注册
	m_ControlType = REGISTER_TYPE;
	//开始实时采图
	m_cameraImageCapture->capture();
	//开始注册人脸信息库
	qDebug() << "开始注册人脸信息库!";
}

/************************************
*@Method:    on_btnCheckIn_clicked
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/12/01 10:18
*@Describe:	 确认打开按钮
*************************************/
void MainWindow::on_btnCheckIn_clicked()
{
	//触发采图比对人脸
	m_cameraImageCapture->capture();
	m_ControlType = LOGIN_TYPE;
}

/************************************
*@Method:    on_btnOpenCam_clicked
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/12/01 12:59
*@Describe:	 打开摄像头按钮
*************************************/
void MainWindow::on_btnOpenCam_clicked()
{
	m_camera = new QCamera(this);	//系统摄像头设备
	m_cameraViewFinder = new QCameraViewfinder(this);	//摄像头取景器部件
	m_cameraImageCapture = new QCameraImageCapture(m_camera);	//截图部件
	ui->cameraWindow->addWidget(m_cameraViewFinder);	//ui显示取景
	//实时刷新
	connect(m_cameraImageCapture, SIGNAL(imageCaptured(int, QImage)), this, SLOT(cameraImageCaptured(int, QImage)));
	m_cameraImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
	m_camera->setCaptureMode(QCamera::CaptureStillImage);
	m_camera->setViewfinder(m_cameraViewFinder);
	m_camera->start();//启动摄像头
	m_ControlType = LOGIN_TYPE;
}

/************************************
*@Method:    on_btnAdminLogin_clicked
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/12/01 13:22
*@Describe:	 管理员登录按钮
*************************************/
void MainWindow::on_btnAdminLogin_clicked()
{
	this->hide();
	m_Login = new AdminLogin(nullptr);
	m_Login->exec();
	int result = m_Login->GetLoginResult();
	while (result != LOGIN_SUCCEED) {
		int res = QMessageBox::information(NULL, "错误", "管理员密码错误，请重新输入",
			QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		if (res == QMessageBox::No)
		{
			this->show();
			break;
		}
		else
		{
			m_Login->exec();
			result = m_Login->GetLoginResult();
		}
	}
	if (result == LOGIN_SUCCEED)
	{
		m_AdminInfo->show();
	}
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
				QMessageBox::information(NULL, "完成", "您的人脸信息已经识别成功！请录入其他信息！",
					QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
				//隐藏当前窗口
				this->hide();
				//显示信息窗口
				mInfo->show();
			}
			else
			{
				qDebug() << "人脸信息录入失败";
				QMessageBox::information(NULL, "错误", "请检查您的网络或与管理员联系！",
					QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
				return 1;
			}
		}
		//登录事件类型
		else if (m_ControlType == LOGIN_TYPE)
		{
			//调用人脸搜索
			int success = m_Face->IdentifyFace(imgData);
			if (!success)
			{
				qDebug() << "比对失败";
				QMessageBox::information(NULL, "错误", "打卡失败，人脸库中查无此人，请先注册人脸！",
					QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
			}
			else	//比对成功
			{
				temp = success;
				//打开数据库
				QSqlDatabase database;
				//如果数据库已经存在,则直接采用
				if (QSqlDatabase::contains("qt_sql_default_connection"))
				{
					database = QSqlDatabase::database("qt_sql_default_connection");
				}
				else	//数据库不存在则新建
				{
					database = QSqlDatabase::addDatabase("QSQLITE");
					database.setDatabaseName("MyDataBase.db");
					database.setUserName("123456");
					database.setPassword("123456");
				}
				//数据库打开失败
				if (!database.open())
				{
					qDebug() << "错误: 数据库打开失败..." << database.lastError();
				}
				else
				{
					qDebug() << "数据库打开成功...";
				}
				//创建查询对象
				QSqlQuery query;
				//拼接id查询语句
				QString sql = QString("SELECT * FROM worker WHERE id='%1'").arg(success);
				//执行查询命令
				query.exec(sql);
				if (query.at() != -2)
				{
					QString strTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
					while (query.next())	//查询结果下一条不为空则继续
					{
#pragma region 解析获取的结果
						QString id = query.value(0).toString();
						QString name = query.value(1).toString();
						QString department = query.value(2).toString();
						QString post = query.value(3).toString();
						QString time = query.value(4).toString();
#pragma endregion
						qDebug() << id << name << department << post << time;
#pragma region 同步到界面显示
						ui->kq_id->setText(id);
						ui->kq_department->setText(department);
						ui->kq_name->setText(name);
						ui->kq_post->setText(post);
						ui->kq_time->setText(strTime);
#pragma endregion
					}
					qDebug() << "比对成功";
					//更新查询语句
					sql = QString("UPDATE worker SET time = '%1' WHERE id = '%2'").arg(strTime).arg(temp);
					//修改操作
					query.prepare(sql);
					//如果执行失败
					if (!query.exec())
					{
						qDebug() << "打卡时间更新失败！" << query.lastError();
					}
					else
					{
						qDebug("打卡时间更新成功");
					}
					//释放查询查询对象,避免紊乱
					query.clear();
					//QMessageBox提示1.5秒无操作自动关闭
					QMessageBox *box = new QMessageBox(QMessageBox::Information, tr("完成"), tr("打卡成功"));
					QTimer::singleShot(1500, box, SLOT(accept()));
					box->exec();
				}
				else
				{
					QMessageBox::information(NULL, "失败", "打卡失败!请先注册此人信息!",
						QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
				}
				database.close();
				m_camera->stop();
				QThread::sleep(2);
				m_camera->start();
			}
		}
	}
	return 0;
}

/************************************
*@Method:    timerUpdate
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Parameter: void
*@Created:   2020/11/30 16:30
*@Describe:	 更新时间
*************************************/
void MainWindow::timerUpdate(void)
{
	QDateTime time = QDateTime::currentDateTime();
	QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
	ui->dateTable->setText(str);
}

