#include "ViewServiceOperator.h"
#include "IWorkbenchPart.h"


namespace UiUtils{
	ViewServiceOperator::ViewServiceOperator()
	{
	}

	ViewServiceOperator::~ViewServiceOperator()
	{
	}

	void ViewServiceOperator::viewReflesh(const QString& serviceName
										, const QString& filePath)
	{
		doViewReflesh(serviceName, filePath);
	}

	void ViewServiceOperator::doViewReflesh(const QString& serviceName
										, const QString& filePath)
	{
		vector<IService*> services = ServiceManager::instance().getServices();
		std::for_each(services.begin(), services.end()
			, bind(&ViewServiceOperator::refleshViewService
			, this, serviceName, filePath, _1));
	}

	void ViewServiceOperator::refleshViewService(const QString& serviceName
												, const QString& filePath
												, IService* service)
	{
		if (!service) return;

		if ((service->getServiceConfig()->getServiceType() == ST_VIEW
			|| service->getServiceConfig()->getServiceType() == ST_EDITOR)
			&& serviceName.toStdString() != service->getServiceConfig()->getServiceName()){
			IWorkbenchPart* workPart = static_cast<IWorkbenchPart*>(service);
			if (workPart){
				workPart->reflesh(filePath);
			}
		}
	}
}

