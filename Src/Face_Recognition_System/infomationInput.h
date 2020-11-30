#pragma once

#include <QWidget>
namespace Ui { class infomationInput; };

class infomationInput : public QWidget
{
	Q_OBJECT

public:
	infomationInput(QWidget *parent = Q_NULLPTR);
	~infomationInput();
signals:
	//info界面信号函数
	void infoSignal();
private slots:
	void on_btnReturn_clicked();

private:
	Ui::infomationInput *ui;
};
