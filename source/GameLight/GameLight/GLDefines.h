#pragma once
#include <string>

enum eRetCode
{
	eNone = -1,
	eSuccess = 0,
	eFailed,
	eError,
	eCritical
};

struct CError
{
	eRetCode eErrorCode;
	std::string sError;
};

class QHelper : public QWidget
{
	Q_OBJECT

public:
	static QString trans( std::string s )
	{
		return tr( s.c_str() );
	}

	static QString getError( std::string s, eRetCode e = eNone )
	{
		if ( s.compare( "genericError" ) == 0 )
			return tr( ( std::string( "We have encounterd an error: " ) + ( e != eNone ? std::to_string(e) : std::string( "" ) ) ).c_str() );
		else
			return tr( "Unknown error. Please contact the developer!" );
	}

};