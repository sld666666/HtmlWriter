/** 
* @file         MarkdownListAction.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-5-6
*/
#ifndef MARKDOWNLISTACTION_H
#define MARKDOWNLISTACTION_H

#include <QObject>
#include "BaseMarkdownAction.h"

class MarkdownListAction : public BaseMarkdownAction
{
	Q_OBJECT

public:
	MarkdownListAction(QObject * parent = 0);
	~MarkdownListAction();

	virtual	long	serviceId();

	virtual QString title();

	virtual QIcon getIcon();

protected:
	virtual	void	doExecute();

private:
	void	textList();
};

#endif // 
