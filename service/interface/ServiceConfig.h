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
#include "GlobalServiceConstant.h"


namespace service
{
	enum SERVICETYPES{
		ST_UNKOWN = 0,
		ST_VIEW = 1,
		ST_EDITOR ,
		ST_MENU ,
		ST_ACTION,
		ST_TOOLBAR

	};
	class SERVICE_EXPORT ServiceConfig
	{
	public:
		ServiceConfig(SERVICETYPES type, const string& name, long id)
			: serviceType_(type)
			, serviceName_(name)
			, serviceId_(id)
		{

		}

		ServiceConfig(){};

		~ServiceConfig(){};

	public:
		void			setServiceType(SERVICETYPES type){ serviceType_ = type;}
		SERVICETYPES	getServiceType(){return serviceType_;}

		void			setServiceName(const string& serviceName){serviceName_ = serviceName;}
		string			getServiceName(){return serviceName_;}

		long			getServiceId(){return serviceId_;}
		void			setServiceId(long id ){serviceId_ = id;}

	private:
		SERVICETYPES serviceType_;
		string		serviceName_;
		long		serviceId_;
	};

	typedef shared_ptr<ServiceConfig> ServiceConfigPtr;
}



#endif // SERVICE_H
