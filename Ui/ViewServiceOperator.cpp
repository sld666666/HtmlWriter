#include "ViewServiceOperator.h"
#include "IWorkbenchPart.h"
#include "IEditorPart.h"


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

	void ViewServiceOperator::saveEditors()
	{
		vector<IService*> services = ServiceManager::instance().getServices();
		std::for_each(services.begin(), services.end()
			, bind(&ViewServiceOperator::doSaveEditors, this, _1));
	}

	void ViewServiceOperator::saveAsEditor(const QString& targetPath)
	{
		vector<IService*> services = ServiceManager::instance().getServices();
		std::for_each(services.begin(), services.end()
			, bind(&ViewServiceOperator::doSaveAsEditors, this, _1, targetPath));
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

	void ViewServiceOperator::doSaveEditors(IService* service)
	{
		if (!service) return;

		if (service->getServiceConfig()->getServiceType() == ST_EDITOR){
				IEditorPart* workPart = static_cast<IEditorPart*>(service);
				if (workPart){
					workPart->doSave();
				}
		}
	}

	void ViewServiceOperator::doSaveAsEditors(IService* service, const QString& targetPath)
	{
		if (!service) return;

		if (service->getServiceConfig()->getServiceType() == ST_EDITOR){
			IEditorPart* workPart = static_cast<IEditorPart*>(service);
			if (workPart){
				workPart->doSaveAs(targetPath);
			}
		}
	}
}

