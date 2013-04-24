#ifndef MENUBARFILEMENU_H
#define MENUBARFILEMENU_H

#include <QObject>
#include <QWidget>
#include "action/Menu.h"

using namespace UiUtils;
class MenuBarFileMenu : public UiUtils::Menu
{
	Q_OBJECT

public:
	MenuBarFileMenu(IContext* context, QWidget * parent = 0);
	~MenuBarFileMenu();

protected:
	virtual vector<UiUtils::IAction*>	getActions();
private:
	
};

#endif // MENUBARFILEMENU_H
