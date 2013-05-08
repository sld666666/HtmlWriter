/** 
* @file         MarkdownAlignLeftAction.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-5-6
*/
#ifndef MARKDOWNALIGNLEFTACTION_H
#define MARKDOWNALIGNLEFTACTION_H

#include <QObject>
#include "BaseMarkdownAction.h"

class MarkdownAlignLeftAction : public BaseMarkdownAction
{
	Q_OBJECT

public:
	MarkdownAlignLeftAction(QObject * parent = 0);
	~MarkdownAlignLeftAction();

	virtual	long	serviceId();

	virtual QString title();

	virtual QIcon getIcon();

protected:
	virtual	void	doExecute();

private:
	void	textAlign();
};

#endif // MARKDOWNALIGNLEFTACTION_H
