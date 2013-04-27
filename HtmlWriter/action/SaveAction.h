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
	SaveAction(const QString& text, QObject * parent = 0);
	~SaveAction();

	virtual	void	execute();

	virtual	long	serviceId();
};

#endif // OPENACTION_H
