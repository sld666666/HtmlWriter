#include "Menu.h"

namespace UiUtils{
	Menu::Menu(const QString& title, QWidget * parent)
		: QMenu(title, parent)
	{
	}

	Menu::Menu(const QString& title
		, IContext* context
		, QWidget * parent)
		: QMenu(title, parent)
		, context_(context)
	{
	}

	Menu::Menu(IContext* context
			, QWidget * parent)
			: QMenu(parent)
			, context_(context)
	{

	}

	Menu::~Menu()
	{
	}

	void Menu::add(IAction* action)
	{
		if (action){
			this->addAction(action);
			connect(action, SIGNAL(triggered(bool))
				, this, SLOT(actionTriggeredSlot(bool)));
		}
	}

	void Menu::actionTriggeredSlot(bool checked)
	{
		IAction* action = dynamic_cast<IAction*> (sender());
		if(action)
		{
			action->execute(context_);
		}					
	}
}