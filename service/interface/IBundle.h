/** 
* @file         IBundle.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-2-7
*/

#ifndef SERVICE_IBUNDLE_H 
#define SERVICE_IBUNDLE_H

#include "BundleContext.h"
#include "BundleConfig.h"

namespace service{

	class IBundle
	{
	public:
		IBundle(){};

		virtual ~IBundle() {};

		virtual void start( BundleContext* context ) const = 0;

		virtual void stop( BundleContext* context ) const = 0;

		virtual BundleConfigPtr getBundlelConfig() const = 0;
	};

}

#endif