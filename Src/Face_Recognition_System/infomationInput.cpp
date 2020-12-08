#pragma execution_character_set("utf-8")
#include "infomationInput.h"
#include "ui_infomationInput.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QDateTime>
#include <QSqlError>
extern  QString info[4];//全局变量
infomationInput::infomationInput(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::infomationInput();
	ui->setupUi(this);
	//灰色信息提示
	if (info->size() == 0)
	{
		ui->info_Department->setPlaceholderText("请输入部门全称");
		ui->info_Name->setPlaceholderText("请输入姓名");
		ui->info_Id->setPlaceholderText("请输入工号,工号必须与目标一致");
		ui->info_Post->setPlaceholderText("请输入职位");
	}
	else
	{
		ui->info_Department->setText(info[2]);
		ui->info_Name->setText(info[1]);
		ui->info_Id->setReadOnly(true);
		ui->info_Id->setText(info[0]);
		ui->info_Post->setText(info[3]);
	}

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
	//获取当前系统时间
	QDateTime time = QDateTime::currentDateTime();
	//时间格式
	QString str = time.toString("yyyy-MM-dd hh:mm:ss");
	//参数数组赋值
	QString args[5] = { ui->info_Id->text(),ui->info_Name->text(),ui->info_Department->text(),ui->info_Post->text(),str };
	//创建数据查询对象
	QString sql;
	if (info->size() != 0)
	{
		sql = QString("UPDATE worker SET name = '%1',department = '%2',post = '%3'"
			"WHERE id = '%4'").arg(args[1]).arg(args[2]).arg(args[3]).arg(args[0]);
	}
	else
	{
		//拼接插入数据语句
		sql = QString("insert into worker values('%1','%2','%3','%4','%5')").arg(args[0]).arg(args[1]).arg(args[2]).arg(args[3]).arg(args[4]);
	}
	//插入sql语句到数据表
	sql_query.prepare(sql);
	//判断插入是否成功
	if (!sql_query.exec(sql))
	{
		qDebug() << "数据插入失败,请检查工号是否已存在!" << sql_query.lastError();
		ui->listWidget->addItem(tr("数据插入失败,请检查工号是否已存在!"));
		//关闭数据库
		database.close();
	}
	else
	{
		qDebug() << "数据插入成功!";
		ui->listWidget->addItem(tr("数据插入成功!"));
		database.close();
	}
}
