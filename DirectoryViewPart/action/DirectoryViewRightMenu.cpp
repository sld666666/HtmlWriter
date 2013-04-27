#include "DirectoryViewRightMenu.h"
#include "DirectoryViewActions.h"

DirectoryViewRightMenu::DirectoryViewRightMenu(QWidget* parent )
: UiUtils::Menu(parent)
{

}

DirectoryViewRightMenu::~DirectoryViewRightMenu()
{

}



long DirectoryViewRightMenu::serviceId()
{
	return RegisteredSeviceID::RSI_UNREGISTER;
}

vector<IAction*> DirectoryViewRightMenu::getActions()
{
	vector<UiUtils::IAction*>  actions;
	actions.push_back(new NewFolderAction("&new folder",this));
	actions.push_back(new NewFileAction("&new file",this));
	actions.push_back(new DeleteAction("&delete",this));
	return actions;
}