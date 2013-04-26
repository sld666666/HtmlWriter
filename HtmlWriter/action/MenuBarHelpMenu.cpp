#include "MenuBarHelpMenu.h"

MenuBarHelpMenu::MenuBarHelpMenu(QWidget * parent)
	: Menu( tr("&Help"), parent)
{

}

MenuBarHelpMenu::~MenuBarHelpMenu()
{

}

ServiceConfigPtr MenuBarHelpMenu::getServiceConfig() const
{
	return ServiceConfigPtr(new ServiceConfig(ST_MENU, "MenuBarHelpMenu"));
}

vector<IAction*> MenuBarHelpMenu::getActions()
{
	vector<IAction*>  actions;

	return actions;
}
