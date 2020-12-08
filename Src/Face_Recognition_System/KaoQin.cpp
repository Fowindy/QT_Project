#pragma execution_character_set("utf-8")
#include "KaoQin.h"
#include "ui_KaoQin.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
KaoQin::KaoQin(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::KaoQin();
	ui->setupUi(this);
	RefreshTable();
}

/************************************
*@Method:    RefreshTable
*@Access:    public
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/12/01 12:56
*@Describe:	 考勤页面刷新数据
*************************************/
void KaoQin::RefreshTable()
{
	//设置表格列宽_5列_宽200
	ui->WorkerDaKa->setColumnWidth(5, 200);
	//创建数据库对象
	QSqlDatabase database;
	//数据库已存在则使用
	if (QSqlDatabase::contains("qt_sql_default_connection"))
	{
		database = QSqlDatabase::database("qt_sql_default_connection");
	}
	else	//数据库不存在则创建
	{
		database = QSqlDatabase::addDatabase("QSQLITE");
		database.setDatabaseName("MyDataBase.db");
		database.setUserName("123456");
		database.setPassword("123456");
	}
	//数据库打开失败
	if (!database.open())
	{
		qDebug() << "错误:数据库打开失败..." << database.lastError();

	}
	else	//数据库打开成功
	{
		qDebug() << "数据库打开成功...";
	}
	//创建数据查询对象
	QSqlQuery query;
	//拼接数据库查询语句
	QString sql = QString("SELECT * FROM worker");
	//执行查询命令
	query.exec(sql);
	QString id;
	QString name;
	QString department;
	QString post;
	//设置表格属性
	ui->WorkerDaKa->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui->WorkerDaKa->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->WorkerDaKa->setEditTriggers(QAbstractItemView::NoEditTriggers);
	int cow = 0;
	//为表格赋值
	while (query.next())
	{
		for (int row = 0; row < 5; row++)
		{
			ui->WorkerDaKa->setItem(cow, row, new QTableWidgetItem(query.value(row).toString()));
		}
		cow++;
	}
	//关闭数据库
	database.close();
}

KaoQin::~KaoQin()
{
	delete ui;
}

/************************************
*@Method:    on_btnReturn_clicked
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/11/27 20:04
*@Describe:	 考勤页面返回按钮函数
*************************************/
void KaoQin::on_btnReturn_clicked()
{
	//隐藏当前考勤页
	this->hide();
	//发送信号显示首页
	emit KaoQinSignal();
}
