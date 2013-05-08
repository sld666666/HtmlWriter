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
			XmlViewsConfigPtr tmp (new XmlViewsConfig);
			xmlViewsConfigs_ = tmp->readListConfig();
		}
		return xmlViewsConfigs_;
	}

	XmlApplicationConfigPtr XmlConfigManager::getXmlAppConfig()
	{
		if (!xmlAppConfig_.get()){
			xmlAppConfig_ = XmlApplicationConfigPtr(new XmlApplicationConfig());
			xmlAppConfig_->readConfig(xmlAppConfig_);

		}
		return xmlAppConfig_;
	}

	void XmlConfigManager::writeXmlAPPConfig()
	{
		if (xmlAppConfig_){
			xmlAppConfig_->writeXmlAPPConfig(xmlAppConfig_);
		}	
	}

	
}
