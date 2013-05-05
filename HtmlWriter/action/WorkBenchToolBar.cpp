#include "WorkBenchToolBar.h"
#include "action/ActionHelper.h"

WorkBenchToolBar::WorkBenchToolBar(QWidget *parent)
	: IToolBar(parent)
{

}

WorkBenchToolBar::~WorkBenchToolBar()
{

}
vector<IAction*> WorkBenchToolBar::getActions()
{
	vector<long> fillIds;
	fillIds.push_back(RegisteredSeviceID::RSI_ACTION_OPEN);
	fillIds.push_back(RegisteredSeviceID::RSI_ACTION_SAVE);
	fillIds.push_back(RegisteredSeviceID::RSI_ACTION_SAVEAS);
	vector<IAction*> actions = ActionHelper::getActions(fillIds);
	return actions;
}

long WorkBenchToolBar::serviceId()
{
	return RegisteredSeviceID::RSI_TOOLBAR_WORKBENCH;
}