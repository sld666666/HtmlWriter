#ifndef RICHEDITORTOOLBAR_H
#define RICHEDITORTOOLBAR_H

#include <QObject>
#include "action/IToolBar.h"

using namespace UiUtils;

class RichEditorToolBar : public IToolBar
{
	Q_OBJECT

public:
	RichEditorToolBar(QWidget *parent);
	~RichEditorToolBar();

	virtual long serviceId();

protected:
	virtual vector<IAction*> getActions();
	
};

#endif // RICHEDITORTOOLBAR_H
