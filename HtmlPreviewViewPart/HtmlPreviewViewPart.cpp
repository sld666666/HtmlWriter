#include "HtmlPreviewViewPart.h"

HtmlPreviewViewPart::HtmlPreviewViewPart()
: htmlPreviewWidget_(NULL)
{

}

HtmlPreviewViewPart::~HtmlPreviewViewPart()
{

}

long HtmlPreviewViewPart::serviceId()
{
	return RegisteredSeviceID::RSI_VIEW_HTMLPREVIEW;
}

void HtmlPreviewViewPart::reflesh(const QString& filePath)
{
	if (htmlPreviewWidget_){
		htmlPreviewWidget_->reflesh(filePath);
	}
}

void HtmlPreviewViewPart::createPartControl(QWidget* parent)
{
	if (!parent)return;

	htmlPreviewWidget_ = new HtmlPreviewWidget(parent);
	parent->layout()->addWidget(htmlPreviewWidget_);
}
