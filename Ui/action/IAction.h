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
#include "interface/IService.h"

#include "ui_global.h"

using namespace service;

namespace UiUtils{
	class UI_EXPORT IAction : public QAction
		, public IService
	{
		Q_OBJECT

	public:
		IAction(const QString& text, QObject * parent = 0);
		~IAction();

		virtual	void	execute() = 0;
	};
}


#endif // UI_IACTION_H
