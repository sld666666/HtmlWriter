#include "MenuBarEditorMenu.h"

MenuBarEditorMenu::MenuBarEditorMenu(QWidget * parent)
	: Menu( tr("&Editor"), parent)
{

}

MenuBarEditorMenu::~MenuBarEditorMenu()
{

}

long MenuBarEditorMenu::serviceId()
{
	return RegisteredSeviceID::RSI_MENU_EDITOR;
}

vector<IAction*> MenuBarEditorMenu::getActions()
{
	vector<IAction*>  actions;

	return actions;
}
