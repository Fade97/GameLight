#pragma once

#include <QtWidgets/QDialog>
#include "ui_QGameLight.h"

class QGameLight : public QDialog
{
	Q_OBJECT

public:
	QGameLight(QWidget *parent = Q_NULLPTR);

private:
	Ui::QGameLightClass ui;
};
