#include "infomationInput.h"
#include "ui_infomationInput.h"

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
