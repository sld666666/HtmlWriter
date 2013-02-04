#include "ActionConfigurer.h"

namespace UiUtils{
	ActionConfigurer::ActionConfigurer(QMenuBar *menuBar)
		: menuManager_(new MenuManager(menuBar))
	{

	}

	ActionConfigurer::~ActionConfigurer()
	{

	}

	MenuManagerPtr	ActionConfigurer::getMenuManager()
	{
		return menuManager_;
	}
}

