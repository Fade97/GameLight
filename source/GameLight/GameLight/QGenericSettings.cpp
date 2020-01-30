#include "stdafx.h"
#include "QGenericSettings.h"
#include "QFlowLayout.h"
#include "GLSetting.h"

QGenericSettings::QGenericSettings( QWidget *parent /*= ( QWidget * ) nullptr */ )
	: QWidget( parent )
{
	m_pMainLayout = new QFlowLayout( this, 0, 50, 50 );
	setFont( QHelper::instance()->sansLarge );
	initUI();
}

CError QGenericSettings::getSetting( std::string sSettingName, /*OUT*/ GLSetting *pSetting )
{
	CError erRet;
	erRet.eErrorCode = eSuccess;
	erRet.sLocation += " -> QGenericSettings::getSetting()";
	
	if ( m_mSettings.find( sSettingName ) == m_mSettings.end() )
	{
		erRet.eErrorCode = eFailed;
		erRet.sError = ( tr("The setting with key ").toStdString() + sSettingName + tr( " could not be found" ).toStdString() );
	}
	else
	{
		pSetting = m_mSettings.at( sSettingName );
	}

	return erRet;
}

CError QGenericSettings::setSetting( GLSetting *pSetting )
{
	CError erRet;
	erRet.eErrorCode = eSuccess;
	erRet.sLocation += " -> QGenericSettings::setSetting()";

	m_mSettings[pSetting->sName.toStdString()] = pSetting;

	return erRet;
}

void QGenericSettings::initUI()
{
	m_pMainLayout->setContentsMargins( 10, 5, 0, 0 );

	GLSetting* pSetting1 = new GLSetting( "Generic 1", "My first setting" );
	pSetting1->setValue( true );
	setSetting( pSetting1 );

	for ( auto setting : m_mSettings )
	{
		GLSetting *pSetting = setting.second;
		QWidget *pQSetting = nullptr;
		switch ( pSetting->getValueType() )
		{
		case GLSetting::eValueType::eBool:
			pQSetting = pSetting->pWidget;
			break;
		}

		m_pMainLayout->addWidget( pQSetting );
	}


	qDebug() << this->font();
}
