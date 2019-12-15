#include "stdafx.h"
#include "QGameLight.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QGameLight w;
	w.show();
	return a.exec();
}
