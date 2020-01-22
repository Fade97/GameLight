#pragma once
#include <QWidget>
#include <vector>

class QGLPushButton;
class QSideMenu : public QWidget
{
	Q_OBJECT

public:
	QSideMenu( QWidget* parent = Q_NULLPTR );

public slots:
	void openMenuItem( int iIndex );

private:
	eRetCode initUI();
	QGLPushButton* addEntry( QString sName );

	void paintEvent( QPaintEvent *pe );

	QVBoxLayout *m_pMainLayout = nullptr;
	QVBoxLayout *m_pItemLayout = nullptr;
	std::vector<QGLPushButton*> m_vItems;
	int m_iLastItem = -1;
};

