/** 
* @file         IService.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-16
*/
#ifndef ISERVICE_SERVICE_H
#define ISERVICE_SERVICE_H

#include <QObject>

#include "service_global.h"
#include "BundleContext.h"
#include "ServiceConfig.h"
#include "ServiceConfigManager.h"

namespace service
{
	class SERVICE_EXPORT IService
	{
	public:
		IService(){};
		~IService(){};
		
		virtual long serviceId() = 0;

		ServiceConfigPtr getServiceConfig(){
			return ServiceConfigManager::instance()
				.getServiceConfig(serviceId());
		}
	};
}



#endif // SERVICE_H
