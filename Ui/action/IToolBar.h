/** 
* @file         IToolBar.h 
* @Synopsis       
* @author         sld666666@gmail.com 
* @version     1.0.0
* @date         2:2:2013  
*/
#ifndef UIUTILS_ITOOLBAR_H
#define UIUTILS_ITOOLBAR_H

#include <QObject>
#include <QToolBar>

#include "ui_global.h"
#include "IAction.h"
#include "interface/IService.h"

using namespace service;

namespace UiUtils{

	class UI_EXPORT IToolBar : public QToolBar
		, public IService
	{
		Q_OBJECT

	public:
		IToolBar(QWidget * parent = 0);

		~IToolBar();

		void	fills();
	protected:
		virtual vector<IAction*>	getActions()	= 0;

	private slots:
		void	actionTriggeredSlot(bool checked);

	private:
		void	add(IAction* action);
		void	initConnect();

	private:
		vector<IAction*> actions_;

	};

}


#endif // UI_Menu_H
