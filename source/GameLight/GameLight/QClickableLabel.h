#pragma once
#include <QLabel>
class QClickableLabel :
	public QLabel
{
	Q_OBJECT

public:
	explicit QClickableLabel( QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags() );
	~QClickableLabel();

signals:
	void clicked();

protected:
	void mousePressEvent( QMouseEvent* event );

};

