#ifndef SWQT_H
#define SWQT_H

#include <QtWidgets/QMainWindow>
#include "ui_swqt.h"

class swQT : public QMainWindow
{
	Q_OBJECT

public:
	swQT(QWidget *parent = 0);
	~swQT();

private:
	Ui::swQTClass ui;
	private slots:
	void exit();
};

#endif // SWQT_H
