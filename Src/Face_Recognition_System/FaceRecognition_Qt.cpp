#pragma execution_character_set("utf-8")
#include "FaceRecognition_Qt.h"
#include <QUrl>
#include <QNetworkRequest>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

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
	request.setRawHeader("Content-Type", "application/json");
	append["image"] = qStrImage;	//图片字符串码
	append["image_type"] = "BASE64";	//图像编码
	append["group_id"] = "A";	//用户组id_默认A组
	append["user_id"] = userId;	//用户id
	append["face_token"] = m_token;	//人脸图片唯一标识
	//创建字符数组用于接收结果
	QByteArray buf;
	//http对象发送请求
	m_http.post(request, QJsonDocument(append).toJson(), buf, 10000);
	//将接收的buf转换为QJsonObject
	QJsonObject acceptedData(QJsonDocument::fromJson(buf).object());
	//判断反馈信息_反馈失败的情况
	if (buf.isEmpty() || acceptedData.isEmpty() || !acceptedData.contains("result"))
	{
		return false;
	}
	else	//反馈成功
	{
		return true;
	}
}

/************************************
*@Method:    IdentifyFace
*@Access:    public
*@Returns:   int	成功返回id,失败返回false
*@Author: 	  Fowindy
*@Parameter: QString qstrImage
*@Created:   2020/11/30 22:04
*@Describe:	 比对人脸
*************************************/
int FaceRecognition_Qt::IdentifyFace(QString qstrImage)
{
	//拼接人脸搜素的url
	QUrl url("https://aip.baidubce.com/rest/2.0/face/v3/search?access_token=" + m_token);
	//创建请求对象
	QNetworkRequest request(url);
	//创建json参数
	QJsonObject append;
	request.setRawHeader("Content-Type", "application/json");
	append["image"] = qstrImage;
	append["image_type"] = "BASE64";
	append["group_id_list"] = "Color";
	QByteArray buf;
	m_http.post(request, QJsonDocument(append).toJson(), buf, 15000);
	QJsonObject acceptedData(QJsonDocument::fromJson(buf).object());
	if (buf.isEmpty() || acceptedData.isEmpty() || !acceptedData.contains("result"))
	{
		return false;
	}
	QJsonObject result = acceptedData.take("result").toObject();
	if (result.contains("user_list"))
	{
		QJsonArray user_list = result.take("user_list").toArray();
		QJsonObject userObj = user_list.at(0).toObject();
		double score = userObj["score"].toDouble();
		QString user_id = userObj["user_id"].toString();
		int tmp = user_id.toInt();
		if (score >= m_dThresholdValue)
			return tmp;
		else
			return false;
	}
	return false;
}

/************************************
*@Method:    DetectFace
*@Access:    public
*@Returns:   int
*@Author: 	  Fowindy
*@Parameter: QString qstrImage
*@Created:   2020/12/04 15:00
*@Describe:	 颜值评分
*************************************/
int FaceRecognition_Qt::DetectFace(QString qstrImage)
{
#pragma region 地址拼接_不自动获取Token
	//QString requestUrl = "https://aip.baidubce.com/rest/2.0/face/v3/detect";
	//QString accessToken = "24.0e980fd20cd7534bcde1cd94d53ad734.2592000.1608978848.282335-23039406";
	//QUrl url(requestUrl + "?access_token=" + accessToken);
#pragma endregion

	//拼接人脸搜素的url_自动获取Token方式
	QUrl url("https://aip.baidubce.com/rest/2.0/face/v3/detect?access_token=" + m_token);
	//创建请求对象
	QNetworkRequest request(url);
}

FaceRecognition_Qt::~FaceRecognition_Qt()
{
}

/************************************
*@Method:    refreshToken
*@Access:    public
*@Returns:   bool
*@Author: 	  Fowindy
*@Parameter: void
*@Created:   2020/11/29 10:37
*@Describe:	 刷新获取Token
*************************************/
bool FaceRecognition_Qt::refreshToken(void)
{
	QNetworkRequest request(QUrl(QString("https://aip.baidubce.com/oauth/2.0/token?")));
	QByteArray append = QString("grant_type=client_credentials&client_id=%1&client_secret=%2").arg(m_apiKey).arg(m_secretKey).toUtf8();
	QByteArray buf;

	request.setRawHeader("Content-Type", "application/json");
	//超时为15000ms
	const auto &flag = m_http.post(request, append, buf, 15000);
	if (!flag) { return false; }

	const auto &data = QJsonDocument::fromJson(buf).object();
	if (data.isEmpty() || !data.contains("access_token")) { return false; }

	m_token = data["access_token"].toString();
	return true;
}
