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
#include "DirectoryViewPart.h"


using service::IBundle;
using service::BundleContext;
using service::BundleConfigPtr;
using service::BundleConfig;

class DIRECTORYVIEWPART_EXPORT DirectoryViewBundle : public IBundle
{
public:
	DirectoryViewBundle();
	~DirectoryViewBundle();

public:
	virtual void start( BundleContext* context )const;

	virtual void stop( BundleContext* context )const;

	virtual BundleConfigPtr getBundlelConfig()const;

private:
	DirectoryViewPart*		directoryViewPart_;
	
};

#endif // DIRECTORYVIEWBUNDLE_H
