/** 
* @file         MenuBarHelpMenu.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-25
*/
#ifndef MENUBARHELPMENU_H
#define MENUBARHELPMENU_H

#include <QObject>
#include <QWidget>
#include "action/Menu.h"

using namespace UiUtils;
class MenuBarHelpMenu : public UiUtils::Menu
{
	Q_OBJECT

public:
	MenuBarHelpMenu(QWidget * parent = 0);
	~MenuBarHelpMenu();

	virtual long serviceId();
protected:
	virtual vector<UiUtils::IAction*>	getActions();
private:
	
};

#endif // MENUBARHELPMENU_H
