/** 
* @file         ServiceFunctors.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-25
*/

#ifndef SERVICE_SERVICEFUNCTORS_H 
#define SERVICE_SERVICEFUNCTORS_H
#include "interface/IService.h"

namespace service{

	class ServiceFunctors
	{
	public:
		static bool	 matchedByType(IService* service
								, SERVICETYPES serviceType)
		{ 
			return (service 
					&& service->getServiceConfig().get()
					&& serviceType == service->getServiceConfig()->getServiceType());
		}

		static bool	 isViewOrEditorService(IService* service)
		{ 
			return (service 
				&& service->getServiceConfig().get()
				&& (ST_VIEW == service->getServiceConfig()->getServiceType()
					|| ST_EDITOR == service->getServiceConfig()->getServiceType()));
		}

		static bool	matchByName(IService* service
							, const string name)
		{
			return (service 
				&& service->getServiceConfig().get()
				&& name == service->getServiceConfig()->getServiceName());
		}

	};

}

#endif