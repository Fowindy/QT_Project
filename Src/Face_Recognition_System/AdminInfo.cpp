#include "AdminInfo.h"
#include "ui_AdminInfo.h"

AdminInfo::AdminInfo(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::AdminInfo();
	ui->setupUi(this);
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
