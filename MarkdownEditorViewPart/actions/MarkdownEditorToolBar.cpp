#include "MarkdownEditorToolBar.h"
#include "action/ActionHelper.h"
#include "MarkdownAlignCenterAction.h"
#include "MarkdownAlignJustifyAction.h"
#include "MarkdownAlignLeftAction.h"
#include "MarkdownAlignRightAction.h"
#include "MarkdownBoldAction.h"
#include "MarkdownItalicAction.h"
#include "MarkdownTextColorAction.h"
#include "MarkdownUnderlineAction.h"

#include "MarkdownHeaderAction.h"
#include "MarkdownBlockAction.h"
#include "MarkdownDivLineAction.h"
#include "MarkdownImageAction.h"
#include "MarkdownLinkAction.h"
#include "MarkdownListAction.h"


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
	actions.push_back(new MarkdownHeaderAction());
	actions.push_back(new MarkdownBlockAction());
	actions.push_back(new MarkdownDivLineAction());
	actions.push_back(new MarkdownListAction());
	actions.push_back(new MarkdownLinkAction());
	actions.push_back(new MarkdownImageAction());
	return actions;
}

long MarkdownEditorToolBar::serviceId()
{
	return RegisteredSeviceID::RSI_TOOLBAR_MARKDOWNEDITOR;
}