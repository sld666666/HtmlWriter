/** 
* @file         ServiceContainer.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-25
*/
#ifndef SERVICE_SERVICECONTAINER_H
#define SERVICE_SERVICECONTAINER_H

#include "interface/IService.h"


namespace service{
	class SERVICE_EXPORT ServiceContainer 
	{
	public:
		ServiceContainer(){};
		~ServiceContainer(){};

		void appendService(IService* service){
			services_.push_back(service);
		}

		vector<IService*> getServices(){
			return services_;
		}

	private:
		vector<IService*> services_;
	};
}



#endif // PLUGINCONFIG_H
