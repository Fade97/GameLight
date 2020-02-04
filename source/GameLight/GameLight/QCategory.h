#pragma once
#include <QWidget>
#include "QFlowLayout.h"
#include "QClickableLabel.h"

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
		connect( &m_imgBg, SIGNAL( clicked() ), this, SIGNAL( categoryClicked() ) );
	}

	CError loadImage( QString sImgFile );

signals:
	void categoryClicked();
	// TODO: add click signals

private:
	QFlowLayout *m_pLayout;
	QClickableLabel m_imgBg;

};

