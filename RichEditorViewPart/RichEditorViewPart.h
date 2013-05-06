#ifndef RICHEDITORVIEWPART_H
#define RICHEDITORVIEWPART_H

#include "workbench/IEditorPart.h"

using UiUtils::IEditorPart;

class RichEditorViewPart : public IEditorPart
{
public:
	RichEditorViewPart();
	~RichEditorViewPart();

public:
	virtual		long serviceId();
	virtual		void reflesh(const QString& filePath);
	virtual		void createPartControl(QWidget* parent);
	virtual		void doSave();
	virtual		void doSaveAs(const QString& targetPath);
private:

};

#endif // RICHEDITORVIEWPART_H
