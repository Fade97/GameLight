#include "stdafx.h"
#include "QCategory.h"

CError QCategory::loadImage( QString sImgFile )
{
	CError erRet;
	
	QPixmap img( sImgFile );
	if ( img.isNull() )
	{
		erRet.eErrorCode = eFailed;
		erRet.sError = tr( "Could not load image %1" ).arg(QDir::toNativeSeparators(sImgFile)).toStdString();
		erRet.sLocation += " -> QCategory::loadImage()";
	}
	else
	{
		m_pLayout->addWidget( &m_imgBg );
		m_imgBg.setPixmap( img );
		m_imgBg.show();
	}

	return erRet;
}
