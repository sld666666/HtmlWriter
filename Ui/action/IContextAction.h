/** 
* @file         IContextAction.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-5-14
*/
#ifndef UIUTILS_ICONTEXTACTION_H
#define UIUTILS_ICONTEXTACTION_H

#include <QObject>
#include <QAction>

#include "ui_global.h"
#include "context/IContext.h"


namespace UiUtils{

	class UI_EXPORT IContextAction : public QAction
	{
		Q_OBJECT

	public:
		IContextAction(QObject * parent = 0);
		~IContextAction();

		virtual	void	execute(IContextPtr context) = 0;

		virtual QString title() = 0;

		virtual	QIcon	getIcon();

	};
}


#endif // UI_IACTION_H
