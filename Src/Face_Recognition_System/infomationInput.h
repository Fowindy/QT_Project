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
	void on_btnReturn_clicked();	//返回按钮
	void on_btnSure_clicked();	//确定按钮

private:
	Ui::infomationInput *ui;
};
