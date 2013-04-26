#include "HtmlPreviewBundle.h"
#include "ServiceManager.h"

HtmlPreviewBundle::HtmlPreviewBundle()
:htmlPreviewViewPart_(new HtmlPreviewViewPart())
{

}

HtmlPreviewBundle::~HtmlPreviewBundle()
{

}

void HtmlPreviewBundle::start( BundleContext* context )const
{
	if (htmlPreviewViewPart_){
		ServiceManager::instance().appendService(htmlPreviewViewPart_);
	}
}

void HtmlPreviewBundle::stop( BundleContext* context )const
{

}

BundleConfigPtr HtmlPreviewBundle::getBundlelConfig() const
{
	BundleConfigPtr bundConfig(new BundleConfig(
		service::RegisteredSevice::BENCHVIEW
		, "HtmlPreviewBundle.dll"));
	return bundConfig;
}
