/** 
* @file         MarkdownAlignRightAction.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-5-6
*/
#ifndef MARKDOWNALIGNRIGHTACTION_H
#define MARKDOWNALIGNRIGHTACTION_H

#include <QObject>
#include "BaseMarkdownAction.h"

class MarkdownAlignRightAction : public BaseMarkdownAction
{
	Q_OBJECT

public:
	MarkdownAlignRightAction(QObject * parent = 0);
	~MarkdownAlignRightAction();

	virtual	long	serviceId();

	virtual QString title();

	virtual QIcon getIcon();

protected:
	virtual	void	doExecute();

private:
	void	textAlign();
};

#endif // OPENACTION_H
