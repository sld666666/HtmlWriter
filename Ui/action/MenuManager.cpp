#include "MenuManager.h"

namespace UiUtils{
	MenuManager::MenuManager(QMenuBar *menuBar)
		: menuBar_(menuBar)
	{

	}

	MenuManager::~MenuManager()
	{

	}

	void MenuManager::addMenu(Menu* menu)
	{
		if (menuBar_ && menu){
			menuBar_->addMenu(menu);
		}
	}

	void MenuManager::addAction(IAction* action)
	{
		if (menuBar_ && action){
			menuBar_->addAction(action);
		}
	}
}
