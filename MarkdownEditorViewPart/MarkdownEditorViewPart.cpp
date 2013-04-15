#include "MarkdownEditorViewPart.h"


MarkdownEditorViewPart::MarkdownEditorViewPart()
{

}

MarkdownEditorViewPart::~MarkdownEditorViewPart()
{

}

void MarkdownEditorViewPart::createPartControl(QWidget* parent)
{
	if (!parent)return;
	
	MarkdownEditorWidget* markdownEditorWidget(
		new MarkdownEditorWidget(parent));

}
