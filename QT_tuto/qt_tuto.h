#ifndef QT_TUTO_H
#define QT_TUTO_H

#include <QtWidgets/QMainWindow>
#include "ui_qt_tuto.h"

class QT_tuto : public QMainWindow
{
	Q_OBJECT

public:
	QT_tuto(QWidget *parent = 0);
	~QT_tuto();

private:
	Ui::QT_tutoClass ui;
};

#endif // QT_TUTO_H
