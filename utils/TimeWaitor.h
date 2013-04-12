#ifndef UTILS_TIMEWAITOR_H
#define UTILS_TIMEWAITOR_H

#include <QObject>
#include "utils_global.h"
namespace utils{
	class UTILS_EXPORT TimeWaitor : public QObject
	{
		Q_OBJECT

	public:
		TimeWaitor(QObject *parent = 0);
		~TimeWaitor();

		bool waitForTimeFinished(quint64 outTime);

		public slots:
			void progressFinishedSlot();

signals: 
			void timeFinishedSignal();
	};
}


#endif // TIMEWAITOR_H
