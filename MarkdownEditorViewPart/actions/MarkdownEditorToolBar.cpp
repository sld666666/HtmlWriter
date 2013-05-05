#include "MarkdownEditorToolBar.h"
#include "action/ActionHelper.h"
#include "EditorHeaderAction.h"

MarkdownEditorToolBar::MarkdownEditorToolBar(QWidget *parent)
	: IToolBar(parent)
{

}

MarkdownEditorToolBar::~MarkdownEditorToolBar()
{

}
vector<IAction*> MarkdownEditorToolBar::getActions()
{
	vector<IAction*> actions;
	actions.push_back(new EditorHeaderAction());
	return actions;
}

long MarkdownEditorToolBar::serviceId()
{
	return RegisteredSeviceID::RSI_TOOLBAR_WORKBENCH;
}