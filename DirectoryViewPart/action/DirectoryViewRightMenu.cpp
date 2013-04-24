#include "DirectoryViewRightMenu.h"
#include "DirectoryViewActions.h"

DirectoryViewRightMenu::DirectoryViewRightMenu(IContext* context, QWidget* parent )
: UiUtils::Menu(context, parent)
{

}

DirectoryViewRightMenu::~DirectoryViewRightMenu()
{

}


vector<IAction*> DirectoryViewRightMenu::getActions()
{
	vector<UiUtils::IAction*>  actions;
	actions.push_back(new NewFolderAction("&new folder",this));
	actions.push_back(new NewFileAction("&new file",this));
	actions.push_back(new DeleteAction("&delete",this));
	return actions;
}