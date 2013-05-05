#include <QDockWidget>
#include "WorkBench.h"
#include "BundleFunctors.h"
#include "ServiceFunctors.h"
#include "BundlesContainer.h"
#include "UiHelper.h"
#include "SelfServicesRegister.h"
#include "workbench/IWorkbenchPart.h"
#include "AlgorithmEx.h"
#include "action/WorkBenchToolBar.h"

using namespace UiUtils;

WorkBench::WorkBench(QWidget *parent)
	: QMainWindow(parent)
{
 	ui.setupUi(this);
	UiUtils::UiHelper::updateWidgetWithHLayout(this);

	initBundles();
	initSelfServices();
	initViewPart();
	initMenuBar();
	initToolBar();

}

WorkBench::~WorkBench()
{
	
}

void WorkBench::initSelfServices()
{
	SelfServicesRegister::registerMenu(this);
	SelfServicesRegister::registerAction();
	SelfServicesRegister::registerToolBar(this);
}

void WorkBench::initToolBar()
{
	appActionAdvisor_.fillToolBar(this);
}

void WorkBench::initMenuBar()
{
	appActionAdvisor_.fillMenuBar(menuBar());
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
