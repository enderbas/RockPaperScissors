#include "oyun.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Oyun w;
	w.show();
	w.resize(QSize(1300, 700));
	w.setWindowTitle("RockPaperScissors");
	return a.exec();
}
