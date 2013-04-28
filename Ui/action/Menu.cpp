#include "Menu.h"

namespace UiUtils{
	Menu::Menu(const QString& title, QWidget * parent)
		: QMenu(title, parent)
	{
		initConnect();
	}


	Menu::Menu(QWidget * parent)
			: QMenu(parent)
	{
		initConnect();
	}

	Menu::~Menu()
	{
	}

	void  Menu::initConnect()
	{
		connect(this, SIGNAL(aboutToShow()), this, SLOT(onAboutToShowSlot()));
	}

	void Menu::add(IAction* action)
	{
		if (action){
			action->setText(action->title());
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
			action->execute();
		}					
	}

	void Menu::onAboutToShowSlot()
	{
		if (actions_.empty()){
			actions_ = getActions();
			for_each(actions_.begin(), actions_.end(), 
				bind(&Menu::add, this, _1));
		}
	}
}