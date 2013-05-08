/** 
* @file         MarkdownHeaderAction.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-5-6
*/
#ifndef MARKDOWNHEADERACTION_H
#define MARKDOWNHEADERACTION_H

#include <QObject>
#include "BaseMarkdownAction.h"

class MarkdownHeaderAction : public BaseMarkdownAction
{
	Q_OBJECT

public:
	MarkdownHeaderAction(QObject * parent = 0);
	~MarkdownHeaderAction();

	virtual	long	serviceId();

	virtual QString title();

	virtual QIcon getIcon();

protected:
	virtual	void	doExecute();

private:
	void	textHeader();
};

#endif // 
