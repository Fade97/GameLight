#include "stdafx.h"
#include "QGameLight.h"

QGameLight::QGameLight(QWidget *parent)
	: QDialog(parent)
{
	double dScalar = 0.5;
	this->setFixedSize( int(1920*dScalar), int(1080*dScalar) );
	
	m_pButton = new QPushButton( "Click" );
	m_pButton2 = new QPushButton( "Click2" );
	m_pButton3 = new QPushButton( "Click3" );
	m_pMainLayout = new QHBoxLayout();
	m_pMenuLayout = new QVBoxLayout();
	m_pMenuLayoutConstraint = new QWidget();

	m_pMenuLayout->addWidget( m_pButton );
	m_pMenuLayout->addWidget( m_pButton2 );

	m_pMenuLayoutConstraint->setLayout( m_pMenuLayout );
	m_pMenuLayoutConstraint->setMaximumWidth( 280 );

	this->m_pMainLayout->addWidget( m_pMenuLayoutConstraint );
	this->m_pMainLayout->addWidget( m_pButton3 );
	this->setLayout( m_pMainLayout );
}
