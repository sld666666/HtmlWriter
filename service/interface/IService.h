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

namespace service
{
	class SERVICE_EXPORT IService
	{
	public:
		IService(){};
		~IService(){};
		
		virtual ServiceConfigPtr getServiceConfig() const = 0;
	};
}



#endif // SERVICE_H
