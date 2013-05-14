#ifndef MARKDOWNEDITORWIDGET_H
#define MARKDOWNEDITORWIDGET_H

#include <QWidget>
#include "markdowneditorviewpart_global.h"
#include "ui_MarkdownEditorWidget.h"
#include "markdowneditorviewpart_global.h"
#include "widget/ActionTabWidget.h"

using namespace  UiUtils;
class MarkdownEditorWidget : public QWidget
{
	Q_OBJECT

public:
	MarkdownEditorWidget(QWidget *parent = 0);
	~MarkdownEditorWidget();

	void reflesh(const QString& filePath);
	void save();
	void saveAs(const QString& targetPath);

	TextEdit* getCurTextEditor();

private:
	void doSave(TextEdit* textEdit);
private slots:
	void onEditorTextChangedSlot();
private:
	Ui::MarkdownEditorWidget ui;
	ActionTabWidget*	tabWidgetEditor_;
};

#endif // MARKDOWNEDITORWIDGET_H
