#pragma once

#include <QObject>
#include <QNetworkAddressEntry>
#include <QNetworkAccessManager>
#include <QTimer>
#include <QNetworkReply>
#include <QHostInfo>
#include <QEventLoop>
namespace NetJson_Qt
{
	QNetworkAddressEntry getNetworkAddressEntry(void);	//获取本地ip
	QString getDeviceName(void);	//获取本地host
	class HTTP : public QObject
	{
		Q_OBJECT

	private:
		QNetworkAccessManager m_manager;	//网络进入管理
		QNetworkReply *m_reply = nullptr;	//网络反馈
		QTimer m_timer;	//网络计时器

	public:
		HTTP(void);
		~HTTP();
	signals:
		void Finished(const QByteArray data);
		void error(const QNetworkReply::NetworkError error);
	private slots:
		void onFinished(QNetworkReply *reply);
		void onTimeout(void);
		void onError(const QNetworkReply::NetworkError &error);
	public slots:
		void get(const QUrl &url, const int &maxTime = 30000);
		void post(const QNetworkRequest &networkRequest, const QByteArray &append, const int &maxTime = 30000);
		void stop(void);
		bool get(const QUrl &url, QByteArray &target, const int &maxTime = 30000);
		bool post(const QNetworkRequest &networkRequest, const QByteArray &append, QByteArray &target, const int &maxTime = 30000);
	};
}
