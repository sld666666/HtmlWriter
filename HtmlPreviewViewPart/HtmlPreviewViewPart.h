#ifndef HTMLPREVIEWVIEWPART_H
#define HTMLPREVIEWVIEWPART_H

#include "htmlpreviewviewpart_global.h"
#include "workbench/IViewPart.h"
#include "HtmlPreviewWidget.h"

using namespace UiUtils;

class  HtmlPreviewViewPart : public IViewPart
{
public:
	HtmlPreviewViewPart();
	~HtmlPreviewViewPart();

	virtual long serviceId();

	virtual void reflesh(const QString& filePath);

	virtual void createPartControl(QWidget* parent);

private:
	HtmlPreviewWidget*	htmlPreviewWidget_;
};

#endif // HTMLPREVIEWVIEWPART_H
