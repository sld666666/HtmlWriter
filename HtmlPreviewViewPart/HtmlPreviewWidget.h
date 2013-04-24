#ifndef HTMLPREVIEWWIDGET_H
#define HTMLPREVIEWWIDGET_H

#include <QWidget>
#include "ui_HtmlPreviewWidget.h"

class HtmlPreviewWidget : public QWidget
{
	Q_OBJECT

public:
	HtmlPreviewWidget(QWidget *parent = 0);
	~HtmlPreviewWidget();

	void reflesh(const QString& filePath);

private:
	Ui::HtmlPreviewWidget ui;
};

#endif // HTMLPREVIEWWIDGET_H
