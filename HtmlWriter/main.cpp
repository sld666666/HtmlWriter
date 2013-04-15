#include "htmlwriter.h"
#include "WorkBench.h"
#include <QtGui/QApplication>
 #include <QTextCodec>

void initCodec()
{
	QTextCodec *codec = QTextCodec::codecForName("GBK");  
	if(codec)
	{
		QTextCodec::setCodecForLocale(codec);   
		QTextCodec::setCodecForCStrings(codec);   
		QTextCodec::setCodecForTr(codec);
	}

	std::locale::global(std::locale(""));//设置为系统语言环境
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	initCodec();
	WorkBench w;
	w.show();
	return a.exec();
}
