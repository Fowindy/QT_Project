#pragma execution_character_set("utf-8")
#include "FaceRecognition_Qt.h"
#include <QUrl>
#include <QNetworkRequest>
#include <QJsonObject>

/************************************
*@Method:    FaceRecognition_Qt
*@Access:    public
*@Returns:
*@Author: 	  Fowindy
*@Parameter: const QString & apiKey
*@Parameter: const QString & secretKey
*@Created:   2020/11/27 22:42
*@Describe:	 FaceRecognition_Qt构造函数
*************************************/
FaceRecognition_Qt::FaceRecognition_Qt(const QString &apiKey, const QString &secretKey)
	: m_apiKey(apiKey), m_secretKey(secretKey), m_dThresholdValue(80.1)	//默认人脸比对80分以上通过
{
}

/************************************
*@Method:    RegisterMember
*@Access:    public
*@Returns:   bool
*@Author: 	  Fowindy
*@Parameter: QString qStrImage	照片字符串码
*@Parameter: QString userId	用户id
*@Created:   2020/11/27 22:46
*@Describe:	 注册人脸函数实现
*************************************/
bool FaceRecognition_Qt::RegisterMember(QString qStrImage, QString userId)
{
	//拼接人脸注册Api的url
	QUrl url("https://aip.baidubce.com/rest/2.0/face/v3/faceset/user/add?access_token=" + m_token);
	//[注意]---创建请求对象_需要添加network(在属性或者pro中添加)
	QNetworkRequest request(url);
	//定义Json追加参数
	QJsonObject append;
	m_userId = userId;
	//设置请求头_要根据Api的接口定义类型来对应
	request.setRawHeader("Content-Type", "aspplication/json");
	append["image"] = qStrImage;	//图片字符串码
	append["image_type"] = "BASE64";	//图像编码
	append["group_id"] = "A";	//用户组id_默认A组
	append["user_id"] = userId;	//用户id
	append["face_token"] = m_token;	//人脸图片唯一标识
	//创建字符数组用于接收结果
	QByteArray buf;
	//查询语句
	return true;
}

FaceRecognition_Qt::~FaceRecognition_Qt()
{
}
