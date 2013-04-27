#include "MenuBarHelpMenu.h"

MenuBarHelpMenu::MenuBarHelpMenu(QWidget * parent)
	: Menu( tr("&Help"), parent)
{

}

MenuBarHelpMenu::~MenuBarHelpMenu()
{

}

long MenuBarHelpMenu::serviceId()
{
	return RegisteredSeviceID::RSI_MENU_HELP;
}

vector<IAction*> MenuBarHelpMenu::getActions()
{
	vector<IAction*>  actions;

	return actions;
}
