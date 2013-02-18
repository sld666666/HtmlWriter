/** 
* @file         IBundleActivator.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-2-7
*/

#ifndef SERVICE_IBUNDLEACTIVATOR_H 
#define SERVICE_IBUNDLEACTIVATOR_H
#include "IBundleContext.h"


namespace service{
class IBundleActivator
{
    public:
         virtual ~IBundleActivator() {};
         
         virtual void start( IBundleContext* context ) = 0;
         
         virtual void stop( IBundleContext* context ) = 0;
}

}

#endif