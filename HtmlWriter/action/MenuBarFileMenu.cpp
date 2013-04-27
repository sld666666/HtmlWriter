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

long MenuBarFileMenu::serviceId()
{
	return RegisteredSeviceID::RSI_MENU_FILE;
}

vector<IAction*> MenuBarFileMenu::getActions()
{
	vector<IAction*>  actions;
	actions.push_back(new OpenAction(tr("&open")));
	actions.push_back(new SaveAction(tr("&save")));
	actions.push_back(new SaveAsAction(tr("&saveAs")));
	return actions;
}
