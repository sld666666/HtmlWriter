#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>

#include "ApplicationConfig.h"

namespace service{
	ApplicationConfig::ApplicationConfig()
	{

	}

	ApplicationConfig::~ApplicationConfig()
	{

	}

	string ApplicationConfig::getCurAppPath()
	{
		if (curAppPath_.empty()){
			
			curAppPath_ = boost::filesystem::initial_path
				<boost::filesystem::path>().string();
		}

		return curAppPath_;
	}

	string ApplicationConfig::getAPPConfigPath()
	{
		return getCurAppPath() + "/config";
	}

	string ApplicationConfig::getAppPluginPath()
	{
		return getCurAppPath() + "/plugin";
	}

	string ApplicationConfig::getIconPath()
	{
		return getCurAppPath() + "/res" + "/images" + "/icon";
	}

}
