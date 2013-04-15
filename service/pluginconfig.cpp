#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include <boost/any.hpp>
#include "pluginconfig.h"
#include "CustomDefinition.h"
#include "ApplicationConfig.h"

using namespace boost::property_tree;
using boost::property_tree::ptree;
using namespace boost;

namespace service{
	PluginConfig::PluginConfig()
	{

	}

	PluginConfig::~PluginConfig()
	{

	}


	vector<BundleConfigPtr> PluginConfig::getPlugins()
	{
		vector<BundleConfigPtr> bundleConfigs;

		string fileName = getFileName();
		ptree tree;
		xml_parser::read_xml(fileName, tree);

		FOREACH(ptree::value_type& val, tree.get_child("plugins"))
		{
			string test = val.first;
			string name, service;
			FOREACH(ptree::value_type& valChild, val.second)
			{
				string key = valChild.first;
				if ("name" == key){
					name = valChild.second.data();
				}else if ("service" == key){
					service = valChild.second.data();
				}
			}
			BundleConfigPtr config(new BundleConfig(service, name));
			bundleConfigs.push_back(config);
		}

		return bundleConfigs;
	}

	string PluginConfig::getFileName()
	{
		return ApplicationConfig::instance().getAPPConfigPath()
			+ "/framework/pluginConfig.xml";
	}
}
