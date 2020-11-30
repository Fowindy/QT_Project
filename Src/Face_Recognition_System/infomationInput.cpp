#include "infomationInput.h"
#include "ui_infomationInput.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>

infomationInput::infomationInput(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::infomationInput();
	ui->setupUi(this);
}

infomationInput::~infomationInput()
{
	delete ui;
}

/************************************
*@Method:    on_btnReturn_clicked
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/11/30 10:02
*@Describe:	 信息界面返回按钮
*************************************/
void infomationInput::on_btnReturn_clicked()
{
	//隐藏当前界面
	this->hide();
	//发送信息_显示首页
	emit infoSignal();
}

/************************************
*@Method:    on_btnSure_clicked
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/11/30 10:11
*@Describe:	 确定按钮
*************************************/
void infomationInput::on_btnSure_clicked()
{
	//建立并打开数据库
	QSqlDatabase database;
	//如果数据库已经存在
	if (QSqlDatabase::contains("qt_sql_default_connection"))
	{
		//数据库就用当前存在的数据库
		database = QSqlDatabase::database("qt_sql_default_connection");
	}
	else	//新建一个数据库
	{
		//增加一个数据库
		database = QSqlDatabase::addDatabase("QSQLITE");
		//设置数据库名字
		database.setDatabaseName("MyDataBase.db");
		//设置数据库的用户名
		database.setUserName("123456");
		//设置数据库的密码
		database.setPassword("123456");
	}
	//如果数据库没有打开_数据库连接失败
	if (!database.open())
	{
		qDebug() << "错误:数据库连接失败..." << database.lastError();
		ui->listWidget->addItem(tr("错误:数据库连接失败..."));
	}
	else	//数据库连接成功
	{
		qDebug() << "数据库连接成功...";
		ui->listWidget->addItem(tr("数据库连接成功..."));
	}
	//创建数据库表格对象
	QSqlQuery sql_query;
	//往数据库表格写入数据
	//如果不存在员工表格
	if (!sql_query.exec("create table IF NOT EXISTS  worker(id int primary key, name varchar(20), department varchar(20), post varchar(20),time Text)"))
	{
		//错误:创建数据表失败
		qDebug() << "Error: Fail to create table." << sql_query.lastError();
		ui->listWidget->addItem(tr("Error: Fail to create worker table."));
	}
	else	//worker数据表创建成功
	{
		qDebug() << "worker Table created!";
		ui->listWidget->addItem(tr("worker Table created Success!"));
	}
}
