#ifndef UTILS_XMLCONFIGMANAGER_H
#define UTILS_XMLCONFIGMANAGER_H

#include "ISingleton.h"
#include "utils_global.h"
#include "XmlViewsConfig.h"
#include "XmlApplicationConfig.h"

namespace utils{
	class UTILS_EXPORT XmlConfigManager : public ISingleton<XmlConfigManager>
	{

	public:
		~XmlConfigManager();

	public:
		vector<XmlViewsConfigPtr>	getViewsConfigs();
		XmlApplicationConfigPtr	getXmlAppConfig();
		
		void	writeSaveableSetting();
	private:
		XmlConfigManager();
		friend class ISingleton<XmlConfigManager>;

		void	writeXmlAPPConfig();
		void	writeViewsConfigs();
	private:
		vector<XmlViewsConfigPtr> xmlViewsConfigs_;
		XmlApplicationConfigPtr	xmlAppConfig_;
	};
}


#endif // XMLCONFIGMANAGER_H
