/** 
* @file         MarkdownLinkAction.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-5-6
*/
#ifndef MARKDOWNLINKACTION_H
#define MARKDOWNLINKACTION_H

#include <QObject>
#include "BaseMarkdownAction.h"

class MarkdownLinkAction : public BaseMarkdownAction
{
	Q_OBJECT

public:
	MarkdownLinkAction(QObject * parent = 0);
	~MarkdownLinkAction();

	virtual	long	serviceId();

	virtual QString title();

	virtual QIcon getIcon();

protected:
	virtual	void	doExecute();

private:
	void	textLink();
};

#endif // 
