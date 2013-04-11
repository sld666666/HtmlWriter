#include <boost/filesystem.hpp>
#include <string>

#include "ServiceLoader.h"
#include "instantiation/ObjectCreator.h"
#include "interface/IBundle.h"
#include "ApplicationConfig.h"
#include "BundlesContainer.h"

using std::string;

namespace service{
	ServiceLoader::ServiceLoader()
	{
	}

	ServiceLoader::~ServiceLoader()
	{
	}

	bool ServiceLoader::loadPlugins()
	{
		bool rtn(false);
		vector<BundleConfigPtr> bundleConfigs = PluginConfig::instance().getPlugins();
		
		for_each(bundleConfigs.begin(), bundleConfigs.end()
			, bind(&ServiceLoader::loadPlugins, this, _1));

		return rtn;
	}

	void ServiceLoader::loadPlugins(const BundleConfigPtr bundleConfig)
	{
		ObjectCreator<IBundle> objectCreator(ApplicationConfig::instance().getAppPluginPath()
			, bundleConfig->getDllName());
		IBundle* bundle = objectCreator.createObject();
		BundlesContainer::instance().appendBundle(bundle);

	}

}

