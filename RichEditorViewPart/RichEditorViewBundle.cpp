#include "RichEditorViewBundle.h"
#include "ServiceManager.h"


RichEditorViewBundle::RichEditorViewBundle()
:richEditorViewPart_(new RichEditorViewPart())
{

}

RichEditorViewBundle::~RichEditorViewBundle()
{

}

void RichEditorViewBundle::start( BundleContext* context )const
{
	if (richEditorViewPart_){
		ServiceManager::instance().appendService(richEditorViewPart_);
	}
}

void RichEditorViewBundle::stop( BundleContext* context )const
{

}

BundleConfigPtr RichEditorViewBundle::getBundlelConfig() const
{
	BundleConfigPtr bundConfig(new BundleConfig(
		service::RegisteredSevice::BENCHVIEW
		, RICHEDITORBUNDELNAME));
	return bundConfig;
}

