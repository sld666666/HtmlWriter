#include "ApplicationToolBarAdvisor.h"
#include "action/Menu.h"

ApplicationToolBarAdvisor::ApplicationToolBarAdvisor(ActionConfigurerPtr actionConfig)
	: ActionBarAdvisor(actionConfig)
{
	init(actionConfig);
}

ApplicationToolBarAdvisor::~ApplicationToolBarAdvisor()
{

}

void ApplicationToolBarAdvisor::makeActions()
{
	OpenAction_ = new OpenAction(tr("open"), NULL);
}

void ApplicationToolBarAdvisor::fillMenuBar(const MenuManagerPtr menuManager)
{
// 	Menu* fileMenu(new Menu(tr("File")));
// 	fileMenu->addAction(OpenAction_);
// 	menuManager->addMenu(fileMenu);
}
