#include "KaoQin.h"
#include "ui_KaoQin.h"

KaoQin::KaoQin(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::KaoQin();
	ui->setupUi(this);
	//设置表格列宽_5列_宽200
	ui->WorkerDaKa->setColumnWidth(5, 200);
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
