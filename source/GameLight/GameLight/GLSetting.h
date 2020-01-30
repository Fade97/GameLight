#pragma once
#include <QObject>
class GLSetting : public QObject
{
	Q_OBJECT

public:

	enum eValueType
	{
		eBool,
		eInt,
		eString
	};

	GLSetting( QString name )
		: sName(name), sDescription(name), m_iID(iNextID++), pWidget(nullptr)
	{}
	GLSetting( QString name, QString descr )
		: sName( name ), sDescription( descr ), m_iID( iNextID++ ), pWidget(nullptr)
	{}

	QString sName;
	QString sDescription;
	static int iNextID;

	GLSetting &setValue( bool bValue )
	{
		m_sValue = QString::fromStdString( std::to_string( bValue ) );
		m_eValueType = eBool;
		if ( pWidget == nullptr )
		{
			pWidget = new QCheckBox( sDescription );
		}
		pWidget->setObjectName( sName );
		( (QCheckBox*)pWidget )->setChecked( bValue );
		return *this;
	}
	GLSetting &setValue( int iValue )
	{
		m_sValue = QString::fromStdString(std::to_string(iValue));
		m_eValueType = eInt;
		if ( pWidget == nullptr )
		{
			pWidget = new QSpinBox();
		}
		pWidget->setObjectName( sName );
		( (QSpinBox*)pWidget )->setValue( iValue );
		return *this;
	}
	GLSetting &setValue( QString sValue )
	{
		m_sValue = sValue;
		m_eValueType = eString;
		return *this;
	}

	QString getValue() const
	{
		return m_sValue;
	}

	int getID() const
	{
		return m_iID;
	}
	eValueType getValueType() const
	{
		return m_eValueType;
	}

	void setValueType( eValueType t )
	{
		m_eValueType = t;
	}

	CError save()
	{
		// TODO: implement save to registry or save file
	}

	QWidget *pWidget;

private:

	GLSetting(){}

	int m_iID;
	QString m_sValue;
	eValueType m_eValueType;

};

