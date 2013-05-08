/** 
* @file         MarkdownDivLineAction.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-5-6
*/
#ifndef MARKDOWNDIVLINEACTION_H
#define MARKDOWNDIVLINEACTION_H

#include <QObject>
#include "BaseMarkdownAction.h"

class MarkdownDivLineAction : public BaseMarkdownAction
{
	Q_OBJECT

public:
	MarkdownDivLineAction(QObject * parent = 0);
	~MarkdownDivLineAction();

	virtual	long	serviceId();

	virtual QString title();

	virtual QIcon getIcon();

protected:
	virtual	void	doExecute();

private:
	void	textDivLine();
};

#endif // 
