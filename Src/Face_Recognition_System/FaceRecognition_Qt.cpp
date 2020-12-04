#pragma execution_character_set("utf-8")
#include "FaceRecognition_Qt.h"
#include <QUrl>
#include <QNetworkRequest>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>
#include <QThread>
QString toShowInfo;
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
	//实例化网络管理对象
	detectManager = new QNetworkAccessManager(this);
	//网络管理对象信号和槽
	connect(detectManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyDetectFinished(QNetworkReply*)));
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
void FaceRecognition_Qt::DetectFace(QString qstrImage)
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
	//设置数据提交格式，这个不能自己随便写，每个平台的格式可能不一样，百度AI要求的格式为application/json
	request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
	QJsonObject obj;
	QJsonDocument doc;

	obj.insert("image", qstrImage);
	obj.insert("image_type", "BASE64");
	obj.insert("face_field", "age,beauty,gender,expression,quality");
	obj.insert("max_face_num", 10);
	doc.setObject(obj);

	QByteArray postParam = doc.toJson(QJsonDocument::Compact);
	detectManager->post(request, postParam);
}

FaceRecognition_Qt::~FaceRecognition_Qt()
{
}

/************************************
*@Method:    jsonDetectDataParser
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Parameter: QByteArray replyData
*@Created:   2020/12/04 15:36
*@Describe:	 Json解析
*************************************/
void FaceRecognition_Qt::jsonDetectDataParser(QByteArray &replyData)
{
	QJsonParseError err;
	toShowInfo.clear();
	QJsonDocument doc = QJsonDocument::fromJson(replyData, &err);
	if (err.error == QJsonParseError::NoError) {
		if (doc.isObject()) {
			QJsonObject obj = doc.object();
			//解析反馈的人脸属性结果
			if (obj.contains("result")) {
				QJsonObject resultObj = obj.take("result").toObject();
				//解析人脸个数
				if (resultObj.contains("face_num")) {
					int faceNum = resultObj.take("face_num").toInt();
					qDebug() << "查询到了图片中的人脸个数为：" << faceNum;
				}
				//解析人脸属性
				if (resultObj.contains("face_list")) {
					QJsonArray faceArray = resultObj.take("face_list").toArray();
					for (int i = 0; i < faceArray.size(); i++) {
						QJsonObject faceObj = faceArray.at(i).toObject();

						// 解析性别
						if (faceObj.contains("gender")) {
							QJsonObject genderObj = faceObj.take("gender").toObject();
							if (genderObj.contains("type")) {
								QString type = genderObj.take("type").toString();
								if (type == "male") {
									toShowInfo += "性别：男\r\n";
								}
								else {
									toShowInfo += "性别：女\r\n";
								}
							}
						}

						// 解析年龄
						if (faceObj.contains("age")) {
							int age = faceObj.take("age").toDouble();
							toShowInfo += "年龄：" + QString("%1").arg(age) + "\r\n";
						}

						// 解析颜值
						if (faceObj.contains("beauty")) {
							int beauty = faceObj.take("beauty").toDouble();
							toShowInfo += "颜值：" + QString("%1").arg(beauty) + "\r\n";
						}

						// 解析表情
						if (faceObj.contains("expression")) {
							QJsonObject expressionObj = faceObj.take("expression").toObject();
							if (expressionObj.contains("type")) {
								QString type = expressionObj.take("type").toString();
								if (type == "smile") {
									toShowInfo += "表情：微笑\r\n";
								}
								else if (type == "laugh") {
									toShowInfo += "表情：大笑\r\n";
								}
								else {
									toShowInfo += "表情：不笑\r\n";
								}
							}
						}
						toShowInfo += "\r\n================\r\n";
					}
				}
			}
		}
	}
	qDebug() << "toShowInfo:" << toShowInfo;
	emit(CanShowResult());
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

/************************************
*@Method:    replyDetectFinished
*@Access:    public
*@Returns:   void
*@Author: 	  Fowindy
*@Parameter: QNetworkReply * reply
*@Created:   2020/12/04 15:34
*@Describe:	 detect响应结束槽函数
*************************************/
void FaceRecognition_Qt::replyDetectFinished(QNetworkReply *reply)
{
	qDebug() << "replyDetectFinished IN";
	//读取网络反馈响应的信息
	QByteArray replyData = reply->readAll();
	reply->close();
	qDebug() << "reply data is:" << QString(replyData);
	//json解码
	jsonDetectDataParser(replyData);
	qDebug() << "replyDetectFinished OUT";
}
