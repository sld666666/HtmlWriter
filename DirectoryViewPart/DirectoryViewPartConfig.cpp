#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include "DirectoryViewPartConfig.h"
#include "ApplicationConfig.h"
#include "CustomDefinition.h"

using namespace boost;
using namespace boost::property_tree;
using boost::property_tree::ptree;

DirectoryViewPartConfig::DirectoryViewPartConfig()
{

}

DirectoryViewPartConfig::~DirectoryViewPartConfig()
{
}

string	DirectoryViewPartConfig::getValue(const string& key)
{
	if (configs_.empty()) initConfigs();
	
	return (configs_.find(key) != configs_.end())? configs_[key]:"";
}


void DirectoryViewPartConfig::initConfigs()
{
	string fileName = getFileName();
	ptree tree;
	xml_parser::read_xml(fileName, tree);

	FOREACH(ptree::value_type& val, tree.get_child("setting"))
	{
		configs_.insert( make_pair(val.first, val.second.data()));
	}
}

string DirectoryViewPartConfig::getFileName()
{
	return service::ApplicationConfig::instance().getAPPConfigPath()
		+ "/plugins/directoryViewPartConfig.xml";
}
