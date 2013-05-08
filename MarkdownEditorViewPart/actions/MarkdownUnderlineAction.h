/** 
* @file         MarkdownUnderlineAction.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-5-6
*/
#ifndef MARKDOWNUNDERLINEACTION_H
#define MARKDOWNUNDERLINEACTION_H

#include <QObject>
#include "BaseMarkdownAction.h"

class MarkdownUnderlineAction : public BaseMarkdownAction
{
	Q_OBJECT

public:
	MarkdownUnderlineAction(QObject * parent = 0);
	~MarkdownUnderlineAction();

	virtual	long	serviceId();

	virtual QString title();

	virtual QIcon getIcon();

protected:
	virtual	void	doExecute();

private:
	void	textUnderline();
};

#endif // MARKDOWNUNDERLINEACTION_H
