#include "stdafx.h"
#include "GLSetting.h"

int GLSetting::iNextID = 0;

GLSetting & GLSetting::setValue( bool bValue )
{
	m_sValue = QString::fromStdString( std::to_string( bValue ) );
	m_eValueType = eBool;
	if ( pWidget == nullptr )
	{
		pWidget = new QCheckBox( sDescription );
	}
	pWidget->setObjectName( sName );
	( (QCheckBox*)pWidget )->setChecked( bValue );
	return *this;
}

GLSetting & GLSetting::setValue( int iValue )
{
	m_sValue = QString::fromStdString( std::to_string( iValue ) );
	m_eValueType = eInt;
	if ( pWidget == nullptr )
	{
		pWidget = new QSpinBox();
	}
	pWidget->setObjectName( sName );
	( (QSpinBox*)pWidget )->setValue( iValue );
	return *this;
}

GLSetting & GLSetting::setValue( QString sValue )
{
	m_sValue = sValue;
	m_eValueType = eString;
	return *this;
}