#include "MarkdownEditorViewPart.h"

MarkdownEditorViewPart::MarkdownEditorViewPart()
: markdownEditorWidget_(NULL)
{

}

MarkdownEditorViewPart::~MarkdownEditorViewPart()
{

}

long MarkdownEditorViewPart::serviceId()
{
	return RegisteredSeviceID::RSI_EDITOR_MARKDOWNEDITORVIEW;
}

void MarkdownEditorViewPart::reflesh(const QString& filePath)
{
	markdownEditorWidget_->reflesh(filePath);
}

void MarkdownEditorViewPart::createPartControl(QWidget* parent)
{
	if (!parent)return;
	
	markdownEditorWidget_ =	new MarkdownEditorWidget(parent);
	parent->layout()->addWidget(markdownEditorWidget_);

}

void MarkdownEditorViewPart::doSave()
{

}

void MarkdownEditorViewPart::doSaveAs()
{

}
