/** 
* @file         RichBoldAction.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-5-6
*/
#ifndef RICHBOLDACTION_H
#define RICHBOLDACTION_H

#include <QObject>
#include "BaseRichAction.h"

class RichBoldAction : public BaseRichAction
{
	Q_OBJECT

public:
	RichBoldAction(QObject * parent = 0);
	~RichBoldAction();

	virtual	long	serviceId();

	virtual QString title();

	virtual QIcon getIcon();

protected:
	virtual	void	doExecute();

private:
	void	textBold();
};

#endif // OPENACTION_H
