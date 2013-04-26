#include "DirectoryViewBundle.h"
#include "ServiceManager.h"


DirectoryViewBundle::DirectoryViewBundle()
:directoryViewPart_(new DirectoryViewPart())
{

}

DirectoryViewBundle::~DirectoryViewBundle()
{

}

void DirectoryViewBundle::start( BundleContext* context )const
{
	if (directoryViewPart_){
		ServiceManager::instance().appendService(directoryViewPart_);
	}
}

void DirectoryViewBundle::stop( BundleContext* context )const
{

}

BundleConfigPtr DirectoryViewBundle::getBundlelConfig() const
{
	BundleConfigPtr bundConfig(new BundleConfig(
		service::RegisteredSevice::BENCHVIEW
		, DIR_VIEW_BUNDELNAME));
	return bundConfig;
}
