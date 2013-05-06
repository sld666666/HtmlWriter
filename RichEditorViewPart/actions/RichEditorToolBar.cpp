#include "RichEditorToolBar.h"
#include "action/ActionHelper.h"
#include "RichBoldAction.h"
#include "RichItalicAction.h"
#include "RichUnderlineAction.h"

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
	return actions;
}

long RichEditorToolBar::serviceId()
{
	return RegisteredSeviceID::RSI_TOOLBAR_MARKDOWNEDITOR;
}