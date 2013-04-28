/** 
* @file         ServiceManager.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-25
*/
#ifndef SERVICE_SERVICEMANAGER_H
#define SERVICE_SERVICEMANAGER_H

#include <QObject>
#include "ServiceContainer.h"
#include "ISingleton.h"
#include "service_global.h"

namespace service{
	class SERVICE_EXPORT ServiceManager : public ISingleton<ServiceManager>
	{
	public:
		~ServiceManager();
	public:
		void				appendService(IService* service);

		vector<IService*>	getServices();

		IService*			find(const string& name);
		IService*			find(long id);

	private:
		ServiceManager();
		friend class ISingleton<ServiceManager>;
	private:
		ServiceContainer	serviceContainer_;
	};
}


#endif // SERVICE_SERVICEMANAGER_H
