/** 
* @file         RichAlignCenterAction.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-5-6
*/
#ifndef RICHALIGNCENTERACTION_H
#define RICHALIGNCENTERACTION_H

#include <QObject>
#include "BaseRichAction.h"

class RichAlignCenterAction : public BaseRichAction
{
	Q_OBJECT

public:
	RichAlignCenterAction(QObject * parent = 0);
	~RichAlignCenterAction();

	virtual	long	serviceId();

	virtual QString title();

	virtual QIcon getIcon();

protected:
	virtual	void	doExecute();

private:
	void	textAlign();
};

#endif // RICHALIGNCENTERACTION_H
