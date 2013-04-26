#include "DirectoryViewPart.h"

DirectoryViewPart::DirectoryViewPart()
: directoryViewWidget_(NULL)
{

}

DirectoryViewPart::~DirectoryViewPart()
{

}

ServiceConfigPtr DirectoryViewPart::getServiceConfig() const
{
	ServiceConfigPtr serviceConfig(new ServiceConfig(ST_VIEW, DIR_VIEW_SERVICENAME));
	return serviceConfig;
}

void DirectoryViewPart::createPartControl(QWidget* parent)
{
	if (!parent)return;

	directoryViewWidget_ = new DirectoryViewWidget(parent);
	parent->layout()->addWidget(directoryViewWidget_);
}

void DirectoryViewPart::reflesh(const QString& filePath)
{

}

DirectoryViewWidget*	DirectoryViewPart::getDirectoryViewWidget() const
{
	return directoryViewWidget_;
}