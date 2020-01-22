#pragma once
#include <QPushButton>
class QGLPushButton :
	public QPushButton
{
	Q_OBJECT

public:
	QGLPushButton( QWidget* parent = ( QWidget* )nullptr, QString sText = "Button", int iIndex = -1 );

signals:
	void clicked( int iIndex );

private:
	int m_iIndex;

private slots:
	void onButtonClicked();
};

