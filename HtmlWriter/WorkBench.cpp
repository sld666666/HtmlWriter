#include <QDockWidget>
#include "WorkBench.h"
#include "BundleFunctors.h"
#include "ServiceFunctors.h"
#include "BundlesContainer.h"
#include "SelfServicesRegister.h"
#include "AlgorithmEx.h"
#include "action/WorkBenchToolBar.h"
#include "DockWidget.h"

using namespace UiUtils;
using namespace utils;

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
	initApplicaion();

}

WorkBench::~WorkBench()
{
	
}

void WorkBench::initApplicaion()
{
	XmlApplicationConfigPtr xmlAppConfig = XmlConfigManager::instance()
		.getXmlAppConfig(); 
	if (xmlAppConfig){
		if (xmlAppConfig->isMax()){
			this->showMaximized();
		}else{
			if (xmlAppConfig->width()>0){
				this->resize(xmlAppConfig->width(), this->height());
			}
			if (xmlAppConfig->height()>0){
				this->resize(this->width(), xmlAppConfig->height());
			}
		}
	}

	this->installEventFilter(this);
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
	vector<IService*> viewServices;
	copy_if(service.begin(), service.end(), back_inserter(viewServices)
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
	DockWidget* dockWidget (new DockWidget(service, this));
}

bool WorkBench::eventFilter(QObject *obj, QEvent *event)
{
	if (obj == this) {
		if (event->type() == QEvent::Resize) {
			bool isMax = this->isMaximized();
			qint32 width = this->width();
			qint32 height = this->height();
			XmlApplicationConfigPtr xmlAppConfig = XmlConfigManager::instance()
				.getXmlAppConfig(); 
			if (xmlAppConfig.get()){
				xmlAppConfig->setIsMax(isMax);
				xmlAppConfig->setWidth(width);
				xmlAppConfig->setHeight(height);
			}	
		} 
	}
	
	return QMainWindow::eventFilter(obj, event);
}

void WorkBench::closeEvent ( QCloseEvent * event )
{
	XmlConfigManager::instance().writeSaveableSetting();
	event->accept();
}