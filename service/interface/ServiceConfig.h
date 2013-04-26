/** 
* @file         ServiceConfig.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-16
*/
#ifndef SERVICECONFIG_SERVICE_H
#define SERVICECONFIG_SERVICE_H

#include "service_global.h"


namespace service
{
	enum SERVICETYPES{
		ST_VIEW = 0,
		ST_EDITOR ,
		ST_MENU 

	};
	class SERVICE_EXPORT ServiceConfig
	{
	public:
		ServiceConfig(SERVICETYPES type, const string& name)
			: serviceType_(type)
			, serviceName_(name)
		{

		}

		ServiceConfig(){};

		~ServiceConfig(){};

	public:
		void			setServiceType(SERVICETYPES type){ serviceType_ = type;}
		SERVICETYPES	getServiceType(){return serviceType_;}

		void			setServiceName(const string& serviceName){serviceName_ = serviceName;}
		string			getServiceName(){return serviceName_;}
	private:
		SERVICETYPES serviceType_;
		string		serviceName_;
	};

	typedef shared_ptr<ServiceConfig> ServiceConfigPtr;
}



#endif // SERVICE_H
