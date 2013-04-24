#include "HtmlPreviewBundle.h"


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
		htmlPreviewViewPart_->sartService(context);
	}
}

void HtmlPreviewBundle::stop( BundleContext* context )const
{

}

BundleConfigPtr HtmlPreviewBundle::getBundlelConfig() const
{
	BundleConfigPtr bundConfig(new BundleConfig(
		service::RegisteredSevice::BENCHVIEW
		, "HtmlPreviewBundle.dll"
		, htmlPreviewViewPart_));
	return bundConfig;
}
