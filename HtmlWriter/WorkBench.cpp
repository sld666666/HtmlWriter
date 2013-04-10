#include <QDockWidget>
#include "WorkBench.h"
#include "pluginconfig.h"
#include "ServiceLoader.h"

WorkBench::WorkBench(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	service::ServiceLoader serviceLoader;
	serviceLoader.loadPlugins();

//  	vector<string> stdpulginsStr = PluginConfig::instance().getPlugins();
//  	vector<QString> qtStrs(stdpulginsStr.size());
// 
// 	transform(stdpulginsStr.begin(), stdpulginsStr.end(), qtStrs.begin()
// 		,QString::fromStdString);
// 
// 	for_each(qtStrs.begin(), qtStrs.end()
// 		, boost::bind(&WorkBench::appendDockWidget, this,  _1));

}

WorkBench::~WorkBench()
{

}

void WorkBench::appendDockWidget(const QString& name)
{
	QDockWidget *dock = new QDockWidget(name, this);
	QWidget* widget = new QWidget(dock);
	dock->setWidget(widget);
	addDockWidget(Qt::RightDockWidgetArea, dock, Qt::Horizontal);
}
