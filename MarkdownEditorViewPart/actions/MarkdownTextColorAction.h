/** 
* @file         MarkdownTextColorAction.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-5-6
*/
#ifndef MARKDOWNTEXTCOLORACTION_H
#define MARKDOWNTEXTCOLORACTION_H

#include <QObject>
#include <QColor>
#include "BaseMarkdownAction.h"

class MarkdownTextColorAction : public BaseMarkdownAction
{
	Q_OBJECT

public:
	MarkdownTextColorAction(QObject * parent = 0);
	~MarkdownTextColorAction();

	virtual	long	serviceId();

	virtual QString title();

	virtual QIcon getIcon();

protected:
	virtual	void	doExecute();

private:
	void	textColor();
	void	colorChanged(const QColor &c);
};

#endif // MARKDOWNTEXTCOLORACTION_H
