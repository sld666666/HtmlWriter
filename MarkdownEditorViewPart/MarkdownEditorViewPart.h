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

public:
	virtual		void createPartControl(QWidget* parent);
	virtual		void doSave();
	virtual		void doSaveAs();

private:
	 	

};

#endif // MARKDOWNEDITORVIEWPART_H
