/** 
* @file         MenuManager.h 
* @Synopsis       
* @author         sld666666@gmail.com 
* @version     1.0.0
* @date         2:2:2013  
*/
#ifndef UIUTILS_MENUMANAGER_H
#define UIUTILS_MENUMANAGER_H

#include <QObject>
#include <QMenuBar>

#include "ui_global.h"
#include "Menu.h"

namespace UiUtils{
	class UI_EXPORT MenuManager : public QObject
	{
		Q_OBJECT

	public:
		MenuManager(QMenuBar *menuBar);
		~MenuManager();

		void	addMenu(Menu* menu);
		void	addAction(IAction* action);

	private:
		QMenuBar*	menuBar_;
	};

	typedef shared_ptr<MenuManager> MenuManagerPtr;
}
#endif // UI_MENUMANAGER_H
