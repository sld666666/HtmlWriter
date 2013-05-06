#ifndef RICHEDITORWIDGET_H
#define RICHEDITORWIDGET_H

#include <QWidget>
#include "ui_RichEditorWidget.h"
#include "widget/TextEdit.h"
#include "richeditorviewpart_global.h"

using namespace  UiUtils;
class RichEditorWidget : public QWidget
{
	Q_OBJECT

public:
	RichEditorWidget(QWidget *parent = 0);
	~RichEditorWidget();

	void reflesh(const QString& filePath);
	void save();
	void saveAs(const QString& targetPath);
public:
	TextEdit*	getCurrentEditor();
private slots:
	void onEditorTextChangedSlot();
private:
	void doSave(TextEdit* textEdit);

private:
	Ui::RichEditorWidget ui;
	vector<TextEdit*>  textEdits_;
};

#endif // RICHEDITORWIDGET_H
