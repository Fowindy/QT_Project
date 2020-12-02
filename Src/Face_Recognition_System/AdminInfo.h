#pragma once

#include <QWidget>
namespace Ui { class AdminInfo; };

class AdminInfo : public QWidget
{
	Q_OBJECT

public:
	AdminInfo(QWidget *parent = Q_NULLPTR);
	~AdminInfo();

private:
	Ui::AdminInfo *ui;
private slots:
	//返回按钮槽函数
	void on_btnReturn_clicked();
signals:
	//向外界发射信号
	void adminInfoSignal();
};
