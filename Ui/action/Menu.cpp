#include "Menu.h"

namespace UiUtils{
	Menu::Menu(const QString& title, QWidget * parent)
		: QMenu(title, parent)
	{

	}

	Menu::~Menu()
	{

	}

	void Menu::add(IAction* action)
	{
		if (action){
			this->addAction(action);
		}
	}
}