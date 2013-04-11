/** 
* @file         BundleConfig.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-2-7
*/

#ifndef SERVICE_BUNDLECONFIG_H
#define SERVICE_BUNDLECONFIG_H

#include <sstream>
#include <string>
#include <boost/shared_ptr.hpp>

using namespace std;
using boost::shared_ptr;

namespace service{
	class BundleConfig
	{
	public:
		BundleConfig( const string &serviceName
							, const string &dllName)
			: serviceName_( serviceName )
			, dllName_(dllName)
		{

		}

		string getServiceName(){return serviceName_;}

		string getDllName(){return dllName_;}

		string toString(){
			ostringstream infoStream;
			infoStream << "bundleConfig={";
			infoStream << "serviceName=" << this->getServiceName() << ", ";
			infoStream << "dllName=" << this->getDllName() ;
			return infoStream.str();
		}

	private:	
		string serviceName_;
		string dllName_;
	};

	typedef boost::shared_ptr<BundleConfig> BundleConfigPtr;


	namespace RegisteredSevice
	{
		const string BENCHVIEW = "benchview";


	}
}
#endif