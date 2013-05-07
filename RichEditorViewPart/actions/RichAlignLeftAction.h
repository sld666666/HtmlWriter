/** 
* @file         RichAlignLeftAction.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-5-6
*/
#ifndef RICHALIGNLEFTACTION_H
#define RICHALIGNLEFTACTION_H

#include <QObject>
#include "BaseRichAction.h"

class RichAlignLeftAction : public BaseRichAction
{
	Q_OBJECT

public:
	RichAlignLeftAction(QObject * parent = 0);
	~RichAlignLeftAction();

	virtual	long	serviceId();

	virtual QString title();

	virtual QIcon getIcon();

protected:
	virtual	void	doExecute();

private:
	void	textAlign();
};

#endif // RICHALIGNLEFTACTION_H
