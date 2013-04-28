#include "MenuBarFileMenu.h"
#include "OpenAction.h"
#include "SaveAction.h"
#include "SaveAsAction.h"
#include "action/ActionHelper.h"

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
	vector<long> actionIds;
	actionIds.push_back(RegisteredSeviceID::RSI_ACTION_OPEN);
	actionIds.push_back(RegisteredSeviceID::RSI_ACTION_SAVE);
	actionIds.push_back(RegisteredSeviceID::RSI_ACTION_SAVEAS);
	
	return ActionHelper::getActions(actionIds);
}
