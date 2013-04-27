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

class ApplicationActionBarAdvisor : public QObject
{
	Q_OBJECT

public:
	ApplicationActionBarAdvisor();
	~ApplicationActionBarAdvisor();

	virtual	void fillMenuBar(QMenuBar* menuBar);
	virtual	void fillToolBar(QToolBar* toolBar);

protected:
	virtual	void makeActions();
	
};
#endif // APPLICATIONACTIONBARADVISOR_H
