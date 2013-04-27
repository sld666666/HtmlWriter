/** 
* @file         ApplicationToolBarAdvisor.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-26
*/
#ifndef APPLICATIONTOOLBARADVISOR_H
#define APPLICATIONTOOLBARADVISOR_H

#include <QObject>
#include "action/ActionBarAdvisor.h"
#include "action/MenuManager.h"
#include "action/ActionConfigurer.h"
#include "action/OpenAction.h"

using namespace UiUtils;

class ApplicationToolBarAdvisor : public ActionBarAdvisor
{
	Q_OBJECT

public:
	ApplicationToolBarAdvisor(ActionConfigurerPtr actionConfig);
	~ApplicationToolBarAdvisor();
protected:
	virtual	void makeActions();
	virtual	void fillMenuBar(const MenuManagerPtr menuManager);
private:
	OpenAction*		OpenAction_;
};

typedef shared_ptr<ApplicationToolBarAdvisor> ApplicationActionBarAdvisorPtr;
#endif // APPLICATIONACTIONBARADVISOR_H
