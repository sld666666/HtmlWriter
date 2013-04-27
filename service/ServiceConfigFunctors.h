/** 
* @file         ServiceConfigFunctors.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-25
*/

#ifndef SERVICE_SERVICECONFIGFUNCTORS_H 
#define SERVICE_SERVICECONFIGFUNCTORS_H
#include "interface/ServiceConfig.h"

namespace service{

	class ServiceConfigFunctors
	{
	public:
		static bool	 matchedById(const ServiceConfigPtr config
								, long id)
		{ 
			return (config.get() 
					&& id == config->getServiceId());
		}


	};

}

#endif