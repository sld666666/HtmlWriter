#include "MenuBarToolMenu.h"

MenuBarToolMenu::MenuBarToolMenu(QWidget * parent)
	: Menu( tr("&Tool"), parent)
{

}

MenuBarToolMenu::~MenuBarToolMenu()
{

}

ServiceConfigPtr MenuBarToolMenu::getServiceConfig() const
{
	return ServiceConfigPtr(new ServiceConfig(ST_MENU, "MenuBarToolMenu"));
}

vector<IAction*> MenuBarToolMenu::getActions()
{
	vector<IAction*>  actions;

	return actions;
}
