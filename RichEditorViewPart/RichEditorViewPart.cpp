#include "RichEditorViewPart.h"

RichEditorViewPart::RichEditorViewPart()
{

}

RichEditorViewPart::~RichEditorViewPart()
{

}

long RichEditorViewPart::serviceId()
{
	return RegisteredSeviceID::RSI_EDITOR_RICHEDITORVIEW;
}

void RichEditorViewPart::reflesh(const QString& filePath)
{
	
}

void RichEditorViewPart::createPartControl(QWidget* parent)
{
	if (!parent)return;

// 	markdownEditorWidget_ =	new MarkdownEditorWidget(parent);
// 	parent->layout()->addWidget(markdownEditorWidget_);

}

void RichEditorViewPart::doSave()
{
// 	if (markdownEditorWidget_){
// 		markdownEditorWidget_->save();
// 	}
}

void RichEditorViewPart::doSaveAs(const QString& targetPath)
{
// 	if (markdownEditorWidget_){
// 		markdownEditorWidget_->saveAs(targetPath);
// 	}
}
