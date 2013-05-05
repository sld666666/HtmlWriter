/** 
* @file         MarkdownEditorViewBundle.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-3
*/
#ifndef MARKDOWNEDITORVIEWBUNDLE_H
#define MARKDOWNEDITORVIEWBUNDLE_H

#include "interface/IBundle.h"
#include "markdowneditorviewpart_global.h"
#include "MarkdownEditorViewPart.h"

using service::IBundle;
using service::BundleContext;
using service::BundleConfigPtr;
using service::BundleConfig;

class MARKDOWNEDITORVIEWPART_EXPORT MarkdownEditorViewBundle : public IBundle
{
public:
	MarkdownEditorViewBundle();
	~MarkdownEditorViewBundle();

public:
	virtual void start( BundleContext* context )const;

	virtual void stop( BundleContext* context )const;

	virtual BundleConfigPtr getBundlelConfig()const;


private:
	MarkdownEditorViewPart*		markdownEditorViewPart_;
	
};

#endif // MarkdownEditorViewBundle_H
