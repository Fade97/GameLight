#include "stdafx.h"
#include "QGLPushButton.h"

QGLPushButton::QGLPushButton( QWidget* parent /*= ( QWidget* )nullptr*/, QString sText /*= "Button" */, int iIndex /*= -1 */ )
	: QPushButton( sText, parent ), m_iIndex( iIndex )
{
	connect( this, SIGNAL( clicked(void) ), this, SLOT( onButtonClicked(void) ) );

}

void QGLPushButton::onButtonClicked()
{
	emit clicked( m_iIndex );
}

