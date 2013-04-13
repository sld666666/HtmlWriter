#ifndef MARKDOWNEDITORVIEWPART_H
#define MARKDOWNEDITORVIEWPART_H

#include "workbench/ViewPart.h"

class MarkdownEditorViewPart : public QObject
{
public:
	MarkdownEditorViewPart();
	~MarkdownEditorViewPart();

public:
	virtual void createPartControl(QWidget* parent);
private:

};

#endif // MARKDOWNEDITORVIEWPART_H
