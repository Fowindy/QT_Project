#include "KaoQin.h"
#include "ui_KaoQin.h"

KaoQin::KaoQin(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::KaoQin();
	ui->setupUi(this);
}

KaoQin::~KaoQin()
{
	delete ui;
}
