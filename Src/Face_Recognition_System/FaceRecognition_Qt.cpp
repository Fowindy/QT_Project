#pragma execution_character_set("utf-8")
#include "FaceRecognition_Qt.h"

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
}

FaceRecognition_Qt::~FaceRecognition_Qt()
{
}
