#pragma once

#include <QObject>

class FaceRecognition_Qt : public QObject
{
	Q_OBJECT

public:
	FaceRecognition_Qt(const QString &apiKey, const QString &secretKey);
	bool RegisterMember(QString qStrImage, QString userId);	//注册人脸
	~FaceRecognition_Qt();

private:
	//Baidu.AI脸部识别相关的Key参数变量
	QString m_apiKey;	//注册的apikey
	QString m_secretKey;	//注册的secretKey
	QString m_token;	//请求Baidu.AI返回的token值
	double m_dThresholdValue;	//人脸识别的阈值
};
