#pragma once

#include <QDialog>
#include "infomationInput.h"
namespace Ui { class AdminLogin; };
#define LOGIN_SUCCEED		1	//登录成功
#define LOGIN_ERROR_NAME	2	//用户名错误
#define LOGIN_ERROR_PASSD	3	//密码错误
#define LOGIN_ERROR			4	//用户名和密码均错误

class AdminLogin : public QDialog
{
	Q_OBJECT

public:
	AdminLogin(QWidget *parent = Q_NULLPTR);
	~AdminLogin();
	int GetLoginResult();	//获取登录对话框结果传到主页

private slots:
	void OnOKBtn();	//Ok按钮槽函数
	void OnCancelBtn(); //Cancel按钮槽函数

private:
	Ui::AdminLogin *ui;
	int m_LoginResult;	//登录结果
	QString m_UserName;	//用户名
	QString m_PassWord;	//密码
};
