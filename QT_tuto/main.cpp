#include "qt_tuto.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QT_tuto w;
	w.show();
	return a.exec();
}
