#include "stdafx.h"
#include "QSideMenu.h"

QSideMenu::QSideMenu( QWidget* parent /*= Q_NULLPTR */ )
	: QWidget( parent )
{
	GLErrorHandler( initUI(), "QSideMenu::initUI()" );
}

eRetCode QSideMenu::initUI()
{
	eRetCode ret = eFailed;
	QHBoxLayout *lo = new QHBoxLayout();
	QPushButton *btn = new QPushButton("HI!");
	lo->addWidget( btn );
	this->setLayout( lo );
	return ret;
}
