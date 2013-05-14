/** 
* @file         IContextMenu.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-5-14
*/
#ifndef UIUTILS_ICONTEXTMENU_H
#define UIUTILS_ICONTEXTMENU_H

#include <QObject>
#include <QMenu>

#include "ui_global.h"
#include "IContextAction.h"
#include "context/IContext.h"

namespace UiUtils{

	class UI_EXPORT IContextMenu : public QMenu
	{
		Q_OBJECT

	public:
		IContextMenu(IContextPtr context, const QString& title, QWidget * parent = 0);
		IContextMenu(QWidget * parent = 0);

		~IContextMenu();

	protected:
		virtual vector<IContextAction*>	getActions()	= 0;

	private slots:
		void	actionTriggeredSlot(bool checked);
		void	onAboutToShowSlot();

	private:
		void	add(IContextAction* action);
		void	initConnect();

	private:
		vector<IContextAction*> actions_;
		IContextPtr		context_;
	};

}


#endif // UI_Menu_H
