#include <QDockWidget>
#include "WorkBench.h"
#include "BundleFunctors.h"
#include "ServiceFunctors.h"
#include "BundlesContainer.h"
#include "UiHelper.h"
#include "AlgorithmEx.h"
#include "action/MenuBarFileMenu.h"
#include "action/MenuBarEditorMenu.h"
#include "action/MenuBarViewMenu.h"
#include "action/MenuBarToolMenu.h"
#include "action/MenuBarHelpMenu.h"
#include "workbench/IWorkbenchPart.h"

using namespace UiUtils;

WorkBench::WorkBench(QWidget *parent)
	: QMainWindow(parent)
{
 	ui.setupUi(this);
	UiUtils::UiHelper::updateWidgetWithHLayout(this);

	initBundles();
	initSelfServices();
	initViewPart();
	initActionBar();

}

WorkBench::~WorkBench()
{
	
}

void WorkBench::initSelfServices()
{
	ServiceManager::instance().appendService(new MenuBarFileMenu(this));
	ServiceManager::instance().appendService(new MenuBarEditorMenu(this));
	ServiceManager::instance().appendService(new MenuBarViewMenu(this));
	ServiceManager::instance().appendService(new MenuBarToolMenu(this));
	ServiceManager::instance().appendService(new MenuBarHelpMenu(this));
}

void WorkBench::initActionBar()
{
	vector<IService*> service = ServiceManager::instance().getServices();
	vector<IService*> menuServices(service.size());
	copy_if(service.begin(), service.end(), menuServices.begin()
		, bind(&ServiceFunctors::matchedByType, _1, ST_MENU));

	for_each(menuServices.begin(), menuServices.end()
		, bind(&WorkBench::appendMenuBar, this, _1));
}

void WorkBench::appendMenuBar(IService* service)
{
	if (!service) return;

	Menu* menu = static_cast<Menu*>(service);
	if (menu){
		 menuBar()->addMenu(menu);
	}
}

void WorkBench::initViewPart()
{
	vector<IService*> service = ServiceManager::instance().getServices();

	vector<IService*> viewServices(service.size());
	copy_if(service.begin(), service.end(), viewServices.begin()
		, bind(&ServiceFunctors::isViewOrEditorService, _1));

	for_each(viewServices.begin(), viewServices.end()
		, bind(&WorkBench::appendDockWidget, this, _1));

}

void WorkBench::initBundles() 
{
	service::ServiceLoader serviceLoader;
	serviceLoader.loadPlugins();

	vector<IBundle*> bundles = BundlesContainer::instance().getBundles();
	vector<IBundle*> benchViewBundle(bundles.size());
	remove_copy_if(bundles.begin(), bundles.end(), benchViewBundle.begin()
		, bind(&BundleFunctors::notMatched, _1, RegisteredSevice::BENCHVIEW));

	for_each(benchViewBundle.begin(), benchViewBundle.end()
		, bind(&WorkBench::startBundle, this, _1));
}

void WorkBench::startBundle(const IBundle* bundle)
{
	if (bundle) bundle->start(NULL);
}

void WorkBench::appendDockWidget(IService* service)
{
	if (!service)return;

	QString name = QString::fromStdString(service->getServiceConfig()->getServiceName());
	QDockWidget *dock = new QDockWidget(name, this);
	QWidget* widget = new QWidget(dock);
	UiUtils::UiHelper::updateWidgetWithHLayout(widget);
	widget->setMinimumWidth(200);
	dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	dock->setWidget(widget);
	setCentralWidget(dock);
	addDockWidget(Qt::LeftDockWidgetArea, dock, Qt::Horizontal);
	IWorkbenchPart* workBench = static_cast<IWorkbenchPart*>(service);
	if (workBench){
		workBench->createPartControl(widget);
	}
}
