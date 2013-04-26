/** 
* @file         MenuBarEditorMenu.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-25
*/
#ifndef MENUBAREDITORMENU_H
#define MENUBAREDITORMENU_H

#include <QObject>
#include <QWidget>
#include "action/Menu.h"

using namespace UiUtils;
class MenuBarEditorMenu : public UiUtils::Menu
{
	Q_OBJECT

public:
	MenuBarEditorMenu(QWidget * parent = 0);
	~MenuBarEditorMenu();

	virtual ServiceConfigPtr getServiceConfig() const;

protected:
	virtual vector<UiUtils::IAction*>	getActions();
private:
	
};

#endif // MENUBARFILEMENU_H
