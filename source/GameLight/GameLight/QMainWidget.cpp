#include "stdafx.h"
#include "QMainWidget.h"
#include "QGenericSettings.h"
#include "QSideMenu.h"
#include "GLSetting.h"
#include "QCategory.h"

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
	//GLErrorHandler::show( getPage( &m_pCurrentPage, "generalSettings" ) );
	changePage( "generalSettings" );

	GLSetting *pSet = nullptr;
	( (QGenericSettings*)m_mPages["generalSettings"] )->getSetting( "Generic 1", &pSet );
	if ( pSet != nullptr )
	{
		qDebug() << pSet->getValue();
	}
}

void QMainWidget::createPages()
{
	addPage( new QGenericSettings( this ), "generalSettings" );
	GLSetting* pSetting1 = new GLSetting( "Generic 1", tr( "My first setting" ) );
	pSetting1->setValue( true );

	GLSetting* pSetting2 = new GLSetting( "Generic 2", tr( "My second setting" ) );
	pSetting2->setValue( false );
	( (QGenericSettings*)m_mPages["generalSettings"] )->setSetting( pSetting1 );
	( (QGenericSettings*)m_mPages["generalSettings"] )->setSetting( pSetting2 );
	( (QGenericSettings*)m_mPages["generalSettings"] )->getSettingList();

	addPage( new QCategory( this ), "gameSettings" );
	GLErrorHandler::show( ( (QCategory*)m_mPages["gameSettings"] )->loadImage( R"(:/QGameLight/Resources/header_alt_assets_10.png)" ) );
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
		erRet.sError = tr( "Could not receive the page '%1'.\nPlease contact the developer!" ).arg( sPageName.c_str() ).toStdString();
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
	else
	{
		if ( GLErrorHandler::show( getPage( &m_pCurrentPage, sPageName ) ) )
		{
			m_pCurrentPage->setVisible( true );
			m_pLayout->addWidget( m_pCurrentPage );
		}
	}
}
