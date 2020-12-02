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
