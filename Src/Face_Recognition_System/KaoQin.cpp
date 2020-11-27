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
