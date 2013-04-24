#ifndef DIRECTORYVIEWRIGHTMENU_H
#define DIRECTORYVIEWRIGHTMENU_H

#include <QObject>
#include <QWidget>
#include "action/Menu.h"

class DirectoryViewRightMenu : public UiUtils::Menu
{
	Q_OBJECT

public:
	DirectoryViewRightMenu(UiUtils::IContext* context, QWidget * parent = 0);
	~DirectoryViewRightMenu();

protected:
	virtual vector<UiUtils::IAction*>	getActions();

private:
	
};

#endif // DIRECTORYVIEWRIGHTMENU_H
