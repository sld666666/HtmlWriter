/** 
* @file         SaveAsAction.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-25
*/
#ifndef SAVEASACTION_H
#define SAVEASACTION_H

#include <QObject>
#include "action/IAction.h"
#include "context/IContext.h"

using UiUtils::IAction;
using UiUtils::IContext;

class SaveAsAction : public IAction
{
	Q_OBJECT

public:
	SaveAsAction(QObject * parent = 0);
	~SaveAsAction();

	virtual	void	execute();

	virtual	long	serviceId();

	virtual QString title();
};

#endif // OPENACTION_H
