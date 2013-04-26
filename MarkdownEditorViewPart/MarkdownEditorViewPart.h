#ifndef MARKDOWNEDITORVIEWPART_H
#define MARKDOWNEDITORVIEWPART_H

#include "workbench/IEditorPart.h"
#include "MarkdownEditorWidget.h"

using UiUtils::IEditorPart;

class MarkdownEditorViewPart : public IEditorPart
{
public:
	MarkdownEditorViewPart();
	~MarkdownEditorViewPart();

	virtual		ServiceConfigPtr getServiceConfig() const ;

	virtual		void reflesh(const QString& filePath);

	virtual		void createPartControl(QWidget* parent);
	virtual		void doSave();
	virtual		void doSaveAs();

private:
	 MarkdownEditorWidget* markdownEditorWidget_;

};

#endif // MARKDOWNEDITORVIEWPART_H
