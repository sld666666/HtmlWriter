#include "MenuBarViewMenu.h"

MenuBarViewMenu::MenuBarViewMenu(QWidget * parent)
	: Menu( tr("&Editor"), parent)
{

}

MenuBarViewMenu::~MenuBarViewMenu()
{

}

long MenuBarViewMenu::serviceId()
{
	return RegisteredSeviceID::RSI_MENU_VIEW;
}


vector<IAction*> MenuBarViewMenu::getActions()
{
	vector<IAction*>  actions;

	return actions;
}
