#include "ActionBarAdvisor.h"

namespace UiUtils{

	ActionBarAdvisor::ActionBarAdvisor(ActionConfigurerPtr actionConfig)
	{
		Q_ASSERT(actionConfig.get());
	}

	ActionBarAdvisor::~ActionBarAdvisor()
	{

	}

	void ActionBarAdvisor::init(ActionConfigurerPtr actionConfig)
	{
		makeActions();
		fillMenuBar(actionConfig->getMenuManager());
		fillCoolBar();
	}

	void ActionBarAdvisor::makeActions()
	{

	}

	void ActionBarAdvisor::fillMenuBar(const MenuManagerPtr menuManager)
	{
	}

	void ActionBarAdvisor::fillCoolBar()
	{

	}

}

