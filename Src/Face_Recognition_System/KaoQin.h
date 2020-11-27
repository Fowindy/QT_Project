#pragma once

#include <QWidget>
namespace Ui { class KaoQin; };

class KaoQin : public QWidget
{
	Q_OBJECT

public:
	KaoQin(QWidget *parent = Q_NULLPTR);
	~KaoQin();

signals:
	//考勤信号
	void KaoQinSignal();
private slots:
	void on_btnReturn_clicked();

private:
	Ui::KaoQin *ui;
};
