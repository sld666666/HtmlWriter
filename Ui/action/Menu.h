/** 
* @file         Menu.h 
* @Synopsis       
* @author         sld666666@gmail.com 
* @version     1.0.0
* @date         2:2:2013  
*/
#ifndef UIUTILS_Menu_H
#define UIUTILS_Menu_H

#include <QObject>
#include <QMenu>

#include "ui_global.h"
#include "IAction.h"
#include "interface/IService.h"

using namespace service;

namespace UiUtils{

	class UI_EXPORT Menu : public QMenu
		, public IService
	{
		Q_OBJECT

	public:
		Menu(const QString& title, QWidget * parent = 0);
		Menu(QWidget * parent = 0);

		~Menu();

	protected:
		virtual vector<IAction*>	getActions()	= 0;

	private slots:
		void	actionTriggeredSlot(bool checked);
		void	onAboutToShowSlot();

	private:
		void	add(IAction* action);
		void	initConnect();

	private:
		vector<IAction*> actions_;

	};

}


#endif // UI_Menu_H
