/** 
* @file         MarkdownAlignCenterAction.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-5-6
*/
#ifndef MARKDOWNALIGNCENTERACTION_H
#define MarkdownALIGNCENTERACTION_H

#include <QObject>
#include "BaseMarkdownAction.h"

class MarkdownAlignCenterAction : public BaseMarkdownAction
{
	Q_OBJECT

public:
	MarkdownAlignCenterAction(QObject * parent = 0);
	~MarkdownAlignCenterAction();

	virtual	long	serviceId();

	virtual QString title();

	virtual QIcon getIcon();

protected:
	virtual	void	doExecute();

private:
	void	textAlign();
};

#endif // MARKDOWNALIGNCENTERACTION_H
