#include "MarkdownEditorViewBundle.h"
#include "MarkdownEditorViewPart.h"

MarkdownEditorViewBundle::MarkdownEditorViewBundle()
{

}

MarkdownEditorViewBundle::~MarkdownEditorViewBundle()
{

}

void MarkdownEditorViewBundle::start( BundleContext* context )const
{
	if (!context)return;

	QWidget* parent = static_cast<QWidget*>(context->getParent());
 	MarkdownEditorViewPart	directoryViewPart;
 	directoryViewPart.createPartControl(parent);
}

void MarkdownEditorViewBundle::stop( BundleContext* context )const
{

}

BundleConfigPtr MarkdownEditorViewBundle::getBundlelConfig() const
{
	BundleConfigPtr bundConfig(new BundleConfig(
		service::RegisteredSevice::BENCHVIEW, "MarkdownEditorViewPart.dll"));
	return bundConfig;
}
