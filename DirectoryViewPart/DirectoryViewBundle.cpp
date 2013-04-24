#include "DirectoryViewBundle.h"


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
		directoryViewPart_->sartService(context);
	}
}

void DirectoryViewBundle::stop( BundleContext* context )const
{

}

BundleConfigPtr DirectoryViewBundle::getBundlelConfig() const
{
	BundleConfigPtr bundConfig(new BundleConfig(
		service::RegisteredSevice::BENCHVIEW
		, BUNDELNAME
		, directoryViewPart_));
	return bundConfig;
}
