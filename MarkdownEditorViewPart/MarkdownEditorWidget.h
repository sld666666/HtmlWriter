#ifndef MARKDOWNEDITORWIDGET_H
#define MARKDOWNEDITORWIDGET_H

#include <QWidget>
#include <QCloseEvent>
#include "markdowneditorviewpart_global.h"
#include "ui_MarkdownEditorWidget.h"
#include "markdowneditorviewpart_global.h"
#include "widget/ActionTabWidget.h"

class MarkdownViewPartConfig;
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
	void configOpen(const shared_ptr<MarkdownViewPartConfig> config);
	void saveConfig();
private slots:
	void onEditorTextChangedSlot();
private:
	Ui::MarkdownEditorWidget ui;
	ActionTabWidget*	tabWidgetEditor_;
	vector<shared_ptr<MarkdownViewPartConfig>> markdownViewPartConfigs_;
};

#endif // MARKDOWNEDITORWIDGET_H
