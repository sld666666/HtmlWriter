#ifndef MARKDOWNEDITORWIDGET_H
#define MARKDOWNEDITORWIDGET_H

#include <QWidget>
#include "ui_MarkdownEditorWidget.h"
#include "markdowneditorviewpart_global.h"

class MarkdownEditorWidget : public QWidget
{
	Q_OBJECT

public:
	MarkdownEditorWidget(QWidget *parent = 0);
	~MarkdownEditorWidget();

private:
	Ui::MarkdownEditorWidget ui;
};

#endif // MARKDOWNEDITORWIDGET_H
