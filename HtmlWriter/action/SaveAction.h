/** 
* @file         SaveAction.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-25
*/
#ifndef SAVEACTION_H
#define SAVEACTION_H

#include <QObject>
#include "action/IAction.h"
#include "context/IContext.h"

using UiUtils::IAction;
using UiUtils::IContext;

class SaveAction : public IAction
{
	Q_OBJECT

public:
	SaveAction(QObject * parent = 0);
	~SaveAction();

	virtual	void	execute();

	virtual	long	serviceId();

	virtual QString title();

	virtual	QIcon	getIcon();
};

#endif // OPENACTION_H
