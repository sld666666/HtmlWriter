/** 
* @file         BaseRichAction.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-5-6
*/
#ifndef BASERICHACTION_H
#define BASERICHACTION_H

#include <QObject>
#include "action/IAction.h"
#include "RichEditorViewPart.h"

using UiUtils::IAction;

class BaseRichAction : public IAction
{
	Q_OBJECT

public:
	BaseRichAction(QObject * parent = 0);
	~BaseRichAction();

	virtual	void	execute();
protected:
	virtual	void	doExecute() = 0;
protected:
	TextEdit*	textEdit_;
};

#endif // OPENACTION_H
