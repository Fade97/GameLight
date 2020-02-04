#include "stdafx.h"
#include "QClickableLabel.h"

QClickableLabel::QClickableLabel( QWidget* parent, Qt::WindowFlags f )
	: QLabel( parent )
{

}

QClickableLabel::~QClickableLabel()
{}

void QClickableLabel::mousePressEvent( QMouseEvent* event )
{
	emit clicked();
}