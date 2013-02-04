/** 
* @file         IAction.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-2-1
*/
#ifndef UI_IACTION_H
#define UI_IACTION_H

#include <QObject>
#include <QAction>

#include "ui_global.h"

namespace UiUtils{
	class UI_EXPORT IAction : public QAction
	{
		Q_OBJECT

	public:
		IAction(const QString& text, QObject * parent = 0);
		~IAction();
	
	protected:
		virtual	void	onRun() = 0;

	private slots:
		void onTrigger();

	private:
		void	initConnect();

	};

	typedef shared_ptr<IAction>	IActionPtr;

}


#endif // UI_IACTION_H
