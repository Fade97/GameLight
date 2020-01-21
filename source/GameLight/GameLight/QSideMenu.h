#pragma once
#include <QWidget>

class QSideMenu : public QWidget
{
	Q_OBJECT

public:
	QSideMenu( QWidget* parent = Q_NULLPTR );

private:
	eRetCode initUI();
};

