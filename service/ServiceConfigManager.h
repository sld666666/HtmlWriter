/** 
* @file         ServiceConfigManager.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-27
*/
#ifndef SERVICE_SERVICECONFIGMANAGER_H
#define SERVICE_SERVICECONFIGMANAGER_H

#include <QObject>
#include "ISingleton.h"
#include "interface/ServiceConfig.h"
#include "service_global.h"

namespace service{
	class SERVICE_EXPORT ServiceConfigManager : public ISingleton<ServiceConfigManager>
	{

	public:
		~ServiceConfigManager();

		ServiceConfigPtr getServiceConfig(long id);
	private:
		ServiceConfigManager();
		friend class ISingleton<ServiceConfigManager>;

		list<ServiceConfigPtr> 	getConfigs();

		string					getFileName();
	private:
		list<ServiceConfigPtr>	serviceConfigs_;
	};
}


#endif // SERVICECONFIGMANAGER_H
