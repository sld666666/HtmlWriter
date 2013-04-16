#ifndef OPENACTION_H
#define OPENACTION_H

#include <QObject>
#include "action/IAction.h"
#include "context/IContext.h"

using UiUtils::IAction;
using UiUtils::IContext;

class OpenAction : public IAction
{
	Q_OBJECT

public:
	OpenAction(const QString& text, QObject * parent = 0);
	~OpenAction();

	virtual	void	execute(IContext* context);
};

#endif // OPENACTION_H
