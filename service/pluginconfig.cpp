#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>

#include "pluginconfig.h"
#include "CustomDefinition.h"


#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include <boost/any.hpp>

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

		BOOST_AUTO(child, pt.get_child("plugins.plugin")); 
		for(BOOST_AUTO(pos, child.begin()); pos != child.end(); ++pos){
			string name = pos->second.get<string>("name");
			string service = pos->second.get<string>("service");
		}

		FOREACH(ptree::value_type &node, tree.get_child("plugins.plugin")){
		;
		}

		return bundleConfigs;
	}

	string PluginConfig::getFileName()
	{
		return filesystem::initial_path<filesystem::path>().string() + "/config/pluginConfig.xml";
	}
}
