#ifndef OPENACTION_H
#define OPENACTION_H

#include <QObject>
#include "action/IAction.h"
#include "context/IContext.h"

using UiUtils::IAction;
using UiUtils::IContext;

class OpenAction : public IAction
{
	Q_OBJECT

public:
	OpenAction(QObject * parent = 0);
	~OpenAction();
	
	virtual	void	execute();

	virtual	long	serviceId();

	virtual QString title();

	virtual	QIcon	getIcon();
};

#endif // OPENACTION_H
