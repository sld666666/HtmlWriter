/** 
* @file         ActionConfigurer.h 
* @Synopsis       
* @author         sld666666@gmail.com 
* @version     1.0.0
* @date         2:2:2013  
*/
#ifndef UIUTILS_ACTIONCONFIGURER_H
#define UIUTILS_ACTIONCONFIGURER_H

#include <QObject>
#include <QMenuBar>

#include "ui_global.h"
#include "MenuManager.h"

namespace UiUtils{
	class UI_EXPORT ActionConfigurer : public QObject
	{
		Q_OBJECT

	public:
		ActionConfigurer(QMenuBar *menuBar);
		~ActionConfigurer();
		
		MenuManagerPtr	getMenuManager();
	private:
		MenuManagerPtr	menuManager_;

	};

	typedef shared_ptr<ActionConfigurer> ActionConfigurerPtr;
}
#endif // ACTIONCONFIGURER_H
