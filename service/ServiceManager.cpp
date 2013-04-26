#include "ServiceManager.h"
#include "ServiceFunctors.h"

namespace service{
	ServiceManager::ServiceManager()
	{

	}

	ServiceManager::~ServiceManager()
	{

	}

	void ServiceManager::appendService(IService* service)
	{
		serviceContainer_.appendService(service);
	}

	vector<IService*> ServiceManager::getServices()
	{
		return serviceContainer_.getServices();
	}

	IService* ServiceManager::find(const string& name)
	{
		vector<IService*> services = getServices();
		vector<IService*>::iterator iter = find_if(services.begin(), services.end()
			,bind(&ServiceFunctors::matchByName, _1, name));
		
		return (iter != services.end())?(*iter):NULL;
	}
}

