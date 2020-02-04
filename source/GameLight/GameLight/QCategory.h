#pragma once
#include <QWidget>
#include "QFlowLayout.h"
class CError;
class QCategory : public QWidget
{
	Q_OBJECT

public:
	QCategory( QWidget *parent = ( QWidget* )nullptr )
		: QWidget(parent)
	{
		m_pLayout = new QFlowLayout( this, 0, 50, 50 );
		this->setLayout( m_pLayout );
	}

	CError loadImage( QString sImgFile );

private:
	QFlowLayout *m_pLayout;
	QLabel m_imgBg;

};

