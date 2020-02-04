#pragma once
#include <string>

// Use this color palette:
// https://flatuicolors.com/palette/us


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
	eRetCode eErrorCode = eSuccess;
	std::string sError = "";
	std::string sLocation = "";
};

class QHelper : public QWidget
{
	Q_OBJECT

private:
	QHelper()
	{}
	QHelper( QHelper & i )
	{}
	~QHelper()
	{}

	static QHelper *pInstance;

public:

	static QHelper* instance()
	{
		if ( pInstance == nullptr )
		{
			pInstance = new QHelper();
		}
		return pInstance;
	}

	static QString trans( std::string s )
	{
		return tr( s.c_str() );
	}

	static QString getError( std::string s, eRetCode e = eNone )
	{
		if ( s.compare( "genericError" ) == 0 )
			return  tr( "We have encounterd an error: %1" ).arg( e != eNone ? std::to_string( e ).c_str() : "" );
		else
			return tr( "Unknown error. Please contact the developer!" );
	}

	static void updateAllFonts( QWidget *widget, QFont font )
	{
		if ( widget != NULL )
		{
			if ( widget->font() != QHelper::instance()->sansSmall &&
				 widget->font() != QHelper::instance()->sansMedium &&
				 widget->font() != QHelper::instance()->sansLarge )
			{
				widget->setFont( font );
			}

			const QList<QObject*> list = widget->children();
			for ( int i = 0; i < list.size(); ++i )
			{
				QWidget *widget = dynamic_cast<QWidget*>( list.at( i ) );
				updateAllFonts( widget, font );
			}
		}
	}

	QFont sansLarge;
	QFont sansMedium;
	QFont sansSmall;
};
