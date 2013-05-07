/** 
* @file         RichAlignJustifyAction.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-5-6
*/
#ifndef RICHALIGNJUSTIFYACTION_H
#define RICHALIGNJUSTIFYACTION_H

#include <QObject>
#include "BaseRichAction.h"

class RichAlignJustifyAction : public BaseRichAction
{
	Q_OBJECT

public:
	RichAlignJustifyAction(QObject * parent = 0);
	~RichAlignJustifyAction();

	virtual	long	serviceId();

	virtual QString title();

	virtual QIcon getIcon();

protected:
	virtual	void	doExecute();

private:
	void	textAlign();
};

#endif // RICHALIGNJUSTIFYACTION_H
