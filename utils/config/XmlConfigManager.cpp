#include "XmlConfigManager.h"
#include "ApplicationConfig.h"

namespace utils{
	XmlConfigManager::XmlConfigManager()
		: xmlAppConfig_(XmlApplicationConfigPtr())
	{

	}

	XmlConfigManager::~XmlConfigManager()
	{

	}

	vector<XmlViewsConfigPtr> XmlConfigManager::getViewsConfigs()
	{
		if (xmlViewsConfigs_.empty()){
			xmlViewsConfigs_ = XmlViewsConfig::readListConfig();
		}
		return xmlViewsConfigs_;
	}

	XmlApplicationConfigPtr XmlConfigManager::getXmlAppConfig()
	{
		if (!xmlAppConfig_.get()){
			xmlAppConfig_ = XmlApplicationConfigPtr(new XmlApplicationConfig());
			XmlApplicationConfig::readConfig(xmlAppConfig_);

		}
		return xmlAppConfig_;
	}

	void XmlConfigManager::writeXmlAPPConfig()
	{
		if (xmlAppConfig_){
			XmlApplicationConfig::writeXmlAPPConfig(xmlAppConfig_);
		}	
	}

	void XmlConfigManager::writeSaveableSetting()
	{
		writeXmlAPPConfig();
		writeViewsConfigs();
	}

	void XmlConfigManager::writeViewsConfigs()
	{
		XmlViewsConfig::writeListConfig(xmlViewsConfigs_);
	}

	
}
