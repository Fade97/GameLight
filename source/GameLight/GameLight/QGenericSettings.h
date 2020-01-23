#pragma once
#include <QWidget>
#include <string>
#include <map>

class QFlowLayout;
class CError;
class QGenericSettings :
	public QWidget
{
	Q_OBJECT
public:
	QGenericSettings( QWidget *parent = ( QWidget * ) nullptr );

	CError getSetting( std::string sSettingName, /*OUT*/ int &iValue );
	CError setSetting( std::string sSettingName, int iValue );

protected:
	std::string m_sSettingsName;
	QFlowLayout * m_pMainLayout = nullptr;
	virtual void initUI();

private:
	std::map<std::string, int> m_mSettings;


};

