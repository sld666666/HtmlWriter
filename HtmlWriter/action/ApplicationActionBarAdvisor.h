/** 
* @file         ApplicationActionBarAdvisor.h 
* @Synopsis       
* @author         sld666666@gmail.com 
* @version     1.0.0
* @date         3:2:2013  
*/
#ifndef APPLICATIONACTIONBARADVISOR_H
#define APPLICATIONACTIONBARADVISOR_H

#include <QObject>
#include "action/ActionBarAdvisor.h"
#include "action/MenuManager.h"
#include "action/ActionConfigurer.h"
#include "action/OpenAction.h"

using namespace UiUtils;

class ApplicationActionBarAdvisor : public ActionBarAdvisor
{
	Q_OBJECT

public:
	ApplicationActionBarAdvisor(ActionConfigurerPtr actionConfig);
	~ApplicationActionBarAdvisor();
protected:
	virtual	void makeActions();
	virtual	void fillMenuBar(const MenuManagerPtr menuManager);
private:
	OpenAction*		OpenAction_;
};

typedef shared_ptr<ApplicationActionBarAdvisor> ApplicationActionBarAdvisorPtr;
#endif // APPLICATIONACTIONBARADVISOR_H
