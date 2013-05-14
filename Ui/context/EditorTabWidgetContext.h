/** 
* @file         EditorTabWidgetContext.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-5-14
*/
#ifndef UIUTILS_EDITORTABWIDGETCONTEXT_H
#define UIUTILS_EDITORTABWIDGETCONTEXT_H

#include "IContext.h"

namespace UiUtils{

	class UI_EXPORT EditorTabWidgetContext :public IContext
	{
		
	public:
		EditorTabWidgetContext(QWidget* contextWidget)
			:IContext()
			, contextWidget_(contextWidget){

		}
	
		~EditorTabWidgetContext(){}
		
		QWidget*	getContextWidget(){return contextWidget_;}

	private:
		QWidget*	contextWidget_;
	};

	typedef	shared_ptr<EditorTabWidgetContext> EditorTabWidgetContextPtr;

}


#endif // UI_UiUtils_H
