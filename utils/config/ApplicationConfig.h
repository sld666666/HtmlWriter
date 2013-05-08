/** 
* @file         ApplicationConfig.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-9
*/
#ifndef SERVICE_APPLICATIONCONFIG_H
#define SERVICE_APPLICATIONCONFIG_H

#include "ISingleton.h"
#include "utils_global.h"


namespace utils{
	class UTILS_EXPORT ApplicationConfig : public ISingleton<ApplicationConfig>
	{
	public:
		~ApplicationConfig();

		string	getCurAppPath();

		string	getAPPConfigPath();

		string	getAppPluginPath();

		string	getIconPath();

	private:
		ApplicationConfig();

		friend class ISingleton<ApplicationConfig>;
	private:
		string	curAppPath_;
	};
}



#endif // PLUGINCONFIG_H
