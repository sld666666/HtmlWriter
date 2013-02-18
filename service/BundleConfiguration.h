/** 
* @file         BundleConfiguration.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-2-7
*/

#ifndef SERVICE_BUNDLECONFIGURATION_H
#define SERVICE_BUNDLECONFIGURATION_H
#include <sstream>

#include "service.h"

static const string NO_LIB_PATH;
static const string NO_LIB_NAME;

namespace service{
	class BundleConfiguration
	{
	public:
		BundleConfiguration( const string &bundleName, const string &className
			, const string &libPath, const string &libName )
			:bundleName_( bundleName )
			, className_(className)
			, libraryPath_( libPath )
			, libraryName_( libName )
		{

		}

		BundleConfiguration( const string &bundleName, const string &className )
			:bundleName_( bundleName )
			, className_(className)
			, libraryPath_( NO_LIB_PATH )
			, libraryName_( NO_LIB_NAME )
		{

		}

		string getBundleName(){return bundleName_;}
		string getClassName(){return className_;}
		string getLibraryPath(){return libraryPath_;}
		string getLibraryName(){return libraryName_;}
		string toString(){

			ostringstream infoStream;
			infoStream << "bundleConfig={";
			infoStream << "bundleName=" << this->bundleName_ << ", ";
			infoStream << "className=" << this->className_ << ", ";
			infoStream << "libraryName=" << this->libraryPath_ << ", ";
			infoStream << "libraryPath=" << this->libraryName_ << "}";
			return infoStream.str();
		}

	private:	
		string bundleName_;
		string className_;
		string libraryPath_;
		string libraryName_;
	};

}
#endif