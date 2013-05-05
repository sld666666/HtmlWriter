/** 
* @file         EditorHeaderAction.h 
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

class EditorHeaderAction : public IAction
{
	Q_OBJECT

public:
	EditorHeaderAction(QObject * parent = 0);
	~EditorHeaderAction();

	virtual	void	execute();

	virtual	long	serviceId();

	virtual QString title();

	virtual QIcon getIcon();
};

#endif // OPENACTION_H
