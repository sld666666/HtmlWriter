#include "IAction.h"


namespace UiUtils{

	IAction::IAction(const QString& text, QObject * parent)
		: QAction(text, parent)
	{
		initConnect();
	}

	IAction::~IAction()
	{

	}

	void IAction::initConnect()
	{
		connect(this, SIGNAL(triggered()), this, SLOT(onTrigger()));
	}

	void IAction::onTrigger()
	{
		onRun();
	}
}

