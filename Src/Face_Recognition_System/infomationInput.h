#pragma once

#include <QWidget>
namespace Ui { class infomationInput; };

class infomationInput : public QWidget
{
	Q_OBJECT

public:
	infomationInput(QWidget *parent = Q_NULLPTR);
	~infomationInput();

private:
	Ui::infomationInput *ui;
};
