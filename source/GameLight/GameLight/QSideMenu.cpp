#include "stdafx.h"
#include "QSideMenu.h"

QSideMenu::QSideMenu( QWidget* parent /*= Q_NULLPTR */ )
	: QWidget( parent )
{
	GLErrorHandler( initUI(), "QSideMenu::initUI()" );
}

eRetCode QSideMenu::initUI()
{
	eRetCode ret = eSuccess;
	QVBoxLayout *layout = new QVBoxLayout( this );
	layout->setSpacing( 0 );
	layout->setMargin( 0 );
	layout->setContentsMargins( 0, 0, 0, 0 );

	QLabel* lMenuName = new QLabel( tr( "Menu" ) );
	lMenuName->setStyleSheet( "QLabel { background-color: #FF8080 }" );
	lMenuName->setSizePolicy( QSizePolicy( QSizePolicy::Expanding, QSizePolicy::Fixed ) );
	lMenuName->setFixedHeight( 50 );

	QVBoxLayout *loMenuItems = new QVBoxLayout( this );
	loMenuItems->setContentsMargins( 0, 0, 0, 0 );
	loMenuItems->setAlignment( Qt::AlignTop );

	QLabel *lFooter = new QLabel( tr( "Footer" ) );
	lFooter->setStyleSheet( "QLabel { background-color: #8080FF }" );
	lFooter->setSizePolicy( QSizePolicy( QSizePolicy::Expanding, QSizePolicy::Fixed ) );
	lFooter->setFixedHeight( 40 );

	loMenuItems->addWidget( addEntry( "General" ), 0 );
	loMenuItems->addWidget( addEntry( "Game Settings" ), 0 );

	layout->addWidget( lMenuName, 0, Qt::AlignTop );
	layout->addLayout( loMenuItems, 1 );
	layout->addWidget( lFooter, 0, Qt::AlignBottom );

	this->setLayout( layout );
	this->setFixedWidth( 250 );
	this->setMinimumHeight( 400 );
	this->setStyleSheet( "background-color:#404040;" );
	return ret;
}



QLabel* QSideMenu::addEntry( QString sName )
{
	QLabel *entry = new QLabel( this );
	entry->setFixedHeight( 40 );
	entry->setSizePolicy( QSizePolicy( QSizePolicy::Expanding, QSizePolicy::Fixed ) );
	entry->setStyleSheet( "QLabel { color: #ffffff; border-top: 1px solid #606060; background-color: #404040 }" );
	entry->setText( sName );

	return entry;
}

void QSideMenu::paintEvent( QPaintEvent *pe )
{
	QStyleOption o;
	o.initFrom( this );
	QPainter p( this );
	style()->drawPrimitive(
		QStyle::PE_Widget, &o, &p, this );
};
