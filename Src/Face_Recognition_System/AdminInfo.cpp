#pragma execution_character_set("utf-8")
#include "AdminInfo.h"
#include "ui_AdminInfo.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

AdminInfo::AdminInfo(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::AdminInfo();
	ui->setupUi(this);
	//实例化用户信息输入界面
	m_infoInput = new infomationInput();
	//连接用户输入界面的信号和槽
	connect(m_infoInput, SIGNAL(adminInfoSignal()), this, SLOT(show()));
	ui->btnRefreshTable->clicked();
}

AdminInfo::~AdminInfo()
{
	delete ui;
}

/************************************
*@Method:    on_btnReturn_clicked
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/12/02 10:48
*@Describe:	 返回按钮槽函数
*************************************/
void AdminInfo::on_btnReturn_clicked()
{
	//隐藏本界面
	this->hide();
	//向首页发送信号
	emit adminInfoSignal();
}

/************************************
*@Method:    on_btnAddWorker_clicked
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/12/02 10:56
*@Describe:	 增加员工按钮槽函数
*************************************/
void AdminInfo::on_btnAddWorker_clicked()
{
	//隐藏当前界面
	this->hide();
	//弹出用户信息输入界面
	m_infoInput->show();
}

/************************************
*@Method:    on_btnDelWorker_clicked
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/12/02 11:03
*@Describe:	 删除员工按钮槽函数
*************************************/
void AdminInfo::on_btnDelWorker_clicked()
{
	bool result;
	//弹出输入工号的对话框
	QString text = QInputDialog::getText(this, tr("User_Id"), tr("请输入工号"), QLineEdit::Password, 0, &result);
	//判断输入是否为空
	if (text.isEmpty())
	{
		QMessageBox::information(NULL, "错误:工号不能为空", "请输入正确的工号!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	}
	//创建数据库对象
	QSqlDatabase database;
	//如果已存在则直接使用
	if (QSqlDatabase::contains("qt_sql_default_connection"))
	{
		database = QSqlDatabase::database("qt_sql_default_connection");
	}
	else	//不存在则新建
	{
		database = QSqlDatabase::addDatabase("QSQLITE");
		//数据库命名
		database.setDatabaseName("MyDataBase.db");
		//设置数据库用户名和密码
		database.setUserName("123456");
		database.setPassword("123456");
	}
	//数据库打开失败
	if (!database.open())
	{
		qDebug() << "错误:数据库连接失败..." << database.lastError();
	}
	else
	{
		qDebug() << "数据库连接成功!...";
	}
	//创建数据库查询对象
	QSqlQuery query;
	//拼接删除数据的sql语句
	QString sql = QString("DELETE FROM worker WHERE id = '%1'").arg(text);
	//
	query.prepare(sql);
	if (!query.exec())
	{
		qDebug() << "删除数据失败！" << query.lastError();
	}
	else
	{
		qDebug("删除数据成功!");
	}
	database.close();
	//再刷新
	ui->btnRefreshTable->clicked();
}

/************************************
*@Method:    on_btnRefresh_clicked
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/12/02 15:23
*@Describe:	 刷新按钮槽函数
*************************************/
void AdminInfo::on_btnRefreshTable_clicked()
{
	for (int cow = 0; cow < 40; cow++) {
		for (int row = 0; row < 4; row++) {
			ui->worker->setItem(cow, row, new QTableWidgetItem(nullptr));
		}
	}

	//创建数据库对象
	QSqlDatabase database;
	//如果已存在数据库则直接使用
	if (QSqlDatabase::contains("qt_sql_default_connection"))
	{
		database = QSqlDatabase::database("qt_sql_default_connection");
	}
	else	//创建数据库
	{
		database = QSqlDatabase::addDatabase("QSQLITE");
		database.setDatabaseName("MyDataBase.db");
		database.setUserName("123456");
		database.setPassword("123456");
	}
	//打开数据库
	if (!database.open())
	{
		qDebug() << "错误:数据库连接失败..." << database.lastError();
	}
	else
	{
		qDebug() << "数据库连接成功!...";
	}
	//创建查询语句对象
	QSqlQuery query;
	//拼接sql查询语句
	QString sql = QString("SELECT * FROM worker");
	//执行查询
	query.exec(sql);
	//设定表格属性
	ui->worker->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui->worker->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->worker->setEditTriggers(QAbstractItemView::NoEditTriggers);
	int cell = 0;
	while (query.next())
	{
		for (int row = 0; row < 4; row++)
		{
			ui->worker->setItem(cell, row, new QTableWidgetItem(query.value(row).toString()));
		}
		cell++;
	}
	//关闭数据库
	database.close();
}
