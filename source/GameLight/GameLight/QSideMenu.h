#pragma once
#include <QWidget>
#include <vector>
#include <string>

class QGLPushButton;
class QSideMenu : public QWidget
{
	Q_OBJECT

public:
	QSideMenu( QWidget* parent = Q_NULLPTR );
signals:
	void onMenuItemSelected( std::string sPageName );
public slots:
	void openMenuItem( std::string sPageName );

private:
	eRetCode initUI();
	QGLPushButton* addEntry( QString sName, std::string sPageName );

	void paintEvent( QPaintEvent *pe );

	QVBoxLayout *m_pMainLayout = nullptr;
	QVBoxLayout *m_pItemLayout = nullptr;
	std::vector<QGLPushButton*> m_vItems;
};

