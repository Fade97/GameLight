#include "stdafx.h"
#include "QGameLight.h"
#include <QtWidgets/QApplication>

QHelper * QHelper::pInstance = nullptr;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	int iFontID = QFontDatabase::addApplicationFont( ":/QGameLight/Resources/OpenSans-Regular.ttf" );
	QString sFontFamily = QFontDatabase::applicationFontFamilies( iFontID ).at(0);
	QHelper::instance()->sansLarge = QFont( sFontFamily, 12 );
	QHelper::instance()->sansMedium = QFont( sFontFamily, 10 );
	QHelper::instance()->sansSmall = QFont( sFontFamily, 8 );
	
	QGameLight w;
	w.show();
	return a.exec();
}
