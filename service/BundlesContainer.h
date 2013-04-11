/** 
* @file         BundlesContainer.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-9
*/
#ifndef SERVICE_BUNDLESCONTAINER_H
#define SERVICE_BUNDLESCONTAINER_H

#include "ISingleton.h"
#include "service_global.h"
#include "interface/IBundle.h"


namespace service{
	class SERVICE_EXPORT BundlesContainer : public ISingleton<BundlesContainer>
	{
	public:
		~BundlesContainer(){};

		void appendBundle(IBundle* bundel){
			bundles_.push_back(bundel);
		}

		vector<IBundle*> getBundles(){
			return bundles_;
		}

	private:
		BundlesContainer(){};

		friend class ISingleton<BundlesContainer>;
	private:
		vector<IBundle*> bundles_;
	};
}



#endif // PLUGINCONFIG_H
