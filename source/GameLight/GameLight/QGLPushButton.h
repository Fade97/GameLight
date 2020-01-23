#pragma once
#include <QPushButton>
#include <string>
class QGLPushButton :
	public QPushButton
{
	Q_OBJECT

public:
	QGLPushButton( QWidget* parent = ( QWidget* )nullptr, QString sText = "Button", std::string sPageName = "" );

signals:
	void clicked( std::string iIndex );

private:
	std::string m_sPageName;

private slots:
	void onButtonClicked();
};

