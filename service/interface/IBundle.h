/** 
* @file         IBundle.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-2-7
*/

#ifndef SERVICE_IBUNDLE_H 
#define SERVICE_IBUNDLE_H

#include "IBundleContext.h"
#include "BundleConfiguration.h"

namespace service{

	class IBundle
	{
	public:
		IBundle(){};

		virtual ~IBundle() {};

		virtual void start( IBundleContext* context ) = 0;
	         
		virtual void stop( IBundleContext* context ) = 0;

	protected:
		virtual BundleConfigPtr bundConfiguration() = 0;
	};

}

#endif