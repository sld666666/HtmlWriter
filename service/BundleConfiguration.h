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
#include <string>
#include <boost/shared_ptr.hpp>

using namespace std;

namespace service{
	class BundleConfiguration
	{
	public:
		BundleConfiguration( const string &serviceName
							, const string &className
							, const string &dllName)
			: serviceName_( serviceName )
			, className_(className)
			, dllName_(dllName)
		{

		}

		string getServiceName(){return serviceName_;}

		string getClassName(){return className_;}

		string getDllName(){return dllName_;}

		string toString(){
			ostringstream infoStream;
			infoStream << "bundleConfig={";
			infoStream << "serviceName=" << this->getServiceName() << ", ";
			infoStream << "className=" << this->getClassName() << ", ";
			infoStream << "dllName=" << this->getDllName() ;
			return infoStream.str();
		}

	private:	
		string serviceName_;
		string className_;
		string dllName_;
	};

	typedef boost::shared_ptr<BundleConfiguration> BundleConfigPtr;
}
#endif