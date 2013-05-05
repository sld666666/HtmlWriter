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
#include <QMenuBar>
#include <QToolBar>
#include <QMainWindow>
#include "ServiceManager.h"
#include "action/ActionHelper.h"

using namespace service;
using namespace UiUtils;

class ApplicationActionBarAdvisor : public QObject
{
	Q_OBJECT

public:
	ApplicationActionBarAdvisor();
	~ApplicationActionBarAdvisor();

	virtual	void fillMenuBar(QMenuBar* menuBar);
	virtual	void fillToolBar(QMainWindow* mainWnd);

protected:
	virtual	void makeActions();

private:
	void	appendMenuBar(IService* service, QMenuBar* menuBar);
	void	appendToolBar(IService* service, QMainWindow* mainWnd);
	
};
#endif // APPLICATIONACTIONBARADVISOR_H
