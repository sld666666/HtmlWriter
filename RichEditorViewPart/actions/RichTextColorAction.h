/** 
* @file         RichTextColorAction.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-5-6
*/
#ifndef RICHTEXTCOLORACTION_H
#define RICHTEXTCOLORACTION_H

#include <QObject>
#include <QColor>
#include "BaseRichAction.h"

class RichTextColorAction : public BaseRichAction
{
	Q_OBJECT

public:
	RichTextColorAction(QObject * parent = 0);
	~RichTextColorAction();

	virtual	long	serviceId();

	virtual QString title();

	virtual QIcon getIcon();

protected:
	virtual	void	doExecute();

private:
	void	textColor();
	void	colorChanged(const QColor &c);
};

#endif // RICHTEXTCOLORACTION_H
