/** 
* @file         MarkdownBlockAction.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-5-6
*/
#ifndef MARKDOWNBLOCKACTION_H
#define MARKDOWNBLOCKACTION_H

#include <QObject>
#include "BaseMarkdownAction.h"

class MarkdownBlockAction : public BaseMarkdownAction
{
	Q_OBJECT

public:
	MarkdownBlockAction(QObject * parent = 0);
	~MarkdownBlockAction();

	virtual	long	serviceId();

	virtual QString title();

	virtual QIcon getIcon();

protected:
	virtual	void	doExecute();

private:
	void	textBlock();
};

#endif // 
