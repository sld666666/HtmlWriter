/** 
* @file         HtmlPreviewBundle.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-3
*/
#ifndef DIRECTORYVIEWBUNDLE_H
#define DIRECTORYVIEWBUNDLE_H

#include "interface/IBundle.h"
#include "htmlpreviewviewpart_global.h"
#include "HtmlPreviewViewPart.h"


using service::IBundle;
using service::BundleContext;
using service::BundleConfigPtr;
using service::BundleConfig;

class HTMLPREVIEWVIEWPART_EXPORT HtmlPreviewBundle : public IBundle
{
public:
	HtmlPreviewBundle();
	~HtmlPreviewBundle();

public:
	virtual void start( BundleContext* context )const;

	virtual void stop( BundleContext* context )const;

	virtual BundleConfigPtr getBundlelConfig()const;

private:
	HtmlPreviewViewPart*		htmlPreviewViewPart_;
	
};

#endif // DIRECTORYVIEWBUNDLE_H
