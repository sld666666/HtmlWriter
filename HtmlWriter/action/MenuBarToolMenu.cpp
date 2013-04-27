#include "MenuBarToolMenu.h"

MenuBarToolMenu::MenuBarToolMenu(QWidget * parent)
	: Menu( tr("&Tool"), parent)
{

}

MenuBarToolMenu::~MenuBarToolMenu()
{

}

long MenuBarToolMenu::serviceId()
{
	return RegisteredSeviceID::RSI_MENU_TOOL;
}

vector<IAction*> MenuBarToolMenu::getActions()
{
	vector<IAction*>  actions;

	return actions;
}
