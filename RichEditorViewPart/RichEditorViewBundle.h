/** 
* @file         RichEditorViewBundle.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-3
*/
#ifndef RICHEDITORVIEWBUNDLE_H
#define RICHEDITORVIEWBUNDLE_H

#include "interface/IBundle.h"
#include "richeditorviewpart_global.h"
#include "RichEditorViewPart.h"

using service::IBundle;
using service::BundleContext;
using service::BundleConfigPtr;
using service::BundleConfig;

class RICHEDITORVIEWPART_EXPORT RichEditorViewBundle : public IBundle
{
public:
	RichEditorViewBundle();
	~RichEditorViewBundle();

public:
	virtual void start( BundleContext* context )const;

	virtual void stop( BundleContext* context )const;

	virtual BundleConfigPtr getBundlelConfig()const;


private:
	RichEditorViewPart*		richEditorViewPart_;
	
};

#endif // RICHEDITORVIEWBUNDLE_H
