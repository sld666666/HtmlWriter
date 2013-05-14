/** 
* @file         BaseMarkdownAction.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-5-6
*/
#ifndef BASERICHACTION_H
#define BASERICHACTION_H

#include <QObject>
#include <QTextCharFormat>
#include "action/IAction.h"
#include "MarkdownEditorViewPart.h"

using UiUtils::IAction;

class BaseMarkdownAction : public IAction
{
	Q_OBJECT

public:
	BaseMarkdownAction(QObject * parent = 0);
	~BaseMarkdownAction();

	virtual	void	execute();
protected:
	virtual	void	doExecute() = 0;
protected:
	TextEdit*	textEdit_;
};

#endif // OPENACTION_H
