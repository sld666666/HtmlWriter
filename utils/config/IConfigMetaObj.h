/** 
* @file         IConfigMetaObj.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-3
*/
#ifndef UTILS_ICONFIGMETAOBJ_H
#define UTILS_ICONFIGMETAOBJ_H

#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/any.hpp>
#include <boost/algorithm/string.hpp>
#include <QMetaObject>
#include <QMetaProperty>
#include "utils_global.h"
#include "CustomDefinition.h"
#include "ApplicationConfig.h"

using namespace boost::property_tree;
using boost::property_tree::ptree;
using namespace boost;

namespace utils{

	template <typename Derived>
	class IConfigMetaObj
	{
	public:
		IConfigMetaObj(){}
		~IConfigMetaObj(){}

		static void readConfig(shared_ptr<Derived> xmlConfig) 
		{
			string filePath = ApplicationConfig::instance()
				.getAPPConfigPath();
			filePath.append("/").append(xmlConfig->getFileName());

			ptree pt;
			read_xml(filePath, pt);

			const QMetaObject *metaobject = xmlConfig->metaObject();
			int count= metaobject->propertyCount();
			for (int i=0; i<count; ++i) 
			{
				QMetaProperty metaproperty = metaobject->property(i);
				const char *name = metaproperty.name();
				string propertyName(name);
				if ("objectName" == propertyName)continue;

				string nodePath = xmlConfig->getRootElementName().append(".")
					.append(propertyName);

				string var = pt.get<string>(nodePath);
				xmlConfig->setProperty(name, QString::fromStdString(var));
			}
		}

		static void writeXmlAPPConfig(shared_ptr<Derived> xmlConfig)
		{
			string filePath = ApplicationConfig::instance()
				.getAPPConfigPath();
			filePath.append("/").append(xmlConfig->getFileName());

			string nodePath = xmlConfig->getRootElementName();
			ptree pt;
			writeConfigToPtree(nodePath, xmlConfig, pt);

			write_xml(filePath, pt);
		}

		static vector<shared_ptr<Derived>>  readListConfig() 
		{
			shared_ptr<Derived> tmp(new Derived());
			vector<shared_ptr<Derived>> xmlConfigList;
			string filePath = ApplicationConfig::instance()
				.getAPPConfigPath();
			filePath.append("/").append(tmp->getFileName());

			ptree tree;
			read_xml(filePath, tree);
			
			string rootName = tmp->getRootElementName();
			vector<string> names;
			split(names, rootName, algorithm::is_any_of("."));
			if (!names.empty())rootName = names[0];
;			FOREACH(ptree::value_type& val, tree.get_child(rootName)){

				shared_ptr<Derived> xmlconfig(new Derived());
				FOREACH(ptree::value_type& valChild, val.second)
				{
					string key = valChild.first;
					string value = valChild.second.data();
					xmlconfig->setProperty(key.c_str(), QString::fromStdString(value));
				}
				xmlConfigList.push_back(xmlconfig);
			}

			return xmlConfigList;
		}

		static void writeListConfig(vector<shared_ptr<Derived>> xmlConfigList) 
		{
			shared_ptr<Derived> tmp(new Derived());
			string filePath = ApplicationConfig::instance()
				.getAPPConfigPath();
			filePath.append("/").append(tmp->getFileName());

			ptree tree;
			FOREACH(shared_ptr<Derived> config, xmlConfigList){
				ptree child;
				writeConfigToPtree("", config, child);
				tree.add_child(config->getRootElementName(), child);

			}

			write_xml(filePath, tree);
		}

		static	void writeConfigToPtree(const string& nodePath, shared_ptr<Derived> xmlConfig, ptree &pt) 
		{
			const QMetaObject *metaobject = xmlConfig->metaObject();
			int count= metaobject->propertyCount();
			for (int i=0; i<count; ++i) 
			{
				QMetaProperty metaproperty = metaobject->property(i);
				const char *name = metaproperty.name();
				string propertyName(name);
				if ("objectName" == propertyName)continue;

				
				string nodeName =  nodePath.empty() ? propertyName : (nodePath + (".") + (propertyName));
				string var = xmlConfig->property(name).toString().toStdString();
				pt.put(nodeName, var);
			}
		}
	};

}
#endif