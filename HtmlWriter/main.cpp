#include "htmlwriter.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	HtmlWriter w;


	w.show();
	return a.exec();
}
