#ifndef MARKDOWNEDITORTOOLBAR_H
#define MARKDOWNEDITORTOOLBAR_H

#include <QObject>
#include "action/IToolBar.h"

using namespace UiUtils;

class MarkdownEditorToolBar : public IToolBar
{
	Q_OBJECT

public:
	MarkdownEditorToolBar(QWidget *parent);
	~MarkdownEditorToolBar();

	virtual long serviceId();

protected:
	virtual vector<IAction*> getActions();

private:
	
};

#endif // MARKDOWNEDITORTOOLBAR_H
