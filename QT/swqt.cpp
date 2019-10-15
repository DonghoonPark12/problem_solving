#include "swqt.h"

swQT::swQT(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(exit()));
}

swQT::~swQT()
{

}

void swQT::exit() {
	QApplication::exit();
}
