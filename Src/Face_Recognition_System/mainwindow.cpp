﻿#pragma execution_character_set("utf-8")
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	//实例化考勤对象
	mKaoQin = new KaoQin();
	//KaoQin对象连接信号和槽_KaoQin页面返回按钮显示首页
	connect(mKaoQin, SIGNAL(KaoQinSignal()), this, SLOT(show()));
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
void MainWindow::on_bExit_clicked()
{
	this->close();
}

