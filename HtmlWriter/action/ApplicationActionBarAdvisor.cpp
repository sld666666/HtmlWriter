#include "ApplicationActionBarAdvisor.h"
#include "action/Menu.h"

ApplicationActionBarAdvisor::ApplicationActionBarAdvisor(ActionConfigurerPtr actionConfig)
	: ActionBarAdvisor(actionConfig)
{
	init(actionConfig);
}

ApplicationActionBarAdvisor::~ApplicationActionBarAdvisor()
{

}

void ApplicationActionBarAdvisor::makeActions()
{
	OpenAction_ = new OpenAction(tr("open"), NULL);
}

void ApplicationActionBarAdvisor::fillMenuBar(const MenuManagerPtr menuManager)
{
// 	Menu* fileMenu(new Menu(tr("File")));
// 	fileMenu->addAction(OpenAction_);
// 	menuManager->addMenu(fileMenu);
}
