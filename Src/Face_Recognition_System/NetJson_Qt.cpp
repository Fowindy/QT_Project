#include "NetJson_Qt.h"
using namespace NetJson_Qt;
#include <QHostInfo>
#include <QEventLoop>
/************************************
*@Method:    HTTP
*@Access:    public
*@Returns:
*@Author: 	  Fowindy
*@Created:   2020/11/28 1:13
*@Describe:
*************************************/
HTTP::HTTP()
{
	connect(&m_manager, SIGNAL(Finished(QNetworkReply*)), this, SLOT(onFinished(QNetworkReply*)));
	connect(&m_timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
	m_timer.setSingleShot(true);
}

HTTP::~HTTP()
{
}

/************************************
*@Method:    get
*@Access:    public
*@Returns:   void
*@Author: 	  Fowindy
*@Parameter: const QUrl & url
*@Parameter: const int & maxTime
*@Created:   2020/11/28 1:40
*@Describe:	 const QUrl &url url地址, const int &maxTime最大超时时间
*************************************/
void HTTP::get(const QUrl &url, const int &maxTime /*= 30000*/)
{
	if (m_reply)
	{
		this->stop();
	}

	m_reply = m_manager.get(QNetworkRequest(url));
	connect(m_reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onError(QNetworkReply::NetworkError)));

	if (m_timer.isActive())
	{
		m_timer.stop();
	}
	m_timer.start(maxTime);
}

/************************************
*@Method:    get
*@Access:    public
*@Returns:   bool
*@Author: 	  Fowindy
*@Parameter: const QUrl & url
*@Parameter: QByteArray & target
*@Parameter: const int & maxTime
*@Created:   2020/11/28 1:43
*@Describe:	 get获取http
*************************************/
bool HTTP::get(const QUrl &url, QByteArray &target, const int &maxTime /*= 30000*/)
{
	QEventLoop eventLoop;

	connect(this, &HTTP::Finished, [&](const QByteArray &data)
	{
		target = data;

		eventLoop.exit(1);
	});
	//connect(this, &HTTP::error, [&]()
	//{
	//	eventLoop.exit(0);
	//});

	this->get(url, maxTime);

	return eventLoop.exec();
}

/************************************
*@Method:    post
*@Access:    public
*@Returns:   void
*@Author: 	  Fowindy
*@Parameter: const QNetworkRequest & networkRequest
*@Parameter: const QByteArray & append
*@Parameter: const int & maxTime
*@Created:   2020/11/28 1:41
*@Describe:	 网络post
*************************************/
void HTTP::post(const QNetworkRequest &networkRequest, const QByteArray &append, const int &maxTime /*= 30000*/)
{
	if (m_reply)
	{
		this->stop();
	}

	m_reply = m_manager.post(networkRequest, append);
	connect(m_reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onError(QNetworkReply::NetworkError)));

	if (m_timer.isActive())
	{
		m_timer.stop();
	}
	m_timer.start(maxTime);
}

/************************************
*@Method:    stop
*@Access:    public
*@Returns:   void
*@Author: 	  Fowindy
*@Parameter: void
*@Created:   2020/11/28 1:42
*@Describe:
*************************************/
void HTTP::stop(void)
{
	if (m_reply)
	{
		disconnect(m_reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onError(QNetworkReply::NetworkError)));
		m_reply = nullptr;
	}

	if (m_timer.isActive())
	{
		m_timer.stop();
	}
}

/************************************
*@Method:    onFinished
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Parameter: QNetworkReply * reply
*@Created:   2020/11/28 9:42
*@Describe:	 onFinished 完成槽函数
*************************************/
void NetJson_Qt::HTTP::onFinished(QNetworkReply *reply)
{
	if (m_reply == reply)
	{
		if (m_reply->error() != QNetworkReply::NoError)
		{
			emit error(m_reply->error());
		}
		else
		{
			emit Finished(m_reply->readAll());
		}

		this->stop();
	}
}

/************************************
*@Method:    onTimeout
*@Access:    private
*@Returns:   void
*@Author: 	  Fowindy
*@Created:   2020/11/28 1:46
*@Describe:	 onTimeout超时相应函数
*************************************/
void NetJson_Qt::HTTP::onTimeout()
{
	if (m_reply)
	{
		this->stop();
		emit error(QNetworkReply::TimeoutError);
	}
}

/************************************
*@Method:    post
*@Access:    public
*@Returns:   bool	1表示成功，0表示失败
*@Author: 	  Fowindy
*@Parameter: const QNetworkRequest & networkRequest
*@Parameter: const QByteArray & append
*@Parameter: QByteArray & target
*@Parameter: const int & maxTime
*@Created:   2020/11/28 9:41
*@Describe:	 get获取http
*************************************/
bool NetJson_Qt::HTTP::post(const QNetworkRequest &networkRequest, const QByteArray &append, QByteArray &target, const int &maxTime /*= 30000*/)
{
	QEventLoop eventLoop;

	auto c1 = connect(this, &HTTP::Finished, [&](const QByteArray &data)
	{
		target = data;

		eventLoop.exit(1);
	});
	auto c2 = connect(this, &HTTP::error, [&]()
	{
		eventLoop.exit(0);
	});

	this->post(networkRequest, append, maxTime);

	const auto &&flag = eventLoop.exec();

	disconnect(c1);
	disconnect(c2);

	return flag;
}

/************************************
*@Method:    getNetworkAddressEntry
*@Access:    public
*@Returns:   QT_NAMESPACE::QNetworkAddressEntry
*@Author: 	  Fowindy
*@Parameter: void
*@Created:   2020/11/28 0:57
*@Describe:	 获取本地ip
*************************************/
QNetworkAddressEntry NetJson_Qt::getNetworkAddressEntry()
{
	auto allInterfaces = QNetworkInterface::allInterfaces();
	//浏览第一个接口
	for (const auto &interface :allInterfaces)
	{
		if (interface.name().indexOf("en0") != -1)
		{
			for (const auto &entry : interface.addressEntries())
			{
				if (entry.ip().toIPv4Address())
				{
					return entry;
				}
			}
		}
	}

	//浏览其他接口
	for (const auto &interface :allInterfaces)
	{
		for (const auto &entry : interface.addressEntries())
		{
			if (entry.ip().toIPv4Address())
			{
				if (entry.ip().toString().indexOf("10.0") == 0)
				{
					return entry;
				}
				else if (entry.ip().toString().indexOf("192.168.") == 0)
				{
					return entry;
				}
			}
		}
	}
	return QNetworkAddressEntry();
}

/************************************
*@Method:    getDeviceName
*@Access:    public
*@Returns:   QT_NAMESPACE::QString
*@Author: 	  Fowindy
*@Parameter: void
*@Created:   2020/11/28 1:08
*@Describe:	 获取本地host
*************************************/
QString NetJson_Qt::getDeviceName()
{
#ifdef Q_OS_MAC	//mac系统
	return QHostInfo::localHostName().replace(".local", "");
#endif // Q_OS_MAC
	return QHostInfo::localHostName();
}
