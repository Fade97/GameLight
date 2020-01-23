#include "stdafx.h"
#include "QGenericSettings.h"
#include "QFlowLayout.h"

QGenericSettings::QGenericSettings( QWidget *parent /*= ( QWidget * ) nullptr */ )
	: QWidget( parent )
{
	m_pMainLayout = new QFlowLayout( this, 0, 50, 50 );
	setFont( QHelper::instance()->sansLarge );
	initUI();
}

CError QGenericSettings::getSetting( std::string sSettingName, /*OUT*/ int &iValue )
{
	CError erRet;
	erRet.eErrorCode = eSuccess;
	erRet.sLocation = "QGenericSettings::getSetting()";
	
	if ( m_mSettings.find( sSettingName ) == m_mSettings.end() )
	{
		erRet.eErrorCode = eFailed;
		erRet.sError = ( tr("The setting with key ").toStdString() + sSettingName + tr( " could not be found" ).toStdString() );
	}
	else
	{
		iValue = m_mSettings.at( sSettingName );
	}

	return erRet;
}

CError QGenericSettings::setSetting( std::string sSettingName, int iValue )
{
	CError erRet;
	erRet.eErrorCode = eSuccess;
	erRet.sLocation = "QGenericSettings::setSetting()";

	m_mSettings[sSettingName] = iValue;

	return erRet;
}

void QGenericSettings::initUI()
{
	m_pMainLayout->setContentsMargins( 10, 5, 0, 0 );

	QCheckBox * cbTest = new QCheckBox(this);
	cbTest->setText( "Test checkbox" );
	QCheckBox * cbTest2 = new QCheckBox(this);
	cbTest2->setText( "Test checkbox" );
	QCheckBox * cbTest3 = new QCheckBox(this);
	cbTest3->setText( "Test checkbox" );

	qDebug() << this->font();
	
	m_pMainLayout->addWidget( cbTest );
	m_pMainLayout->addWidget( cbTest2 );
	m_pMainLayout->addWidget( cbTest3 );
}
