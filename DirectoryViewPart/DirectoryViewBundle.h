/** 
* @file         DirectoryViewBundle.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-3
*/
#ifndef DIRECTORYVIEWBUNDLE_H
#define DIRECTORYVIEWBUNDLE_H

#include "interface/IBundle.h"
#include "directoryviewpart_global.h"

using service::IBundle;
using service::IBundleContext;
using service::BundleConfigPtr;
using service::BundleConfiguration;

class DIRECTORYVIEWPART_EXPORT DirectoryViewBundle : public IBundle
{
public:
	DirectoryViewBundle();
	~DirectoryViewBundle();

public:
	virtual void start( IBundleContext* context );

	virtual void stop( IBundleContext* context );

protected:
	virtual BundleConfigPtr bundConfiguration();

private:
	
};

#endif // DIRECTORYVIEWBUNDLE_H
