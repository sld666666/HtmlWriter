/** 
* @file         SelfServicesRegister.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-28
*/
#ifndef SELFSERVICESREGISTER_H
#define SELFSERVICESREGISTER_H

#include <QObject>

class SelfServicesRegister : public QObject
{
	Q_OBJECT

public:
	SelfServicesRegister(QObject *parent);
	~SelfServicesRegister();
	
	static void	registerMenu(QWidget * parent);
	static void	registerAction();
	static void	registerToolBar(QWidget * parent);
	
};

#endif // SELFSERVICESREGISTER_H
