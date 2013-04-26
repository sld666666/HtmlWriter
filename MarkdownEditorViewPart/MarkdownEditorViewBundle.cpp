#include "MarkdownEditorViewBundle.h"
#include "ServiceManager.h"


MarkdownEditorViewBundle::MarkdownEditorViewBundle()
:markdownEditorViewPart_(new MarkdownEditorViewPart())
{

}

MarkdownEditorViewBundle::~MarkdownEditorViewBundle()
{

}

void MarkdownEditorViewBundle::start( BundleContext* context )const
{
	if (markdownEditorViewPart_){
		ServiceManager::instance().appendService(markdownEditorViewPart_);
	}
}

void MarkdownEditorViewBundle::stop( BundleContext* context )const
{

}

BundleConfigPtr MarkdownEditorViewBundle::getBundlelConfig() const
{
	BundleConfigPtr bundConfig(new BundleConfig(
		service::RegisteredSevice::BENCHVIEW
		, BUNDELNAME));
	return bundConfig;
}
