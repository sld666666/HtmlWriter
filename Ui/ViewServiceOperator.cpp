#include "ViewServiceOperator.h"
#include "IWorkbenchPart.h"

namespace UiUtils{
	ViewServiceOperator::ViewServiceOperator()
	{
	}

	ViewServiceOperator::~ViewServiceOperator()
	{
	}

	void ViewServiceOperator::viewReflesh(const QString& bundelName
										, const QString& filePath)
	{
		doViewReflesh(bundelName, filePath);
	}

	void ViewServiceOperator::doViewReflesh(const QString& bundelName
										, const QString& filePath)
	{
		vector<IBundle*> bundles = BundlesContainer::instance().getBundles();
		std::for_each(bundles.begin(), bundles.end()
			, bind(&ViewServiceOperator::refleshViewService
			, this, bundelName, filePath, _1));
	}

	void ViewServiceOperator::refleshViewService(const QString& bundelName
												, const QString& filePath
												, IBundle*bundle)
	{
		if (!bundle) return;

		if (bundle->getBundlelConfig()->getServiceName() == RegisteredSevice::BENCHVIEW
			&& bundelName.toStdString() != bundle->getBundlelConfig()->getDllName()){
			IWorkbenchPart* workPart = static_cast<IWorkbenchPart*>( 
				bundle->getBundlelConfig()->getSerice());
			if (workPart){
				workPart->reflesh(filePath);
			}
		}
	}
}

