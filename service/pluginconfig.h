/** 
* @file         pluginconfig.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-9
*/
#ifndef SERVICE_PLUGINCONFIG_H
#define SERVICE_PLUGINCONFIG_H

#include <QObject>
#include "ISingleton.h"
#include "service_global.h"
#include "PluginDesc.h"

namespace service{
	class PluginConfig : public ISingleton<PluginConfig>
	{
		//Q_OBJECT

	public:
		~PluginConfig();

		vector<PluginDescPtr> getPlugins();

	protected:
		virtual	string getFileName();

	private:
		PluginConfig();

		friend class ISingleton<PluginConfig>;

	};
}



#endif // PLUGINCONFIG_H
