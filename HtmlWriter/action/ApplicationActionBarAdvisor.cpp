#include "ApplicationActionBarAdvisor.h"
#include "action/Menu.h"
#include "action/IToolBar.h"
#include "ServiceFunctors.h"
#include "AlgorithmEx.h"
#include "FunctionUtils.h"

using namespace utils;

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
	vector<IService*> menuServices;
	copy_if(service.begin(), service.end(), back_inserter(menuServices)
		, bind(&ServiceFunctors::matchedByType, _1, ST_MENU));

	for_each(menuServices.begin(), menuServices.end()
		, bind(&ApplicationActionBarAdvisor::appendMenuBar, this, _1, menuBar));
}

void ApplicationActionBarAdvisor::fillToolBar(QMainWindow* mainWnd)
{
	vector<IService*> service = ServiceManager::instance().getServices();
	vector<IService*> toolBarServices;
	remove_copy_if(service.begin(), service.end(), back_inserter(toolBarServices)
		, bind(&ServiceFunctors::noMatchedByType, _1, ST_TOOLBAR));

	sort(toolBarServices.begin(), toolBarServices.end(), ServiceFunctors::smallerId);

	for_each(toolBarServices.begin(), toolBarServices.end()
		, bind(&ApplicationActionBarAdvisor::appendToolBar, this, _1, mainWnd));
}



void ApplicationActionBarAdvisor::appendToolBar(IService* service
												, QMainWindow* mainWnd)
{
	if (!service || !mainWnd) return;

	IToolBar* toolBar = static_cast<IToolBar*>(service);
	if (toolBar){
		mainWnd->addToolBar(toolBar);
		toolBar->fills();
	}
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

