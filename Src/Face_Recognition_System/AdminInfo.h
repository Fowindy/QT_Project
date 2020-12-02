#pragma once

#include <QWidget>
namespace Ui { class AdminInfo; };

class AdminInfo : public QWidget
{
	Q_OBJECT

public:
	AdminInfo(QWidget *parent = Q_NULLPTR);
	~AdminInfo();

private:
	Ui::AdminInfo *ui;
};
