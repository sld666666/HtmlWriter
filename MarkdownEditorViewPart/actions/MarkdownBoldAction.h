/** 
* @file         MarkdownBoldAction.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-5-6
*/
#ifndef MARKDOWNBOLDACTION_H
#define MARKDOWNBOLDACTION_H

#include <QObject>
#include "BaseMarkdownAction.h"

class MarkdownBoldAction : public BaseMarkdownAction
{
	Q_OBJECT

public:
	MarkdownBoldAction(QObject * parent = 0);
	~MarkdownBoldAction();

	virtual	long	serviceId();

	virtual QString title();

	virtual QIcon getIcon();

protected:
	virtual	void	doExecute();

private:
	void	textBold();
};

#endif //
