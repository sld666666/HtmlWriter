#include "htmlwriter.h"
#include "WorkBench.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	WorkBench w;


	w.show();
	return a.exec();
}
