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
#include "ServiceManager.h"

using namespace service;

namespace  UiUtils{

	class UI_EXPORT ViewServiceOperator : public ISingleton<ViewServiceOperator>
	{
	public:
		~ViewServiceOperator();

		void	viewReflesh(const QString& serviceName, const QString& filePath);
		
		void	saveEditors();

		void	saveAsEditor(const QString& targetPath);

	private:
		ViewServiceOperator();
		friend class ISingleton<ViewServiceOperator>;

	private:
		void	doViewReflesh(const QString& serviceName, const QString& filePath);
		void	refleshViewService(const QString& serviceName, const QString& filePath
			, IService* service);

		void	doSaveEditors(IService* service);

		void	doSaveAsEditors(IService* service, const QString& targetPath);
	};
}


#endif
