#include "stdafx.h"
#include "QSideMenu.h"

QSideMenu::QSideMenu( QWidget* parent /*= Q_NULLPTR */ )
	: QWidget( parent )
{
	GLErrorHandler( initUI(), " -> QSideMenu::initUI()" );
}

eRetCode QSideMenu::initUI()
{
	eRetCode ret = eSuccess;

	m_pMainLayout = new QVBoxLayout( this );
	m_pMainLayout->setSpacing( 0 );
	m_pMainLayout->setMargin( 0 );
	m_pMainLayout->setContentsMargins( 0, 0, 0, 0 );

	m_pItemLayout = new QVBoxLayout( this );
	m_pItemLayout->setSpacing( 0 );
	m_pItemLayout->setMargin( 0 );
	m_pItemLayout->setContentsMargins( 0, 0, 0, 0 );
	m_pItemLayout->setAlignment( Qt::AlignTop );

	QLabel* lMenuName = new QLabel( tr( "Menu" ) );
	lMenuName->setStyleSheet( "QLabel { color: #dfe6e9; padding-left:1px; background-color: #636e72; border-bottom: 1px solid #0984e3 }" );
	lMenuName->setSizePolicy( QSizePolicy( QSizePolicy::Expanding, QSizePolicy::Fixed ) );
	lMenuName->setFixedHeight( 50 );

	QLabel *lFooter = new QLabel( QString::fromStdWString(L"� Fabian D�rkop, 2019") );
	QHelper::updateAllFonts( lFooter, QHelper::instance()->sansSmall );
	lFooter->setStyleSheet( "QLabel { color: #dfe6e9; padding-left:1px; background-color: #2d3436 }" );
	lFooter->setSizePolicy( QSizePolicy( QSizePolicy::Expanding, QSizePolicy::Fixed ) );
	lFooter->setFixedHeight( 40 );

	// Add Menu Buttons here
	m_pItemLayout->addWidget( addEntry( tr( "General" ), "generalSettings" ), 0 );
	m_pItemLayout->addWidget( addEntry( tr( "Game Settings" ), "gameSettings" ), 0 );

	m_pMainLayout->addWidget( lMenuName, 0, Qt::AlignTop );
	m_pMainLayout->addLayout( m_pItemLayout, 1 );
	m_pMainLayout->addWidget( lFooter, 0, Qt::AlignBottom );

	this->setLayout( m_pMainLayout );
	this->setFixedWidth( 250 );
	this->setMinimumHeight( 400 );
	this->setStyleSheet( "color: #dfe6e9; background-color: #2d3436;" );

	for ( auto pItem : m_vItems )
	{
		connect( pItem, SIGNAL( clicked( std::string ) ), this, SLOT( openMenuItem( std::string ) ) );
	}

	return ret;
}



QGLPushButton* QSideMenu::addEntry( QString sName, std::string sPageName )
{
	QGLPushButton *entry = new QGLPushButton( this, sName, sPageName );

	entry->setObjectName( "menuItem" );
	entry->setFixedHeight( 40 );
	entry->setSizePolicy( QSizePolicy( QSizePolicy::Expanding, QSizePolicy::Fixed ) );
	entry->setStyleSheet( "color: #dfe6e9; border: none; border-bottom: 1px solid #0984e3; background-color: #2d3436;" );
	m_vItems.push_back( entry );

	return entry;
}

void QSideMenu::openMenuItem( std::string sPageName )
{
	emit onMenuItemSelected( sPageName );
}

void QSideMenu::paintEvent( QPaintEvent *pe )
{
	QStyleOption o;
	o.initFrom( this );
	QPainter p( this );
	style()->drawPrimitive( QStyle::PE_Widget, &o, &p, this );
};
