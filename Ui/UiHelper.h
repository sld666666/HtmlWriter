/** 
* @file         UiHelper.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-12
*/
#ifndef UIUTILS_UIHELPER_H
#define UIUTILS_UIHELPER_H

#include <QObject>
#include <QWidget>
#include "ui_global.h"

namespace UiUtils{
	class UI_EXPORT UiHelper : public QObject
	{
		Q_OBJECT

	public:
		UiHelper(QObject *parent= NULL);
		~UiHelper();

		static void	updateWidgetWithHLayout(QWidget* widget);
		static void	updateWidgetWithVLayout(QWidget* widget);
	private:

	};
}


#endif // UIHELPER_H
