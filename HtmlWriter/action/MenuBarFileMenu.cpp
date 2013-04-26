#include "MenuBarFileMenu.h"
#include "OpenAction.h"
#include "SaveAction.h"
#include "SaveAsAction.h"

MenuBarFileMenu::MenuBarFileMenu(QWidget * parent)
	: Menu( tr("&File"), parent)
{

}

MenuBarFileMenu::~MenuBarFileMenu()
{

}

ServiceConfigPtr MenuBarFileMenu::getServiceConfig() const
{
	return ServiceConfigPtr(new ServiceConfig(ST_MENU, "MenuBarFileMenu"));
}

vector<IAction*> MenuBarFileMenu::getActions()
{
	vector<IAction*>  actions;
	actions.push_back(new OpenAction(tr("&open")));
	actions.push_back(new SaveAction(tr("&save")));
	actions.push_back(new SaveAsAction(tr("&saveAs")));
	return actions;
}
