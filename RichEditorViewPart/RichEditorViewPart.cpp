#include "RichEditorViewPart.h"

RichEditorViewPart::RichEditorViewPart()
:richEditorWidget_(NULL)
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
	if (richEditorWidget_){
		richEditorWidget_->reflesh(filePath);
	}
}

void RichEditorViewPart::createPartControl(QWidget* parent)
{
	if (!parent)return;

	richEditorWidget_ =	new RichEditorWidget(parent);
 	parent->layout()->addWidget(richEditorWidget_);

}

void RichEditorViewPart::doSave()
{
	if (richEditorWidget_){
		richEditorWidget_->save();
	}
}

void RichEditorViewPart::doSaveAs(const QString& targetPath)
{
	if (richEditorWidget_){
		richEditorWidget_->saveAs(targetPath);
	}
}

RichEditorWidget* RichEditorViewPart::getRichEditorWidget() const
{
	return richEditorWidget_;
}
