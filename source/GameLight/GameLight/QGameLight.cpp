#include "stdafx.h"
#include "QGameLight.h"
#include "QSideMenu.h"

QGameLight::QGameLight( QWidget *parent )
	: QMainWindow( parent )
{
	QWidget *centralWidget = new QWidget();

	m_pSideMenu = new QSideMenu( this );

	m_pButton3 = new QPushButton( "Click3" );
	m_pButton3->setMinimumWidth( 500 );
	m_pMainLayout = new QHBoxLayout();
	m_pMenuLayout = new QVBoxLayout();
	m_pMenuLayoutConstraint = new QWidget();
	m_pMainLayout->setSpacing( 0 );
	m_pMainLayout->setMargin( 0 );
	m_pMainLayout->setContentsMargins( 0, 0, 0, 0 );
	this->m_pMainLayout->addWidget( m_pSideMenu );
	this->m_pMainLayout->addWidget( m_pButton3 );
	centralWidget->setLayout( m_pMainLayout );
	this->setCentralWidget( centralWidget );
}
