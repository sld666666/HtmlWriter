/** 
* @file         IAction.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-2-1
*/
#ifndef UIUTILS_IACTION_H
#define UIUTILS_IACTION_H

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

		virtual	void	execute() = 0;
	};
}


#endif // UI_IACTION_H
