/** 
* @file         PluginDesc.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-16
*/

#ifndef SERVICE_PLUGINDESC_H
#define SERVICE_PLUGINDESC_H

#include <sstream>
#include <string>
#include <boost/shared_ptr.hpp>

using namespace std;
using boost::shared_ptr;

namespace service{
	class PluginDesc
	{
	public:
		PluginDesc( const string &serviceName
					, const string &dllName)
			: serviceName_( serviceName )
			, dllName_(dllName)
		{

		}

		string getServiceName(){return serviceName_;}

		string getDllName(){return dllName_;}

		string toString(){
			ostringstream infoStream;
			infoStream << "PluginDesc={";
			infoStream << "serviceName=" << this->getServiceName() << ", ";
			infoStream << "dllName=" << this->getDllName() ;
			return infoStream.str();
		}

	private:	
		string serviceName_;
		string dllName_;
	};

	typedef boost::shared_ptr<PluginDesc> PluginDescPtr;

}
#endif