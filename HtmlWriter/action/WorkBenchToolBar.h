#ifndef WORKBENCHTOOLBAR_H
#define WORKBENCHTOOLBAR_H

#include <QObject>
#include "action/IToolBar.h"

using namespace UiUtils;

class WorkBenchToolBar : public IToolBar
{
	Q_OBJECT

public:
	WorkBenchToolBar(QWidget *parent);
	~WorkBenchToolBar();

	virtual long serviceId();

protected:
	virtual vector<IAction*> getActions();

private:
	
};

#endif // WORKBENCHTOOLBAR_H
