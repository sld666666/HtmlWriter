/** 
* @file         BundleFunctors.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-11
*/

#ifndef SERVICE_BUNDLEFUNCTORS_H 
#define SERVICE_BUNDLEFUNCTORS_H
#include "interface/IBundle.h"

namespace service{

	class BundleFunctors
	{
	public:
		static bool	 matched(const IBundle* bundle
										, const string& serviceName)
		{ 
			return (bundle 
					&& bundle->getBundlelConfig().get()
					&& serviceName == bundle->getBundlelConfig()->getServiceName());
		}

		static bool	 notMatched(const IBundle* bundle
								, const string& serviceName)
		{ 
			return (!matched(bundle, serviceName));
		}
	};

}

#endif