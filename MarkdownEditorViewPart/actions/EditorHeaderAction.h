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
#include "BaseMarkdownAction.h"

class EditorHeaderAction : public BaseMarkdownAction
{
	Q_OBJECT

public:
	EditorHeaderAction(QObject * parent = 0);
	~EditorHeaderAction();

	virtual	long	serviceId();

	virtual QString title();

	virtual QIcon getIcon();

protected:
	virtual	void	doExecute();
};

#endif // OPENACTION_H
