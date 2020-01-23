#include "stdafx.h"
#include "GLErrorHandler.h"

GLErrorHandler::GLErrorHandler( eRetCode e, string sLocation )
{
	show( e, sLocation );
}

GLErrorHandler::GLErrorHandler( CError e, string sLocation )
{
	show( e, sLocation );
}

bool GLErrorHandler::show( eRetCode e, string sLocation )
{
	bool bRet = true;
	if ( e != eSuccess )
	{
		QMessageBox msgBox;
		msgBox.setText( QHelper::getError( "genericError", e ) + ( sLocation == "" ? "" : "\n at " + sLocation ).c_str() );
		msgBox.exec();
		bRet = false;
	}
	return bRet;
}

bool GLErrorHandler::show( CError e, string sLocation )
{
	bool bRet = true;
	if ( e.eErrorCode != eSuccess && e.eErrorCode != eNone )
	{
		QMessageBox msgBox;
		msgBox.setText( ( e.sError + ( sLocation == "" ? 
				(e.sLocation == "" ?
					"" : 
					e.sLocation) : 
			("\n" + sLocation) ) ).c_str() );
		msgBox.exec();
		bRet = false;
	}
	return bRet;
}
