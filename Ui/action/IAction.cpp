#include "IAction.h"


namespace UiUtils{

	IAction::IAction(const QString& text, QObject * parent)
		: QAction(text, parent)
	{
	}

	IAction::~IAction()
	{

	}
}

