#include "EditorTabWidgetRightMenu.h"
#include "context/EditorTabWidgetContext.h"
#include "EditorTabWidgetActions.h"

namespace UiUtils{
	EditorTabWidgetRightMenu::EditorTabWidgetRightMenu(QWidget* parent )
		: IContextMenu(EditorTabWidgetContextPtr(new EditorTabWidgetContext(parent)) 
						, NULL, parent)
	{

	}

	EditorTabWidgetRightMenu::~EditorTabWidgetRightMenu()
	{

	}

	vector<IContextAction*> EditorTabWidgetRightMenu::getActions()
	{
		vector<IContextAction*>  actions;
		actions.push_back(new OpenFolderAction(this));
		actions.push_back(new CloseEditorAction(this));
		actions.push_back(new CloseOtherEditorsAction(this));
		return actions;
	}
}
