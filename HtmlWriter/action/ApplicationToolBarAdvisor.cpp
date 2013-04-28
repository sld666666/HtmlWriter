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
	
}

void ApplicationToolBarAdvisor::fillMenuBar(const MenuManagerPtr menuManager)
{

}
