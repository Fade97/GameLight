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
		img = img.scaledToWidth( 400, Qt::TransformationMode::SmoothTransformation );
		int iHeight = img.height();

		QRect rect( 0, (iHeight-170)/2, 400, 170 );
		img = img.copy( rect );

		m_imgBg.setStyleSheet( "border: 1px solid transparent; border-radius: 25px; background: transparent;" );
		m_imgBg.setPixmap( img );

		m_pLayout->addWidget( &m_imgBg );
		m_imgBg.show();
	}

	return erRet;
}
