#pragma once
#include <QWidget>
#include <string>
#include <map>

class QCategory;
class QMainWidget :
	public QWidget
{
	Q_OBJECT

public:
	QMainWidget( QWidget *parent = ( QWidget * ) nullptr );

	void createPages();
	void addPage( QWidget * pPage, std::string sPageName );
	CError getPage( QWidget ** pPage, std::string sPageName );

public slots:
	void changePage( std::string sPageName );
private slots:
	void displayRLSettings();
	void displayMCSettings();

private:
	QVBoxLayout * m_pLayout;
	QWidget * m_pCurrentPage;
	std::map<std::string, QWidget*> m_mPages;

	/*Pages*/
	QWidget *m_pGamesCategory;
	QCategory *m_pGCRocketLeague;
	QCategory *m_pGCMinecraft;
};

