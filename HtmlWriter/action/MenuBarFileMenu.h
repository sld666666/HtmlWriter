/** 
* @file         MenuBarFileMenu.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-25
*/
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
	MenuBarFileMenu(QWidget * parent = 0);
	~MenuBarFileMenu();

	virtual long serviceId();

protected:
	virtual vector<UiUtils::IAction*>	getActions();
private:
	
};

#endif // MENUBARFILEMENU_H
