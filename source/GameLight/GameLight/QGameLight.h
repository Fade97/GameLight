#pragma once

#include <QDialog>
#include <QPixmap>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>
#include <QLine>
#include <QLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>

class QSideMenu;
class QMainWidget;
class QGameLight : public QMainWindow
{
	Q_OBJECT

public:
	QGameLight(QWidget *parent = Q_NULLPTR);

private:
	QSideMenu *m_pSideMenu;
	QMainWidget *m_pMainWidget;

	QHBoxLayout *m_pMainLayout;
	QVBoxLayout *m_pMenuLayout;
	QWidget *m_pMenuLayoutConstraint;

	QPushButton *m_pButton;
	QPushButton *m_pButton2;
	QPushButton *m_pButton3;
};
