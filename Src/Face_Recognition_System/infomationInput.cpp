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
