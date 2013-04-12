#include <QTimer>
#include <QEventLoop>

#include "timewaitor.h"

namespace utils{
	TimeWaitor::TimeWaitor(QObject *parent)
		: QObject(parent)
	{

	}

	TimeWaitor::~TimeWaitor()
	{

	}

	bool TimeWaitor::waitForTimeFinished(quint64 outTime)
	{	
		QEventLoop loop;
		QTimer timer;
		QObject::connect(&timer,SIGNAL(timeout()),&loop,SLOT(quit()));
		QObject::connect(this, SIGNAL(timeFinishedSignal()), &loop,SLOT(quit()));
		timer.start(outTime);
		loop.exec();

		bool isTimeOut = false;
		if ( !timer.isActive())
		{
			isTimeOut = true;
		}
		else
		{
			isTimeOut = false;
		}

		return isTimeOut;
	}

	void TimeWaitor::progressFinishedSlot()
	{
		emit timeFinishedSignal();
	}
}
