/** 
* @file         EditorTabWidgetRightMenu.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-5-14
*/
#ifndef UIUTILS_EDITORTABWIDGETRIGHTMENU_H
#define UIUTILS_EDITORTABWIDGETRIGHTMENU_H

#include <QWidget>
#include "action/IContextMenu.h"

namespace UiUtils{
	class EditorTabWidgetRightMenu : public IContextMenu
	{
		Q_OBJECT

	public:
		EditorTabWidgetRightMenu(QWidget * parent = 0);
		~EditorTabWidgetRightMenu();

	protected:
		virtual vector<IContextAction*>	getActions();

	private:


	};
	
}


#endif // UIUTILS_EDITORTABWIDGETRIGHTMENU_H
