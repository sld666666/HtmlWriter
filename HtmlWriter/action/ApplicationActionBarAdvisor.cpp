#include "ApplicationActionBarAdvisor.h"
#include "action/Menu.h"
#include "ServiceFunctors.h"
#include "AlgorithmEx.h"

ApplicationActionBarAdvisor::ApplicationActionBarAdvisor()
{
}

ApplicationActionBarAdvisor::~ApplicationActionBarAdvisor()
{

}

void ApplicationActionBarAdvisor::makeActions()
{
	
}

void ApplicationActionBarAdvisor::fillMenuBar(QMenuBar* menuBar)
{
	vector<IService*> service = ServiceManager::instance().getServices();
	vector<IService*> menuServices(service.size());
	copy_if(service.begin(), service.end(), menuServices.begin()
		, bind(&ServiceFunctors::matchedByType, _1, ST_MENU));

	for_each(menuServices.begin(), menuServices.end()
		, bind(&ApplicationActionBarAdvisor::appendMenuBar, this, _1, menuBar));
}

void ApplicationActionBarAdvisor::fillToolBar(QToolBar* toolBar)
{
	if (!toolBar)return;
	vector<long> fillIds;
	fillIds.push_back(RegisteredSeviceID::RSI_ACTION_OPEN);
	fillIds.push_back(RegisteredSeviceID::RSI_ACTION_SAVE);
	fillIds.push_back(RegisteredSeviceID::RSI_ACTION_SAVEAS);
	vector<IAction*> actions = ActionHelper::getActions(fillIds);
	for_each(actions.begin(), actions.end()
		, bind(&ApplicationActionBarAdvisor::appendToolAction, this, toolBar, _1));
}

void ApplicationActionBarAdvisor::appendToolAction(QToolBar* toolBar, IAction* action)
{
	if (!action)return;

	QString text = action->title();
	action->setStatusTip(text);
	toolBar->addAction(action);
}

void ApplicationActionBarAdvisor::appendMenuBar(IService* service
												, QMenuBar* menuBar)
{
	if (!service || !menuBar) return;

	Menu* menu = static_cast<Menu*>(service);
	if (menu){
		menuBar->addMenu(menu);
	}
}
