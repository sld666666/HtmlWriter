#include "RichEditorToolBar.h"
#include "action/ActionHelper.h"
#include "RichBoldAction.h"
#include "RichItalicAction.h"
#include "RichUnderlineAction.h"
#include "RichAlignLeftAction.h"
#include "RichAlignCenterAction.h"
#include "RichAlignRightAction.h"
#include "RichAlignJustifyAction.h"
#include "RichTextColorAction.h"

RichEditorToolBar::RichEditorToolBar(QWidget *parent)
	: IToolBar(parent)
{

}

RichEditorToolBar::~RichEditorToolBar()
{

}
vector<IAction*> RichEditorToolBar::getActions()
{
	vector<IAction*> actions;
	actions.push_back(new RichBoldAction());
	actions.push_back(new RichItalicAction());
	actions.push_back(new RichUnderlineAction());
	actions.push_back(new RichAlignLeftAction());
	actions.push_back(new RichAlignCenterAction());
	actions.push_back(new RichAlignRightAction());
	actions.push_back(new RichAlignJustifyAction());
	actions.push_back(new RichTextColorAction());
	return actions;
}

long RichEditorToolBar::serviceId()
{
	return RegisteredSeviceID::RSI_TOOLBAR_MARKDOWNEDITOR;
}