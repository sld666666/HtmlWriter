/** 
* @file         ViewServiceOperator.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-18
*/
#ifndef UIUTILS_VIEWSERVICEOPERATOR_H
#define UIUTILS_VIEWSERVICEOPERATOR_H

#include "ui_global.h"
#include "ISingleton.h"
#include "BundlesContainer.h"

using namespace service;

namespace  UiUtils{

	class UI_EXPORT ViewServiceOperator : public ISingleton<ViewServiceOperator>
	{
	public:
		~ViewServiceOperator();

		void	viewReflesh(const QString& bundelName, const QString& filePath);

	private:
		ViewServiceOperator();
		friend class ISingleton<ViewServiceOperator>;

	private:
		void	doViewReflesh(const QString& bundelName, const QString& filePath);
		void	refleshViewService(const QString& bundelName, const QString& filePath, IBundle*bundle);
	};
}


#endif
