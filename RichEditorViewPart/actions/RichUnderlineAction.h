/** 
* @file         RichUnderlineAction.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-5-6
*/
#ifndef RICHUNDERLINEACTION_H
#define RICHUNDERLINEACTION_H

#include <QObject>
#include "BaseRichAction.h"

class RichUnderlineAction : public BaseRichAction
{
	Q_OBJECT

public:
	RichUnderlineAction(QObject * parent = 0);
	~RichUnderlineAction();

	virtual	long	serviceId();

	virtual QString title();

	virtual QIcon getIcon();

protected:
	virtual	void	doExecute();

private:
	void	textUnderline();
};

#endif // RICHUNDERLINEACTION_H
