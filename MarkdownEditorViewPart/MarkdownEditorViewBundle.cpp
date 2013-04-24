#include "MarkdownEditorViewBundle.h"


MarkdownEditorViewBundle::MarkdownEditorViewBundle()
:markdownEditorViewPart_(new MarkdownEditorViewPart())
{

}

MarkdownEditorViewBundle::~MarkdownEditorViewBundle()
{

}

void MarkdownEditorViewBundle::start( BundleContext* context )const
{
	markdownEditorViewPart_->sartService(context);
}

void MarkdownEditorViewBundle::stop( BundleContext* context )const
{

}

BundleConfigPtr MarkdownEditorViewBundle::getBundlelConfig() const
{
	BundleConfigPtr bundConfig(new BundleConfig(
		service::RegisteredSevice::BENCHVIEW
		, BUNDELNAME
		, markdownEditorViewPart_));
	return bundConfig;
}
