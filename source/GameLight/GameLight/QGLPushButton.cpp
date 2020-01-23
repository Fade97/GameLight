#include "stdafx.h"
#include "QGLPushButton.h"

QGLPushButton::QGLPushButton( QWidget* parent /*= ( QWidget* )nullptr*/, QString sText /*= "Button" */, std::string sPageName /*= "" */ )
	: QPushButton( sText, parent ), m_sPageName( sPageName )
{
	connect( this, SIGNAL( clicked(void) ), this, SLOT( onButtonClicked(void) ) );

}

void QGLPushButton::onButtonClicked()
{
	emit clicked( m_sPageName );
}

