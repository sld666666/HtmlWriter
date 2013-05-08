#include "SelfServicesRegister.h"
#include "action/MenuBarFileMenu.h"
#include "action/MenuBarEditorMenu.h"
#include "action/MenuBarViewMenu.h"
#include "action/MenuBarToolMenu.h"
#include "action/MenuBarHelpMenu.h"
#include "action/SaveAction.h"
#include "action/OpenAction.h"
#include "action/SaveAsAction.h"
#include "action/WorkBenchToolBar.h"
#include "ServiceManager.h"

using namespace service;

SelfServicesRegister::SelfServicesRegister(QObject *parent)
	: QObject(parent)
{

}

SelfServicesRegister::~SelfServicesRegister()
{

}

void SelfServicesRegister::registerMenu(QWidget * parent)
{
	ServiceManager::instance().appendService(new MenuBarFileMenu(parent));
	ServiceManager::instance().appendService(new MenuBarEditorMenu(parent));
	ServiceManager::instance().appendService(new MenuBarViewMenu(parent));
	ServiceManager::instance().appendService(new MenuBarToolMenu(parent));
	ServiceManager::instance().appendService(new MenuBarHelpMenu(parent));
}
void SelfServicesRegister::registerAction()
{
	ServiceManager::instance().appendService(new SaveAction());
	ServiceManager::instance().appendService(new OpenAction());
	ServiceManager::instance().appendService(new SaveAsAction());
}

void SelfServicesRegister::registerToolBar(QWidget * parent)
{
	ServiceManager::instance().appendService(new WorkBenchToolBar(parent));
}
