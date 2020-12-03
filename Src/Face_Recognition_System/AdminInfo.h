#pragma once

#include <QWidget>
#include "infomationInput.h"
namespace Ui { class AdminInfo; };

class AdminInfo : public QWidget
{
	Q_OBJECT

public:
	AdminInfo(QWidget *parent = Q_NULLPTR);
	~AdminInfo();

private:
	Ui::AdminInfo *ui;
	infomationInput *m_infoInput;
private slots:
	//返回按钮槽函数
	void on_btnReturn_clicked();
	//增加员工按钮槽函数
	void on_btnAddWorker_clicked();
	//删除员工按钮槽函数
	void on_btnDelWorker_clicked();
	//修改员工按钮槽函数
	void on_btnModifyWorker_clicked();
	//刷新按钮槽函数
	void on_btnRefreshTable_clicked();
	//管理界面槽函数_信息输入返回到
signals:
	//向外界发射信号
	void adminInfoSignal();
};
