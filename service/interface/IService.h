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

namespace service
{
	class SERVICE_EXPORT IService
	{
	public:
		IService(){};
		~IService(){};

		virtual	void sartService(BundleContext* context) = 0;
	};

	typedef shared_ptr<IService> IServicePtr;
}



#endif // SERVICE_H
