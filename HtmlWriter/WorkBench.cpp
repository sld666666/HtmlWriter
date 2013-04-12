#include <QDockWidget>
#include "WorkBench.h"
#include "BundleFunctors.h"
#include "BundlesContainer.h"
#include "UiHelper.h"


WorkBench::WorkBench(QWidget *parent)
	: QMainWindow(parent)
{
 	ui.setupUi(this);

	service::ServiceLoader serviceLoader;
	serviceLoader.loadPlugins();


	vector<IBundle*> bundles = BundlesContainer::instance().getBundles();
	vector<IBundle*> benchViewBundle(bundles.size());
	remove_copy_if(bundles.begin(), bundles.end(), benchViewBundle.begin()
		, bind(&BundleFunctors::notMatched, _1, RegisteredSevice::BENCHVIEW));

	for_each(benchViewBundle.begin(), benchViewBundle.end()
		, bind(&WorkBench::appendDockWidget, this, _1));
}

WorkBench::~WorkBench()
{

}

void WorkBench::appendDockWidget(const IBundle* bundle)
{
	if (!bundle)return;

	QString name = QString::fromStdString(bundle->getBundlelConfig()->getDllName());
	QDockWidget *dock = new QDockWidget(name, this);
	QWidget* widget = new QWidget(dock);
	UiUtils::UiHelper::updateWidgetWithVLayout(widget);
	dock->setWidget(widget);
	addDockWidget(Qt::LeftDockWidgetArea, dock, Qt::Horizontal);
	BundleContext* context(new BundleContext());
 	context->setParent(widget);
	bundle->start(context);
}
