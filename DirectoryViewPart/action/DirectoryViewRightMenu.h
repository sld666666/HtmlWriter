#ifndef DIRECTORYVIEWRIGHTMENU_H
#define DIRECTORYVIEWRIGHTMENU_H

#include <QObject>
#include <QWidget>
#include "action/Menu.h"

class DirectoryViewRightMenu : public UiUtils::Menu
{
	Q_OBJECT

public:
	DirectoryViewRightMenu(QWidget * parent = 0);
	~DirectoryViewRightMenu();

	ServiceConfigPtr getServiceConfig() const;
protected:
	virtual vector<UiUtils::IAction*>	getActions();

private:
	
};

#endif // DIRECTORYVIEWRIGHTMENU_H
