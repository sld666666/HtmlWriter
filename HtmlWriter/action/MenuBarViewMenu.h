/** 
* @file         MenuBarViewMenu.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-25
*/
#ifndef MENUBARVIEWMENU_H
#define MENUBARVIEWMENU_H

#include <QObject>
#include <QWidget>
#include "action/Menu.h"

using namespace UiUtils;
class MenuBarViewMenu : public UiUtils::Menu
{
	Q_OBJECT

public:
	MenuBarViewMenu(QWidget * parent = 0);
	~MenuBarViewMenu();
	virtual ServiceConfigPtr getServiceConfig() const;
protected:
	virtual vector<UiUtils::IAction*>	getActions();
private:
	
};

#endif // MENUBARFILEMENU_H
