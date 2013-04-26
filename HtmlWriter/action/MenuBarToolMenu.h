/** 
* @file         MenuBarToolMenu.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-25
*/
#ifndef MENUBARTOOLMENU_H
#define MENUBARTOOLMENU_H

#include <QObject>
#include <QWidget>
#include "action/Menu.h"

using namespace UiUtils;
class MenuBarToolMenu : public UiUtils::Menu
{
	Q_OBJECT

public:
	MenuBarToolMenu(QWidget * parent = 0);
	~MenuBarToolMenu();

	virtual ServiceConfigPtr getServiceConfig() const;
protected:
	virtual vector<UiUtils::IAction*>	getActions();
private:
	
};

#endif // MENUBARTOOLMENU_H
