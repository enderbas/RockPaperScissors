#include "oyun.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Oyun w;
	w.show();
	return a.exec();
}
