/** 
* @file         RichAlignRightAction.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-5-6
*/
#ifndef RICHALIGNRIGHTACTION_H
#define RICHALIGNRIGHTACTION_H

#include <QObject>
#include "BaseRichAction.h"

class RichAlignRightAction : public BaseRichAction
{
	Q_OBJECT

public:
	RichAlignRightAction(QObject * parent = 0);
	~RichAlignRightAction();

	virtual	long	serviceId();

	virtual QString title();

	virtual QIcon getIcon();

protected:
	virtual	void	doExecute();

private:
	void	textAlign();
};

#endif // OPENACTION_H
