#include "stdafx.h"
#include "QMainWidget.h"
#include "QGenericSettings.h"
#include "QSideMenu.h"

QMainWidget::QMainWidget( QWidget *parent )
	: QWidget( parent ), m_pCurrentPage( nullptr )
{
	createPages();
	m_pLayout = new QVBoxLayout( this );
	this->setLayout( m_pLayout );
	m_pLayout->setSpacing( 0 );
	m_pLayout->setMargin( 0 );
	m_pLayout->setContentsMargins( 0, 0, 0, 0 );

	// set default page
	GLErrorHandler::show( getPage( &m_pCurrentPage, "genericSettings" ) );
	changePage( "genericSettings" );

}

void QMainWidget::createPages()
{
	addPage( new QGenericSettings( this ), "genericSettings" );
	addPage( new QSideMenu( this ), "sideMenu" );
}

void QMainWidget::addPage( QWidget * pPage, std::string sPageName )
{
	if ( pPage != nullptr && !sPageName.empty() )
	{
		m_mPages[sPageName] = pPage;
		m_mPages[sPageName]->setVisible( false );
	}
}

CError QMainWidget::getPage( QWidget ** pPage, std::string sPageName )
{
	CError erRet;
	if ( m_mPages.find( sPageName ) == m_mPages.end() )
	{
		erRet.eErrorCode = eCritical;
		erRet.sError = tr( "Could not receive the page '" ).toStdString() + sPageName + tr( "'.\nPlease contact the developer!" ).toStdString();
		erRet.sLocation += " -> QMainWidget::getPage()";
	}
	else
	{
		*pPage = ( m_mPages.at( sPageName ) );
	}

	return erRet;
}

void QMainWidget::changePage( std::string sPageName )
{
	QWidget * qwTemp = nullptr;
	if ( m_pCurrentPage != nullptr )
	{
		qwTemp = m_pCurrentPage;
		m_pCurrentPage->setVisible( false );
		m_pLayout->removeWidget( m_pCurrentPage );

		if ( !GLErrorHandler::show( getPage( &m_pCurrentPage, sPageName ) ) )
		{
			m_pCurrentPage = qwTemp;
		}
		m_pCurrentPage->setVisible( true );
		m_pLayout->addWidget( m_pCurrentPage );
	}
}
