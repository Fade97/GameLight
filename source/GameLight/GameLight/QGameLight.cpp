#include "stdafx.h"
#include "QGameLight.h"
#include "QSideMenu.h"
#include "QMainWidget.h"

QGameLight::QGameLight( QWidget *parent )
	: QMainWindow( parent )
{
	QWidget *centralWidget = new QWidget();

	m_pSideMenu = new QSideMenu( this );
	m_pMainWidget = new QMainWidget( this );
	m_pMainLayout = new QHBoxLayout();

	m_pMainLayout->setSpacing( 0 );
	m_pMainLayout->setMargin( 0 );
	m_pMainLayout->setContentsMargins( 0, 0, 0, 0 );

	this->m_pMainLayout->addWidget( m_pSideMenu );
	this->m_pMainLayout->addWidget( m_pMainWidget );

	QHelper::updateAllFonts( m_pSideMenu, QHelper::instance()->sansLarge );
	QHelper::updateAllFonts( m_pMainWidget, QHelper::instance()->sansMedium );


	centralWidget->setLayout( m_pMainLayout );
	this->setCentralWidget( centralWidget );


	connect( m_pSideMenu, SIGNAL( onMenuItemSelected(std::string)), m_pMainWidget, SLOT(changePage( std::string )) );
}
