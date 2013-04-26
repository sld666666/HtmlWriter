#include "MenuBarViewMenu.h"

MenuBarViewMenu::MenuBarViewMenu(QWidget * parent)
	: Menu( tr("&Editor"), parent)
{

}

MenuBarViewMenu::~MenuBarViewMenu()
{

}

ServiceConfigPtr MenuBarViewMenu::getServiceConfig() const
{
	return ServiceConfigPtr(new ServiceConfig(ST_MENU, "MenuBarViewMenu"));
}


vector<IAction*> MenuBarViewMenu::getActions()
{
	vector<IAction*>  actions;

	return actions;
}
