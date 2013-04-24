#include "MenuBarFileMenu.h"

MenuBarFileMenu::MenuBarFileMenu(IContext* context, QWidget * parent)
	: Menu( tr("&File"), context, parent)
{

}

MenuBarFileMenu::~MenuBarFileMenu()
{

}

vector<IAction*> MenuBarFileMenu::getActions()
{
	vector<IAction*>  actions;

	return actions;
}
