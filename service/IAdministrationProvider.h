/** 
* @file         IAdministrationProvider.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-2-7
*/
#ifndef SERVICE_IADMINISTRATIONPROVIDE_H
#define SERVICE_IADMINISTRATIONPROVIDE_H

#include "service.h"
#include "BundleConfiguration.h"

namespace service{

	class IAdministrationProvider
	{
		public:
			virtual vector<string> getBundleNames() = 0;	

			virtual string dumpBundleInfo( const string& bundleName ) = 0;

			virtual string dumpAllBundleNames() = 0;

			virtual void stopBundle( const string& bundleName ) = 0;

			virtual void start( vector<BundleConfiguration>& config ) = 0;

			virtual void stop() = 0;
	};
}

#endif