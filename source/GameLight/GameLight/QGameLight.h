#pragma once

#include <QtWidgets/QDialog>
#include <QtGui/QPixmap>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtCore/QLine>
#include <QtWidgets/QLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>

class QGameLight : public QDialog
{
	Q_OBJECT

public:
	QGameLight(QWidget *parent = Q_NULLPTR);

private:
	QHBoxLayout *m_pMainLayout;
	QVBoxLayout *m_pMenuLayout;
	QWidget *m_pMenuLayoutConstraint;

	QPushButton *m_pButton;
	QPushButton *m_pButton2;
	QPushButton *m_pButton3;
};
