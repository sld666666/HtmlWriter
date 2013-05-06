/** 
* @file         RichItalicAction.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-5-6
*/
#ifndef RICHITALICACTION_H
#define RICHITALICACTION_H

#include <QObject>
#include "BaseRichAction.h"

class RichItalicAction : public BaseRichAction
{
	Q_OBJECT

public:
	RichItalicAction(QObject * parent = 0);
	~RichItalicAction();

	virtual	long	serviceId();

	virtual QString title();

	virtual QIcon getIcon();

protected:
	virtual	void	doExecute();

private:
	void	textItalic();
};

#endif // RICHITALICACTION_H
