#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/any.hpp>

#include "CustomDefinition.h"
#include "ServiceConfigManager.h"
#include "StringUtils.h"
#include "ApplicationConfig.h"
#include "ServiceConfigFunctors.h"

using namespace boost::property_tree;
using boost::property_tree::ptree;
using namespace boost;
using utils::StringUtils;

namespace service{
	ServiceConfigManager::ServiceConfigManager()
	{

	}

	ServiceConfigManager::~ServiceConfigManager()
	{

	}

	ServiceConfigPtr ServiceConfigManager::getServiceConfig(long id)
	{
		if (serviceConfigs_.empty()){
			serviceConfigs_ = getConfigs();
		}
		
		list<ServiceConfigPtr>::iterator iter = find_if(serviceConfigs_.begin()
			, serviceConfigs_.end(), bind(&ServiceConfigFunctors::matchedById, _1, id));
		return (iter != serviceConfigs_.end())?(*iter):ServiceConfigPtr();

	}

	list<ServiceConfigPtr> ServiceConfigManager::getConfigs()
	{
		list<ServiceConfigPtr> serviceConfigs;

		string fileName = getFileName();
		ptree tree;
		xml_parser::read_xml(fileName, tree);

		FOREACH(ptree::value_type& val, tree.get_child("services"))
		{
			int type(0);
			string name;
			long id(0);
			FOREACH(ptree::value_type& valChild, val.second)
			{
				string key = valChild.first;
				if ("type" == key){
					type = StringUtils::strTo<int>( valChild.second.data() );
				}else if ("name" == key){
					name = valChild.second.data();
				}else if ("id" == key){
					id  = StringUtils::strTo<long>(valChild.second.data());
				}
			}
			ServiceConfigPtr config(new ServiceConfig(static_cast<SERVICETYPES>(type)
				, name , id));
			serviceConfigs.push_back(config);
		}

		return serviceConfigs;
	}

	string ServiceConfigManager::getFileName()
	{
		return ApplicationConfig::instance().getAPPConfigPath()
			+ "/framework/ServiceConfig.xml";
	}
}

