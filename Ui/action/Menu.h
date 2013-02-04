/** 
* @file         Menu.h 
* @Synopsis       
* @author         sld666666@gmail.com 
* @version     1.0.0
* @date         2:2:2013  
*/
#ifndef UI_Menu_H
#define UI_Menu_H

#include <QObject>
#include <QMenu>

#include "ui_global.h"
#include "IAction.h"

#include "ui_global.h"

namespace UiUtils{

	class UI_EXPORT Menu : public QMenu
	{
		Q_OBJECT

	public:
		Menu(const QString& title, QWidget * parent = 0);
		~Menu();

	void	add(IAction* action);

	private:

	};

	typedef shared_ptr<Menu> MenuPtr;
}


#endif // UI_Menu_H
