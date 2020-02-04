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
		: sName( name ), sDescription( name ), m_iID( iNextID++ ), pWidget( nullptr )
	{}
	GLSetting( QString name, QString descr )
		: sName( name ), sDescription( descr ), m_iID( iNextID++ ), pWidget( nullptr )
	{}

	QString sName;
	QString sDescription;
	static int iNextID;

	GLSetting &setValue( bool bValue );
	GLSetting &setValue( int iValue );
	GLSetting &setValue( QString sValue );

	inline QString getValue() const
	{
		return m_sValue;
	}

	inline void setValueType( eValueType t )
	{
		m_eValueType = t;
	}

	inline eValueType getValueType() const
	{
		return m_eValueType;
	}

	inline void setValueRange( int iLow = 0, int iHigh = 100 )
	{
		if ( m_eValueType == eInt )
		{
			( (QSpinBox*)pWidget )->setMinimum( iLow );
			( (QSpinBox*)pWidget )->setMaximum( iHigh );
		}
	}

	inline int getID() const
	{
		return m_iID;
	}

	CError save()
	{
		// TODO: implement save to registry or save file
	}

	QWidget *pWidget;

private:

	GLSetting()
	{}

	int m_iID;
	QString m_sValue;
	eValueType m_eValueType;

};

