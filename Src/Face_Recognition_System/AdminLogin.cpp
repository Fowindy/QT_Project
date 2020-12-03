#include "AdminLogin.h"
#include "ui_AdminLogin.h"

AdminLogin::AdminLogin(QWidget *parent)
	: QDialog(parent),
	ui(new Ui::AdminLogin)
{
	ui->setupUi(this);
	//实例化信息界面对象
	mInfo = new infomationInput();
	//初始化默认用户名和密码为123
	m_UserName = "123";
	m_PassWord = "123";
	m_LoginResult = LOGIN_ERROR;
	//连接Ok和Cancel按钮的信号和槽
	connect(this, SIGNAL(accepted()), this, SLOT(OnOKBtn()));
	connect(this, SIGNAL(rejected()), this, SLOT(OnCancelBtn()));
	//连接信息输入界面返回的信号和槽
	//[问题]同一个infoSignal怎样响应多个槽函数
	connect(mInfo, SIGNAL(infoSignal()), this, SLOT(show()));
}

AdminLogin::~AdminLogin()
{
	delete ui;
}

/************************************
*@Method:    GetLoginResult
*@Access:    public
*@Returns:   int
*@Author: 	  Fowindy
*@Created:   2020/12/02 9:39
*@Describe:	 获取登录对话框结果传到主页
*************************************/
int AdminLogin::GetLoginResult()
{
	//返回登录结果
	return m_LoginResult;
}

/************************************
*@Method:    on_Ok_clicked
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/12/02 9:45
*@Describe:	 Ok按钮槽函数
*************************************/
void AdminLogin::OnOKBtn()
{
	//获取用户输入界面用户名和密码
	QString strUserName = ui->UserEdt->text();
	QString strPassWord = ui->PassWordEdt->text();
	//用户名和密码均正确
	if (strUserName == m_UserName && strPassWord == m_PassWord)
	{
		//登录结果:成功
		m_LoginResult = LOGIN_SUCCEED;
	}
	//用户名和密码均错误
	else if (strUserName != m_UserName && strPassWord != m_PassWord)
	{
		//登录结果:登录错误
		m_LoginResult = LOGIN_ERROR;
	}
	//用户名错误
	else if (strUserName != m_UserName)
	{
		//登录结果:用户名错误
		m_LoginResult = LOGIN_ERROR_NAME;
	}
	else
	{
		//登录结果:密码错误
		m_LoginResult = LOGIN_ERROR_PASSD;
	}
}

/************************************
*@Method:    on_Cancel_clicked
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/12/02 9:46
*@Describe:	 Cancel按钮槽函数
*************************************/
void AdminLogin::OnCancelBtn()
{
	//nothing to do
}
