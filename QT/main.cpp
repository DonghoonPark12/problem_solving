#include "swqt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	swQT w;
	w.show();
	return a.exec();
}
