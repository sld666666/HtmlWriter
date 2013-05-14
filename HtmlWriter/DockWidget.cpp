#include <QTimer>
#include "DockWidget.h"
#include "workbench/IWorkbenchPart.h"

using namespace UiUtils;

DockWidget::DockWidget(IService* service,QMainWindow *parent)
	: QDockWidget(parent)
	, curServiceId_(service->serviceId())
	, widget_(NULL)
{
	initDockWidget(service, parent);
	this->installEventFilter(this);
	adaptSize();
}

DockWidget::~DockWidget()
{

}

void DockWidget::initDockWidget( IService* service
								, QMainWindow * parent ) 
{
	QString name = QString::fromStdString(service->getServiceConfig()->getServiceName());
	this->setWindowTitle(name);
	widget_ = new QWidget(this);
	UiUtils::UiHelper::updateWidgetWithVLayout(widget_);
	this->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	this->setWidget(widget_);
	//widget_->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 0, 0);"));
	parent->setCentralWidget(this);
	parent->addDockWidget(Qt::LeftDockWidgetArea, this, Qt::Horizontal);
	IWorkbenchPart* workBench = static_cast<IWorkbenchPart*>(service);
	if (workBench){
		workBench->createPartControl(widget_);
	}
}

void DockWidget::adaptSize() 
{
	XmlViewsConfigPtr viewConfig = getXmlViewsConfig(curServiceId_);
	if (viewConfig.get()){
		this->setVisible(viewConfig->visible());
		if (viewConfig->width()>0){
			qint32 width = viewConfig->width();
			setDockSize(width,  this->height());
		}
	}
}

bool DockWidget::eventFilter(QObject *obj, QEvent *event)
{
	if (obj == this) {
		if (event->type() == QEvent::Resize) {
			XmlViewsConfigPtr viewConfig = getXmlViewsConfig(curServiceId_);
			if (viewConfig.get()){
				qint32 width = this->width();
				viewConfig->setWidth(width);
			}	
		}
	}

	return QDockWidget::eventFilter(obj, event);
}

XmlViewsConfigPtr DockWidget::getXmlViewsConfig(long id)
{
	vector<XmlViewsConfigPtr> viewConfigs = XmlConfigManager::instance().getViewsConfigs();
	vector<XmlViewsConfigPtr>::iterator iter = find_if(viewConfigs.begin(), viewConfigs.end()
		, bind(&XmlViewConfigFunctor::isIdMatched, _1, curServiceId_));

	return (iter != viewConfigs.end())?(*iter):XmlViewsConfigPtr(); 
}

void DockWidget::setDockSize(int width
							 , int height)
{
	oldMaxSize_=this->maximumSize();
	oldMinSize_=this->minimumSize();

	if (width>=0){
		if (this->width()<width)
			this->setMinimumWidth(width);
		else
			this->setMaximumWidth(width);
	}

	if (height>=0){
		if (this->height()<height)
			this->setMinimumHeight(height);
		else
			this->setMaximumHeight(height);
	}
	QTimer::singleShot(1, this, SLOT(returnToOldMaxMinSizes()));
}

void DockWidget::returnToOldMaxMinSizes()
{
	this->setMinimumSize(oldMinSize_);
	this->setMaximumSize(oldMaxSize_);
}
