/** 
* @file         ServiceLoader.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-3
*/
#ifndef SERVICE_SERVICE_H
#define SERVICE_SERVICE_H

#include "service_global.h"
#include "pluginconfig.h"

namespace service{
	class SERVICE_EXPORT ServiceLoader
	{
	public:
		ServiceLoader();

		~ServiceLoader();
	public:
		bool	loadPlugins();

	private:
		void	loadPlugins(const BundleConfigPtr bundleConfig);
	};
}


#endif
