#ifndef MARKDOWNEDITORWIDGET_H
#define MARKDOWNEDITORWIDGET_H

#include <QWidget>
#include "markdowneditorviewpart_global.h"
#include "ui_MarkdownEditorWidget.h"
#include "markdowneditorviewpart_global.h"
#include "MarkdownTextEdit.h"

class MarkdownEditorWidget : public QWidget
{
	Q_OBJECT

public:
	MarkdownEditorWidget(QWidget *parent = 0);
	~MarkdownEditorWidget();

	void reflesh(const QString& filePath);

private slots:
	void onEditorTextChangedSlot();
private:
	Ui::MarkdownEditorWidget ui;
	vector<MarkdownTextEdit*>  markdownTextEdits_;
};

#endif // MARKDOWNEDITORWIDGET_H
