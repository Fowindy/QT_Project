#include "AdminInfo.h"
#include "ui_AdminInfo.h"

AdminInfo::AdminInfo(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::AdminInfo();
	ui->setupUi(this);
	//实例化用户信息输入界面
	m_infoInput = new infomationInput();
	//连接用户输入界面的信号和槽
	connect(m_infoInput, SIGNAL(adminInfoSignal()), this, SLOT(show()));
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
