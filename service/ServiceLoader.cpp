#include <boost/filesystem.hpp>
#include <string>

#include "ServiceLoader.h"
#include "instantiation/ObjectCreator.h"
#include "interface/IBundle.h"

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
		
		ObjectCreator<IBundle> objectCreator("D:\\project\\git\\HtmlWriter\\Debug\\plugin"
			, "DirectoryViewBundle.dll");
		IBundle* bundle = objectCreator.createObject("DirectoryViewBundle");
		return rtn;
	}

}

