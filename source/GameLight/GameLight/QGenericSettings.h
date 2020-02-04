#pragma once
#include <QWidget>
#include <string>
#include <vector>
#include <map>

class GLSetting;
class QFlowLayout;
class CError;
class QGenericSettings :
	public QWidget
{
	Q_OBJECT
public:
	QGenericSettings( QWidget *parent = ( QWidget * ) nullptr );

	std::vector<std::string> getSettingList()
	{
		std::vector<std::string> vRet;
		for ( auto spair : m_mSettings )
		{
			vRet.push_back( spair.first );
		}
		return vRet;
	}
	CError getSetting( std::string sSettingName, /*OUT*/ GLSetting **pSetting );
	CError setSetting( GLSetting *pSetting );

protected:
	std::string m_sSettingsName;
	QFlowLayout * m_pMainLayout = nullptr;
	virtual void initUI();

private:
	std::map<std::string, GLSetting*> m_mSettings;


};

