#include "IToolBar.h"
#include "ApplicationConfig.h"


namespace UiUtils{

	IToolBar::IToolBar(QWidget * parent)
		: QToolBar(parent)
	{
	}

	IToolBar::~IToolBar()
	{

	}

	void IToolBar::fills()
	{
		vector<IAction*> actions = getActions();
		for_each(actions.begin(), actions.end(), bind(&IToolBar::add
			, this, _1));
	}

	void IToolBar::add(IAction* action)
	{
		if (action){
			QString text = action->title();
			action->setStatusTip(text);
			action->setIcon(action->getIcon());
			this->addAction(action);
			connect(action, SIGNAL(triggered(bool))
				, this, SLOT(actionTriggeredSlot(bool)));
		}
	}

	void IToolBar::actionTriggeredSlot(bool checked)
	{
		IAction* action = dynamic_cast<IAction*> (sender());
		if(action)
		{
			action->execute();
		}					
	}
}

