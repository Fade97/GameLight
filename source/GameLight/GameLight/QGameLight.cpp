#include "stdafx.h"
#include "QGameLight.h"
#include "QSideMenu.h"
#include "QGenericSettings.h"

QGameLight::QGameLight( QWidget *parent )
	: QMainWindow( parent )
{
	QWidget *centralWidget = new QWidget();

	m_pSideMenu = new QSideMenu( this );
	m_pSettings = new QGenericSettings( this );
	m_pMainLayout = new QHBoxLayout();

	m_pMainLayout->setSpacing( 0 );
	m_pMainLayout->setMargin( 0 );
	m_pMainLayout->setContentsMargins( 0, 0, 0, 0 );

	this->m_pMainLayout->addWidget( m_pSideMenu );
	this->m_pMainLayout->addWidget( m_pSettings );

	QHelper::updateAllFonts( m_pSideMenu, QHelper::instance()->sansLarge );
	QHelper::updateAllFonts( m_pSettings, QHelper::instance()->sansMedium );


	centralWidget->setLayout( m_pMainLayout );
	this->setCentralWidget( centralWidget );
}
