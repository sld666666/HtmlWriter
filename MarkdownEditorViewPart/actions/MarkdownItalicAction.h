/** 
* @file         MarkdownItalicAction.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-5-6
*/
#ifndef MARKDOWNITALICACTION_H
#define MARKDOWNITALICACTION_H

#include <QObject>
#include "BaseMarkdownAction.h"

class MarkdownItalicAction : public BaseMarkdownAction
{
	Q_OBJECT

public:
	MarkdownItalicAction(QObject * parent = 0);
	~MarkdownItalicAction();

	virtual	long	serviceId();

	virtual QString title();

	virtual QIcon getIcon();

protected:
	virtual	void	doExecute();

private:
	void	textItalic();
};

#endif // 
