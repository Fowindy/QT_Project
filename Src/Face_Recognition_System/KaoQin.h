#pragma once

#include <QWidget>
namespace Ui { class KaoQin; };

class KaoQin : public QWidget
{
	Q_OBJECT

public:
	KaoQin(QWidget *parent = Q_NULLPTR);
	~KaoQin();

private:
	Ui::KaoQin *ui;
};
