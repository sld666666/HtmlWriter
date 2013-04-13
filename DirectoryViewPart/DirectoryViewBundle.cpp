#include "DirectoryViewBundle.h"
#include "DirectoryViewPart.h"

DirectoryViewBundle::DirectoryViewBundle()
{

}

DirectoryViewBundle::~DirectoryViewBundle()
{

}

void DirectoryViewBundle::start( BundleContext* context )const
{
	if (!context)return;

	QWidget* parent = static_cast<QWidget*>(context->getParent());
	DirectoryViewPart	directoryViewPart;
	directoryViewPart.createPartControl(parent);
}

void DirectoryViewBundle::stop( BundleContext* context )const
{

}

BundleConfigPtr DirectoryViewBundle::getBundlelConfig() const
{
	BundleConfigPtr bundConfig(new BundleConfig(
		service::RegisteredSevice::BENCHVIEW, "DirectoryViewPart.dll"));
	return bundConfig;
}
