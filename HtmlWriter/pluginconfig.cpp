#include "pluginconfig.h"

PluginConfig::PluginConfig()
{

}

PluginConfig::~PluginConfig()
{

}


vector<string> PluginConfig::getPlugins()
{
	vector<string> pluginName;
	pluginName.push_back("111");
	pluginName.push_back("222");
	pluginName.push_back("333");
	pluginName.push_back("444");

	return pluginName;
}