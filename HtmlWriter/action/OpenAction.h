#ifndef OPENACTION_H
#define OPENACTION_H

#include <QObject>
#include "action/IAction.h"

using UiUtils::IAction;

class OpenAction : public IAction
{
	Q_OBJECT

public:
	OpenAction(const QString& text, QObject * parent = 0);
	~OpenAction();

protected:
	virtual	void	onRun();

private:
	
};

#endif // OPENACTION_H
