/** 
* @file         MarkdownImageAction.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-5-6
*/
#ifndef MARKDOWNIMAGEACTION_H
#define MARKDOWNIMAGEACTION_H

#include <QObject>
#include "BaseMarkdownAction.h"

class MarkdownImageAction : public BaseMarkdownAction
{
	Q_OBJECT

public:
	MarkdownImageAction(QObject * parent = 0);
	~MarkdownImageAction();

	virtual	long	serviceId();

	virtual QString title();

	virtual QIcon getIcon();

protected:
	virtual	void	doExecute();

private:
	void	textImage();
};

#endif // 
