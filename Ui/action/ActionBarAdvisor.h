/** 
* @file         ActionBarAdvisor.h 
* @Synopsis       
* @author         sld666666@gmail.com 
* @version     1.0.0
* @date         2:2:2013  
*/
#ifndef UI_ACTIONBARADVISOR_H
#define UI_ACTIONBARADVISOR_H

#include <QObject>

#include "ui_global.h"
#include "MenuManager.h"
#include "ActionConfigurer.h"

namespace UiUtils{

	class UI_EXPORT ActionBarAdvisor : public QObject
	{
		Q_OBJECT

	public:
		ActionBarAdvisor(ActionConfigurerPtr actionConfig);
		~ActionBarAdvisor();

	protected:
		void		init(ActionConfigurerPtr actionConfig);

		virtual	void makeActions();
		virtual	void fillMenuBar(const MenuManagerPtr menuManager);
		virtual	void fillCoolBar();

	private:

	};

}


#endif // ACTIONBARADVISOR_H
