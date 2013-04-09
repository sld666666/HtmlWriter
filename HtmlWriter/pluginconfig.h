/** 
* @file         pluginconfig.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-9
*/
#ifndef PLUGINCONFIG_H
#define PLUGINCONFIG_H

#include <QObject>
#include "ISingleton.h"
#include "htmlwriterGlobal.h"

//using utils::ISingleton;

class PluginConfig : public ISingleton<PluginConfig>
{
	//Q_OBJECT

public:
	~PluginConfig();

	vector<string> getPlugins();


private:
	PluginConfig();

	friend class ISingleton<PluginConfig>;
	
};

#endif // PLUGINCONFIG_H
