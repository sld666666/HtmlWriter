/** 
* @file         MarkdownAlignJustifyAction.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-5-6
*/
#ifndef MARKDOWNALIGNJUSTIFYACTION_H
#define MARKDOWNALIGNJUSTIFYACTION_H

#include <QObject>
#include "BaseMarkdownAction.h"

class MarkdownAlignJustifyAction : public BaseMarkdownAction
{
	Q_OBJECT

public:
	MarkdownAlignJustifyAction(QObject * parent = 0);
	~MarkdownAlignJustifyAction();

	virtual	long	serviceId();

	virtual QString title();

	virtual QIcon getIcon();

protected:
	virtual	void	doExecute();

private:
	void	textAlign();
};

#endif // MARKDOWNALIGNJUSTIFYACTION_H
