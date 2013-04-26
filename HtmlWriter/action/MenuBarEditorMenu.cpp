#include "MenuBarEditorMenu.h"

MenuBarEditorMenu::MenuBarEditorMenu(QWidget * parent)
	: Menu( tr("&Editor"), parent)
{

}

MenuBarEditorMenu::~MenuBarEditorMenu()
{

}

ServiceConfigPtr MenuBarEditorMenu::getServiceConfig() const
{
	return ServiceConfigPtr(new ServiceConfig(ST_MENU, "MenuBarEditorMenu"));
}

vector<IAction*> MenuBarEditorMenu::getActions()
{
	vector<IAction*>  actions;

	return actions;
}
